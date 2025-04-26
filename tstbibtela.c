/*
Programa: Caça Letras
Nome: Júlio César de Amoraes Pinheiro
ASCII Characters: "┌", "┐", "┘", "└", "─", "│", "╔", "╗", "╝", "╚", "═", "║",
"█", "█", "█", "█", "█", "█"
*/

// Libraries
#include "src/bibtela.h"
/*
  Pre-processor directives: Associate "variables" and integers (in this
  case) to use interchangeably - and have them (names) as return from
  functions (that return integers).
*/
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define ENTER 5
#define INVALID -1
// Global Variables
int top = 0, left = 0, bottom, right, pin_key, current_row = 0,
    current_col = 0; // For selecting matrix position
// --- Dependencies
void boot(void);
void draw_box(int ratio, int top, int left);
void navegation(void);
// Components
void manual_draw_box(void);
void manual_borders(void);
int get_key(void);
int menu_test(void);
int redraw_menu(void);
// Screens
void start_screen(void);
void letter_hunt(void);
// buttons
typedef struct {  // Structs are like a methods/classes - and this is its declaration
  char label[20]; // Text of the buttom, 20 characters max
  int line, col;  // Position of the button
} button;
// Declaration of a "struct instance", an "object" "menu" of the "button" data type.
button start_menu[2][2]; // Declare here so it's global

// --- Functions

int main(void) {
  boot();
  // start_screen();
  // navegation();
  menu_test();
  end_screen();
  return 0;
}

void letter_hunt() {
  manual_draw_box();
  manual_borders();
}

// Made obsolete by draw_window
// E.g., draw_box(79, 0, 0);
// Last two arguments define padding
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

void manual_borders() {
  write_to(10, 10, "┌");
  write_to(10, 50, "┐");
  write_to(15, 10, "└");
  write_to(15, 50, "┘");
}

void manual_draw_box() {
  draw_line(HORIZONTAL, 10, 11, 49, "─");
  draw_line(HORIZONTAL, 15, 11, 49, "─");
  draw_line(VERTICAL, 50, 11, 14, "│");
  draw_line(VERTICAL, 10, 11, 14, "│");
}

// right column, border type
void start_screen() {
  // Draw
  manual_draw_box();
  manual_borders();
  // Buttons
  int current_row = 0, current_col = 0; // Current selection
  // Define "object" ("struct instance") properties
  // Set text to a label (which requires strcpy function)
  strcpy(start_menu[0][0].label, "Caça-palavras");
  start_menu[0][0].line = 10;
  start_menu[0][0].col = 15;

  // As well as its positions
  strcpy(start_menu[0][1].label, "Opção 2");
  start_menu[0][1].line = 10;
  start_menu[0][1].col = 40;

  // Mnemonics: matrix coordinates.property = assigned_value
  strcpy(start_menu[1][0].label, "Opção 3");
  start_menu[1][0].line = 15;
  start_menu[1][0].col = 15;

  strcpy(start_menu[1][1].label, "Sair");
  start_menu[1][1].line = 15;
  start_menu[1][1].col = 40;
}

void navegation() {
  int key;
  while (1) {
    key = get_key();
    // The break in each condition works as a "do nothing"
    switch (key) {
    case UP:
      if (current_row > 0) {
        current_row--;
      }
      break;
    case DOWN:
      if (current_row < 1) {
        current_row++;
      }
      break;
    case LEFT:
      if (current_col > 0) {
        current_col--;
      }
      break;
    case RIGHT:
      if (current_col < 1) {
        current_col++;
      }
      break;
    case ENTER:
      // execute_action();
      return; // Handle selection
    }
    redraw_menu();
  }
}

int redraw_menu(void) {
  clear_screen();
  // Loop over rows and colums - drawing either >< or nothing around strings,
  // denoting selection
  for (int row = 0; row < 2; row++) {
    for (int column = 0; column < 2; column++) {
      // Highlight selected button
      if (row == current_row && column == current_col) {
        write_to(start_menu[row][column].line, start_menu[row][column].col - 2, "> %s <", start_menu[row][column].label);
      } else {
        write_to(start_menu[row][column].line, start_menu[row][column].col, "  %s  ", start_menu[row][column].label);
      }
    }
  }
}

int menu_test(void) {
  int action;
  printf("Press 'h', 'j', 'k', 'l' to navigate (enter to exit):\n");
  while (1) {
    action = get_key();
    switch (action) {
    case UP:
      printf("Up pressed!\n");
      break;
    case DOWN:
      printf("Down pressed!\n");
      break;
    case LEFT:
      printf("Left pressed!\n");
      break;
    case RIGHT:
      printf("Right pressed!\n");
      break;
    case ENTER:
      printf("Exit");
      return 0;
    default:
      printf("Invalid key!\n");
    }
  }
  return 0;
}

int get_key(void) {
  int keypress = getchar(); // Native function to read a character
  switch (keypress) {
  case 'k':
    return UP;
  case 'j':
    return DOWN;
  case 'h':
    return LEFT;
  case 'l':
    return RIGHT;
  case 'g':
    return ENTER;
  default:
    return INVALID;
  }
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
