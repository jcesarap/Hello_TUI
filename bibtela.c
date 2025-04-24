/*
* Function implementations
*/
#include "bibtela.h"

/*
* Global variables
*/
WINDOW *my_screen;   // main global screen

/**
 * Create and define main screen dimensions
 * 
 * @param[in] x qty. of lines.
 * @param[in] y qty. of columns.
 * 
 */
void init_screen(int x, int y) {
    initscr();
    my_screen = newwin(x, y, 0, 0);
    wrefresh(my_screen);
}


/**
 * End screen created by ini_screen function.
 * 
 */
void end_screen(void) {
    endwin();
}


/**
 * Clear all screen.
 * 
 */
void clear_screen(void) {
    wclear(my_screen);
}


/**
 * Move the cursor to coordinate defined by x line and y column.
 * 
 * @param[in] x coordinate line.
 * @param[in] y coordenate column.
 * 
 */
void xygoto(int x, int y) {
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
int xyprint(int x, int y, const char* str) {
    xygoto(x, y);
    wprintw(my_screen, "%s", str);
    wrefresh(my_screen);
    return strlen(str);
}


/**
 * Show a horizontal line.
 * 
 * @param[in] x1 line of line.
 * @param[in] y1 init column.
 * @param[in] y2 end column.
 * @param[in] ch character to draw the line (string type).
 * 
 */
void xyhline(int x, int y1, int y2, const char *ch) {
    for (int y=y1; y<=y2; y++) 
        xyprint(x, y, ch);
}

/**
 * Show a vertical line.
 * 
 * @param[in] y column of line.
 * @param[in] x1 init line.
 * @param[in] x2 end line.
 * @param[in] ch character to draw the line (string type).
 * 
 */
void xyvline(int y, int x1, int x2, const char *ch) {   
    for (int x=x1; x<=x2; x++) 
        xyprint(x, y, ch);
}
