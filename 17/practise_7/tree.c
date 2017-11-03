/* tree.c -- tree support functions */
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* local data type */
typedef struct pair
{
  Node *parent;
  Node *child;
} Pair;

/* protototypes for local functions */
static Node *MakeNode(const Item *pi);
static bool ToLeft(const Item *i1, const Item *i2);
static bool ToRight(const Item *i1, const Item *i2);
static void AddNode(Node *new_node, Node *root);
static void InOrder(const Node *root, void (*pfun)(Node node));
static Pair SeekItem(const Item *pi, const Tree *ptree);
static void DeleteNode(Node **ptr);
static void DeleteAllNodes(Node *ptr);

/* function definitions */
void InitializeTree(Tree *ptree)
{
  ptree->root = NULL;
  ptree->size = 0;
}

bool TreeIsEmpty(const Tree *ptree)
{
  return ptree->root == NULL;
}

bool TreeIsFull(const Tree *ptree)
{
  return ptree->size == MAXITEMS;
}

int TreeItemCount(const Tree *ptree)
{
  return ptree->size;
}

bool AddItem(const Item *pi, Tree *ptree)
{
  Node *new_node;
  Pair look = SeekItem(pi, ptree);

  if (TreeIsFull(ptree))
  {
    fprintf(stderr, "Tree is full\n");
    return false; /* early return           */
  }
  if (look.child != NULL)
  {
    look.child->count++;
    return true; /* early return           */
  }
  new_node = MakeNode(pi); /* points to new node     */
  if (new_node == NULL)
  {
    fprintf(stderr, "Couldn't create node\n");
    return false; /* early return           */
  }
  /* succeeded in creating a new node */
  ptree->size++;

  if (ptree->root == NULL)          /* case 1: tree is empty  */
    ptree->root = new_node;         /* new node is tree root  */
  else                              /* case 2: not empty      */
    AddNode(new_node, ptree->root); /* add node to tree  */

  return true; /* successful return      */
}

bool InTree(const Item *pi, const Tree *ptree)
{
  return (SeekItem(pi, ptree).child == NULL) ? false : true;
}

bool DeleteItem(const Item *pi, Tree *ptree)
{
  Pair look;

  look = SeekItem(pi, ptree);
  if (look.child == NULL)
    return false;

  if (look.parent == NULL) /* delete root item       */
    DeleteNode(&ptree->root);
  else if (look.parent->left == look.child)
    DeleteNode(&look.parent->left);
  else
    DeleteNode(&look.parent->right);
  ptree->size--;

  return true;
}

void Traverse(const Tree *ptree, void (*pfun)(Node node))
{

  if (ptree != NULL)
    InOrder(ptree->root, pfun);
}

void DeleteAll(Tree *ptree)
{
  if (ptree != NULL)
    DeleteAllNodes(ptree->root);
  ptree->root = NULL;
  ptree->size = 0;
}

/* local functions */
static void InOrder(const Node *root, void (*pfun)(Node node))
{
  if (root != NULL)
  {
    InOrder(root->left, pfun);
    (*pfun)(*root);
    InOrder(root->right, pfun);
  }
}

static void DeleteAllNodes(Node *root)
{
  Node *pright;

  if (root != NULL)
  {
    pright = root->right;
    DeleteAllNodes(root->left);
    free(root);
    DeleteAllNodes(pright);
  }
}

static void AddNode(Node *new_node, Node *root)
{
  if (ToLeft(&new_node->item, &root->item))
  {
    if (root->left == NULL)  /* empty subtree       */
      root->left = new_node; /* so add node here    */
    else
      AddNode(new_node, root->left); /* else process subtree*/
  }
  else if (ToRight(&new_node->item, &root->item))
  {
    if (root->right == NULL)
      root->right = new_node;
    else
      AddNode(new_node, root->right);
  }
  else /* should be no duplicates */
  {
    fprintf(stderr, "location error in AddNode()\n");
    exit(1);
  }
}

static bool ToLeft(const Item *i1, const Item *i2)
{
  /* 第一个参数减第二个参数，字母表的十进制表示法 */
  return strcmp((const char *)i1, (const char *)i2) < 0;
}

static bool ToRight(const Item *i1, const Item *i2)
{
  return strcmp((const char *)i1, (const char *)i2) > 0;
}

static Node *MakeNode(const Item *pi)
{
  Node *new_node;

  new_node = (Node *)malloc(sizeof(Node));
  if (new_node != NULL)
  {
    strcpy(new_node->item, *pi);
    new_node->count = 1;
    new_node->left = NULL;
    new_node->right = NULL;
  }

  return new_node;
}

static Pair SeekItem(const Item *pi, const Tree *ptree)
{
  Pair look;
  look.parent = NULL;
  look.child = ptree->root;

  if (look.child == NULL)
    return look; /* early return   */

  while (look.child != NULL)
  {
    if (ToLeft(pi, &(look.child->item))) 
    {
      /* 如果 pi 比 当前节点更左边 */
      /* 那么搜索位置移动到当前节点的左子树 */
      look.parent = look.child;
      look.child = look.child->left;
    }
    else if (ToRight(pi, &(look.child->item)))
    {
      /* 如果 pi 比 当前节点更右边 */
      /* 那么搜索位置移动到当前节点的右子树 */
      look.parent = look.child;
      look.child = look.child->right;
    }
    else     /* must be same if not to left or right    */
      break; /* look.child is address of node with item */
  }

  return look; /* successful return   */
}

static void DeleteNode(Node **ptr)
/* ptr is address of parent member pointing to target node  */
{
  Node *temp;

  puts((*ptr)->item);
  if ((*ptr)->left == NULL)
  {
    temp = *ptr;
    *ptr = (*ptr)->right; /* 替换旧节点的位置 */
    free(temp);
  }
  else if ((*ptr)->right == NULL)
  {
    temp = *ptr;
    *ptr = (*ptr)->left; /* 替换旧节点的位置 */
    free(temp);
  }
  else /* deleted node has two children */
  {
    /* find where to reattach right subtree */
    for (temp = (*ptr)->left; temp->right != NULL; temp = temp->right)
      continue;
    temp->right = (*ptr)->right;
    temp = *ptr;
    *ptr = (*ptr)->left; /* 替换旧节点的位置 */
    free(temp);
  }
}
