// Function Implementations
#include "bibtela.h"

// Global Variables
WINDOW *my_screen; // Global Screen

/**
 * Create and define main screen dimensions
 * @param[in] x qty. of lines.
 * @param[in] y qty. of columns.
 */
void init_screen(int x, int y) {
  initscr();
  my_screen = newwin(x, y, 0, 0);
  wrefresh(my_screen);
}

// End screen created by init_screen function
void end_screen(void) { endwin(); }

// Clears screen
void clear_screen(void) { wclear(my_screen); }

/**
 * Move the cursor to coordinate defined by x line and y column.
 *
 * @param[in] x coordinate line.
 * @param[in] y coordenate column.
 *
 */
void cursor_to(int x, int y) {
  wmove(my_screen, x, y);
  wrefresh(my_screen);
}

/**
 * Print a string from x line and y column.
 *
 * @param[in] x line of init point to show the string.
 * @param[in] y column of init point to show the string.
 * @param[in] str string to print.
 * @return Returns lenght of string printed.
 *
 */
int write_to(int x, int y, const char *str) {
  cursor_to(x, y);
  wprintw(my_screen, "%s", str);
  wrefresh(my_screen);
  return strlen(str);
}

// Writing lines

void draw_line(LineDirection direction, int anchor, int start, int end, const char *symbol) {
  for (int offset = start; offset <= end; offset++) {
    int x = (direction == HORIZONTAL) ? anchor : offset;
    int y = (direction == HORIZONTAL) ? offset : anchor;
    write_to(x, y, symbol);
  }
}

/**
 * End screen created by ini_screen function.
 *
 * @param[in] x1 coordinate line of uppper left coordinate.
 * @param[in] y1 coordenate column of uppper left coordinate.
 * @param[in] x2 coordinate line of down right coordinate.
 * @param[in] y2 coordenate column of down right coordinate.
 * @param[in] border type of window. 1-Single, 2-Double, 3-Bold.
 *
 */

void draw_window(int x1, int y1, int x2, int y2, int border) {
  char *border_chars[18] = {"┌", "┐", "┘", "└", "─", "│", "╔", "╗", "╝", "╚", "═", "║", "█", "█", "█", "█", "█", "█"};
  int border_offset = 0;

  // Select the correct border character set based on the border type
  border_offset = (border - 1) * 6;
  // Draw the top-left corner
  cursor_to(x1, y1); // Move to the x1-y1 position
  wprintw(my_screen, "%s", border_chars[border_offset]);
  // Draw the x1-right corner
  cursor_to(x1, y2); // Move to the x1-x2 position
  wprintw(my_screen, "%s", border_chars[border_offset + 1]);
  // Draw the bottom-y1 corner
  cursor_to(x2, y1); // Move to the y2-y1 position
  wprintw(my_screen, "%s", border_chars[border_offset + 3]);
  // Draw the y2-x2 corner
  cursor_to(x2, y2); // Move to the y2-x2 position
  wprintw(my_screen, "%s", border_chars[border_offset + 2]);

  draw_line(HORIZONTAL, x1, y1 + 1, y2 - 1, border_chars[border_offset + 4]); // Top horizontal line
  draw_line(HORIZONTAL, x2, y1 + 1, y2 - 1, border_chars[border_offset + 4]); // Bottom horizontal line
  draw_line(VERTICAL, y1, x1 + 1, x2 - 1, border_chars[border_offset + 5]);   // Left vertical line
  draw_line(VERTICAL, y2, x1 + 1, x2 - 1, border_chars[border_offset + 5]);   // Right vertical line
  wrefresh(my_screen);
}
