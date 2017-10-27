#include <stdio.h>
struct Font {
  unsigned font_id: 8;
  unsigned font_size: 7;
  unsigned alignment: 2;
  unsigned bold: 1;
  unsigned italic: 1;
  unsigned underline: 1;
};
const char *kStars = "****************************************";
enum {
  kFontIdMask = 255,
  kFontSizeMask = 127,
  kLeft = 0,
  kCenter = 1,
  kRight = 2,
  kOff = 0,
  kOn = 1
};
const char *kAlignments[3] = {"left", "center", "right"};
const char *kToggles[2] = {"off", "on"};

char ShowMenu(void);
void ShowFontValue(struct Font);
void ModifyFontId(struct Font *);
void ModifyFontSize(struct Font *);
void ModifyAlignment(struct Font *);
void ModifyBold(struct Font *);
void ModifyItalic(struct Font *);
void ModifyUnderline(struct Font *);
void IgnoreChar(void);

int main(void) {
  struct Font font = {1, 12, kLeft, kOff, kOff, kOff};
  ShowFontValue(font);
  char action;
  while ((action = ShowMenu()) != 'q') {
    switch (action) {
      case 'f':
        ModifyFontId(&font);
        break;
      case 's':
        ModifyFontSize(&font);
        break;
      case 'a':
        ModifyAlignment(&font);
        break;
      case 'b':
        ModifyBold(&font);
        break;
      case 'i':
        ModifyItalic(&font);
        break;
      case 'u':
        ModifyUnderline(&font);
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

void ShowFontValue(struct Font font) {
  puts("ID  SIZE  ALIGNMENT  B    I    U");
  printf("%u   %u     %s      %s  %s  %s\n",
      font.font_id,
      font.font_size,
      kAlignments[font.alignment],
      kToggles[font.bold],
      kToggles[font.italic],
      kToggles[font.underline]);
}

void ModifyFontId(struct Font *font) {
  unsigned font_id;
  printf("Enter font id (0-255): ");
  while (scanf("%u", &font_id) != 1) {
    puts("Please Enter integer.");
  }
  IgnoreChar();
  font->font_id = kFontIdMask & font_id;
}

void ModifyFontSize(struct Font *font) {
  unsigned font_size;
  printf("Enter font size (0-127): ");
  while (scanf("%u", &font_size) != 1) {
    puts("Please enter integer.");
  }
  IgnoreChar();
  font->font_size = kFontSizeMask & font_size;
}

void ModifyAlignment(struct Font *font) {
  char alignment_code;
  puts("Select alignment_code:");
  printf("l) %s  c) %s  r) %s\n", kAlignments[0], kAlignments[1], kAlignments[2]);
  while (scanf("%c", &alignment_code) !=1 ||
      (alignment_code != 'l' &&
       alignment_code != 'c' &&
       alignment_code != 'r')) {
    puts("Please enter character l, c or r.");
  }
  IgnoreChar();

  switch (alignment_code) {
    case 'l':
      font->alignment = kLeft;
      break;
    case 'c':
      font->alignment = kCenter;
      break;
    case 'r':
      font->alignment = kRight;
      break;
  }
}

void ModifyBold(struct Font *font) {
  int bold_code;
  puts("Toggle bold: ");
  puts("1) OFF  2) On");
  while (scanf("%d", &bold_code) != 1 || bold_code < 1 || bold_code > 2) {
    puts("Please enter integer 1 or 2.");
  }
  IgnoreChar();
  font->bold = bold_code == 1 ? kOff :kOn;
}

void ModifyItalic(struct Font *font) {
  int italic_code;
  puts("Toggle italic: ");
  puts("1) OFF  2) On");
  while (scanf("%d", &italic_code) != 1 || italic_code < 1 || italic_code > 2) {
    puts("Please enter integer 1 or 2.");
  }
  IgnoreChar();
  font->italic = italic_code == 1 ? kOff :kOn;
}

void ModifyUnderline(struct Font *font) {
  int underline_code;
  puts("Toggle underline: ");
  puts("1) OFF  2) On");
  while (scanf("%d", &underline_code) != 1 || underline_code < 1 || underline_code > 2) {
    puts("Please enter integer 1 or 2.");
  }
  IgnoreChar();
  font->underline = underline_code == 1 ? kOff :kOn;
}

void IgnoreChar(void) {
  while (getchar() != '\n')
    continue;
}
