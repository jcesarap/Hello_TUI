/*
Programa: Caça Letras
Nome: Júlio César de Amoraes Pinheiro
ASCII Characters: "┌", "┐", "┘", "└", "─", "│", "╔", "╗", "╝", "╚", "═", "║",
"█", "█", "█", "█", "█", "█"
*/

#include "src/bibtela.h"
int top = 0, left = 0, bottom, right, pin_key;

// --- Dependencies
void boot(void);
void draw_box(int ratio, int top, int left);
void navegation(void);
// Components
void manual_draw_box(void);
void manual_borders(void);
// Screens
void start_screen(void);
void letter_hunt(void);
// Buttons
typedef struct { // Structs are like a methods/classes
    char label[20]; // Text of the buttom, 20 characters max
    int line, col; // Position of the button
} Button;

// --- Functions

int main(void) {
  boot();
  start_screen();
  navegation();
  end_screen();
  return 0;
}

void letter_hunt() {
  manual_draw_box();
  manual_borders();
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

void manual_borders() {
  write_to(10, 10, "┌");
  write_to(10, 50, "┐");
  write_to(15, 10, "└");
  write_to(15, 50, "┘");
}

// write_to(12, 13, "Login: _______");
// write_to(13, 13, "Senha: ———————");

void manual_draw_box() {
  draw_line(HORIZONTAL, 10, 11, 49, "─");
  draw_line(HORIZONTAL, 15, 11, 49, "─");
  draw_line(VERTICAL, 50, 11, 14, "│");
  draw_line(VERTICAL, 10, 11, 14, "│");
}

// void draw_window(int x1, int y1, int x2, int y2, int border);
// draw_window(10, 10, 20, 20, 1);
// draw_window(8, 8, 22, 22, 2);
// draw_window(0, 0, 24, 79, 3);

// draw_window: Upper left line, upper left column, bottom right line, bottom
// right column, border type
void start_screen() {
  // Menu-grid: Rows first (2), columns after (3); Each {} bears a row
  // Every Screen should declare a matrix and its variables, and meanings in such screen (values)
  const char *first = "Caça-palavras", *second = "Sair", *third, *fourth;
  // const char * matrix[2][2] = {{first, second}, {third, fourth}};
  // Draw
  manual_draw_box();
  manual_borders();
  // Menu
  write_to(10, 15, first);
  write_to(15, 15, second);
  //write_to(15, 20, second);
  //write_to(20, 20, second);
Button menu[2][2] = {
    {{"Caça-palavras", 10, 15}, {"Opção 2", 10, 40}},
    {{"Opção 3", 15, 15}, {"Sair", 15, 40}}
};

int current_row = 0, current_col = 0; // Current selection

}

void navegation() { // Read `Sketch.md`
  // Arrows and hjkl iterate cursor through matrix
  scanf("%d", &pin_key);
  cursor_to(bottom, right);
}

void boot() {
  // Prepared
  setlocale(LC_ALL, "");
  setlocale(LC_CTYPE, "");
  // Start Screen
  init_screen(25, 80);
  while (TRUE) {
    clear_screen();
    break;
  }
}
