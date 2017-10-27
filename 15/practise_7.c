#include <stdio.h>
const char *kStars = "****************************************";
enum {
  kFontIdMask = 0xff,
  kFontSizeMask = 0x7f00,
  kAlignmentMask = 0x18000,
  kBoldMask = 0x20000,
  kItalicMask = 0x40000,
  kUnderlineMask = 0x80000,

  kLeft = 0x0,
  kCenter = 0x8000,
  kRight = 0x10000,
};
const char *kAlignments[3] = {"left", "center", "right"};
const char *kToggles[2] = {"off", "on"};

char ShowMenu(void);
void ShowFontValue(unsigned);
unsigned ModifyFontId(unsigned);
unsigned ModifyFontSize(unsigned);
unsigned ModifyAlignment(unsigned);
unsigned ModifyBold(unsigned);
unsigned ModifyItalic(unsigned);
unsigned ModifyUnderline(unsigned);
void IgnoreChar(void);

int main(void) {
  unsigned font = 0;
  ShowFontValue(font);
  char action;
  while ((action = ShowMenu()) != 'q') {
    switch (action) {
      case 'f':
       font =  ModifyFontId(font);
        break;
      case 's':
        font = ModifyFontSize(font);
        break;
      case 'a':
        font = ModifyAlignment(font);
        break;
      case 'b':
        font = ModifyBold(font);
        break;
      case 'i':
        font = ModifyItalic(font);
        break;
      case 'u':
        font = ModifyUnderline(font);
        break;
      default:
        puts("Please Enter the correct action.");
        continue;
    }
    ShowFontValue(font);
  }
  puts("Thank you for use.");
  return 0;
}

char ShowMenu(void) {
  char action;
  printf("\n%s%s\n", kStars, kStars);
  puts("f) Change font    s) Change size    a) Change aligment");
  puts("b) Toggle bold    i) Toggle italic  u) Toggle underline");
  puts("q) Quit");
  printf("%s%s\n", kStars, kStars);
  while (scanf("%c", &action) != 1) {
    puts("Please Enter the correct action.");
  }
  IgnoreChar();
  return action;
}

void ShowFontValue(unsigned font) {
  puts("ID  SIZE  ALIGNMENT  B    I    U");
  printf("%u   %u     %s      %s  %s  %s\n",
      font & kFontIdMask,
      (font & kFontSizeMask) >> 8,
      kAlignments[(font & kAlignmentMask) >> 15],
      kToggles[(font & kBoldMask) >> 17],
      kToggles[(font & kItalicMask) >> 18],
      kToggles[(font & kUnderlineMask) >> 19]);
}
unsigned ModifyFontId(unsigned font) {
  unsigned font_id;
  printf("Enter font id (0-255): ");
  while (scanf("%u", &font_id) != 1) {
    puts("Please Enter integer.");
  }
  IgnoreChar();
  font &= ~kFontIdMask;
  return font | font_id;
}

unsigned ModifyFontSize(unsigned font) {
  unsigned font_size;
  printf("Enter font size (0-127): ");
  while (scanf("%u", &font_size) != 1) {
    puts("Please enter integer.");
  }
  IgnoreChar();
  font &= ~kFontSizeMask;
  return font | (font_size << 8);
}

unsigned ModifyAlignment(unsigned font) {
  char code;
  puts("Select code:");
  printf("l) %s  c) %s  r) %s\n", kAlignments[0], kAlignments[1], kAlignments[2]);
  while (scanf("%c", &code) !=1 ||
      (code != 'l' &&
       code != 'c' &&
       code != 'r')) {
    puts("Please enter character l, c or r.");
  }
  IgnoreChar();
  font &= ~kAlignmentMask;

  switch (code) {
    case 'l':
      font |= kLeft;
      break;
    case 'c':
      font |= kCenter;
      break;
    case 'r':
      font |= kRight;
      break;
  }

  return font;
}

unsigned ModifyBold(unsigned font) {
  int code;
  puts("Toggle bold: ");
  puts("1) OFF  2) On");
  while (scanf("%d", &code) != 1 || code < 1 || code > 2) {
    puts("Please enter integer 1 or 2.");
  }

  IgnoreChar();
  font &= ~kBoldMask;
  if (code ==2 ) 
    font |= kBoldMask;

  return font;
}

unsigned ModifyItalic(unsigned font) {
  int code;
  puts("Toggle italic: ");
  puts("1) OFF  2) On");
  while (scanf("%d", &code) != 1 || code < 1 || code > 2) {
    puts("Please enter integer 1 or 2.");
  }

  IgnoreChar();
  font &= ~kItalicMask;
  if (code ==2 ) 
    font |= kItalicMask;

  return font;
}

unsigned ModifyUnderline(unsigned font) {
  int code;
  puts("Toggle underline: ");
  puts("1) OFF  2) On");
  while (scanf("%d", &code) != 1 || code < 1 || code > 2) {
    puts("Please enter integer 1 or 2.");
  }

  IgnoreChar();
  font &= ~kUnderlineMask;
  if (code ==2 ) 
    font |= kUnderlineMask;

  return font;
}

void IgnoreChar(void) {
  while (getchar() != '\n')
    continue;
}
