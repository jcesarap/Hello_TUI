#include "bibtela.h"

/*
   Program itself using the library - for simplified TUIs with ASCII
   {"■","┌","┐","┘","└","─","│","╔","╗","╝","╚","═","║","█","█","█","█","█","█"}
*/

int pin_key, start_line = 0, start_column = 0, end_line = 24, end_column = 60;
int startscreen();

int main(void) {
  // Prepared
  setlocale(LC_ALL, "");
  setlocale(LC_CTYPE, "");
  // Start Screen
  init_screen(31, 81);
  while (TRUE) {
    clear_screen();
    startscreen();
    break;
  }
  end_screen();

  return 0;
}

void start_screen() {
  // Horizontal: Select Line; Init line, End line, Character
  xyhline(start_line, start_line, end_column, "─");
  xyhline(end_line, start_line, end_column, "─");
  // Vertical: Select column; Init line; End column, Character
  // Padding
  xyvline(start_column, start_line, end_line, "│");
  xyvline(end_column, start_line, end_line, "│");

  // Welcome
  xyprint(12, 20, "Welcome");

  xygoto(end_line, end_column);
  scanf("%d", &pin_key);
}
