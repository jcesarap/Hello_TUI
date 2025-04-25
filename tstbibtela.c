#include "src/bibtela.h"

/*
   Program itself using the library - for simplified TUIs with ASCII
   {"■","┌","┐","┘","└","─","│","╔","╗","╝","╚","═","║","█","█","█","█","█","█"}
*/

void start_screen(void);
void draw_box(int ratio, int top, int left);
int top = 0, left = 0, bottom, right, pin_key;

int main(void) {
  // Prepared
  setlocale(LC_ALL, "");
  setlocale(LC_CTYPE, "");
  // Start Screen
  init_screen(30, 80);
  while (TRUE) {
    clear_screen();
    start_screen();
    break;
  }
  end_screen();

  return 0;
}

// Made obsolete by draw_window
void draw_box(int ratio, int top, int left) {
  // Change top and left for changing padding
  bottom = ratio / 4;
  right = ratio;
  // Borders
  draw_line(HORIZONTAL, top, left, right, "─");
  draw_line(HORIZONTAL, bottom, left, right, "─");
  draw_line(VERTICAL, left, top, bottom, "│");
  draw_line(VERTICAL, right, top, bottom, "│");
}
// draw_box(79, 0, 0);
// Last two arguments define padding

void manual_borders(){
    write_to(10, 10, "┌");
    write_to(10, 50, "┐");
    write_to(15, 10, "└");
    write_to(15, 50, "┘");
}

void manual_messages() {
  // Welcome
  // write_to(12, 20, "Welcome");
  write_to(12, 13, "Login: _______");
  write_to(13, 13, "Senha: ———————");
}

void manual_draw_box() {
    draw_line(HORIZONTAL, 10, 11, 49, "─");
    draw_line(HORIZONTAL, 15, 11, 49,  "─");
    draw_line(VERTICAL, 50, 11, 14, "│");
    draw_line(VERTICAL, 10, 11, 14, "│");
}

// void draw_window(int x1, int y1, int x2, int y2, int border);
//draw_window(10, 10, 20, 20, 1);
//draw_window(8, 8, 22, 22, 2);
//draw_window(0, 0, 24, 79, 3);

// draw_window: Upper left line, upper left column, bottom right line, bottom right column, border type
void start_screen() {
  manual_draw_box();
  manual_borders();
  manual_messages();
  // End
  cursor_to(bottom, right);
  scanf("%d", &pin_key);
}
