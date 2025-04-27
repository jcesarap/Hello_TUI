/*
Programa: Caça Letras
Nome: Júlio César de Amoraes Pinheiro
ASCII Characters: "┌", "┐", "┘", "└", "─", "│", "╔", "╗", "╝", "╚", "═", "║",
"█", "█", "█", "█", "█", "█"
*/

// Libraries
#include "src/bibtela.h"
#include <string.h>
/*
  Pre-processor directives: Associate "variables" and integers (in this
  case) to use interchangeably - and have them (names) as return from
  functions (that return integers).
*/
#define INVALID -1
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4
#define ENTER 5
//
#define START 20
#define OPTION_2 21
#define OPTION_3 22
#define LEAVE 23
//
// Structs
typedef struct {   // Structs are like a methods/classes - and this is its declaration
  char label[20];  // Text of the buttom, 20 characters max
  int row, column; // Position of the button
} button;
// --- Dependencies
void boot(void);
void draw_box(int ratio, int top, int left);
void navigation(void);
void flow(void);
// Components
void manual_draw_box(void);
void manual_borders(void);
int get_key(void);
int menu_test(void);
int draw_menu(button object[2][2]); // Matrices on functions require specifying their size and declaring the variabel itself - not just the type
int redraw_menu(void);
// Screens
void start_screen(void);
void letter_hunt_screen(void);
// buttons
// Declaration of a "struct instance", an "object" "menu" of the "button" data type.
// Global Variables
button start_menu[2][2];                                                                                               // Declare here so it's global
int top = 0, left = 0, bottom, right, pin_key, current_row = 0, current_column = 0, button_row = 0, button_column = 0; // For selecting matrix position
char current_label[40];

// --- Functions

int main(void) {
  printf("\e[?25l"); // hide cursor
  boot();
  start_screen();
  navigation();
  end_screen();
  printf("\e[?25l"); // hide cursor
  return 0;
}

void letter_hunt_screen() {
  manual_draw_box();
  manual_borders();
}

// right column, border type
void start_screen() {
  // Draw
  manual_draw_box();
  manual_borders();
  // Buttons
  // Define "object" ("struct instance") properties
  // Set text to a label (which requires strcpy function)
  strcpy(start_menu[0][0].label, "Caça-palavras");
  start_menu[0][0].row = 10;
  start_menu[0][0].column = 15;

  // As well as its positions
  strcpy(start_menu[0][1].label, "Option 2");
  start_menu[0][1].row = 10;
  start_menu[0][1].column = 40;

  // Mnemonics: matrix coordinates.property = assigned_value
  strcpy(start_menu[1][0].label, "Option 3");
  start_menu[1][0].row = 15;
  start_menu[1][0].column = 15;

  strcpy(start_menu[1][1].label, "Leave");
  start_menu[1][1].row = 15;
  start_menu[1][1].column = 40;

  draw_menu(start_menu);
}

void option_2_screen() {
  // Draw
  manual_draw_box();
  manual_borders();
  write_to(10, 15, "Welcome to option 2");
}

void option_3_screen() {
  // Draw
  manual_draw_box();
  manual_borders();
  write_to(10, 15, "Welcome to option 3");
}

void leave() { return; }

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

int draw_menu(button menu[][2]) { // Remember... button is the datatype, after it is the variable to be placeheld into logical operations
  clear_screen();
  // Iterate through columns and rows
  for (int row = 0; row < 2; row++) {
    for (int column = 0; column < 2; column++) {
      strcpy(current_label, menu[row][column].label);
      button_row = menu[row][column].row;
      button_column = menu[row][column].column;
      if (row == current_row && column == current_column) {
        // Highlight selected button
        write_to(button_row, button_column, "> ");
        write_to(button_row, button_column + 2, current_label);
      } else {
        // Normal button
        write_to(button_row, button_column, "  ");
        write_to(button_row, button_column + 2, current_label);
      }
    }
  }
  return 0;
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

void navigation() {
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
      if (current_column > 0) {
        current_column--;
      }
      break;
    case RIGHT:
      if (current_column < 1) {
        current_column++;
      }
      break;
    case ENTER:
      // execute_action();
      flow();
    }
    draw_menu(start_menu);
  }
}

// "Asynchronously" called by navigation()
void flow(void) {                                                       // Reminder: strcmp returns 0 or 1, which needs be compared to such, in order for the control flow to work
  strcpy(current_label, start_menu[current_row][current_column].label); // update for current before analysing
  clear_screen();
  if (strcmp(current_label, "Caça-palavras") == 0) { // Caça-palavras
    letter_hunt_screen();
  } else if (strcmp(current_label, "Option 2") == 0) { // Option 2
    option_2_screen();
  } else if (strcmp(current_label, "Option 3") == 0) { // Option 3
    option_3_screen();
  } else if (strcmp(current_label, "Leave") == 0) { // Leave
    return;
  }
}

// "Asynchronously" called by navigation()
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
