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
    cbreak();
    echo();
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
    mvwprintw(my_screen, x, y, "%s", str);
    wrefresh(my_screen);
    return strlen(str);
}

/**
 * Print a char from x line and y column.
 * 
 * @param[in] x line of init point to show the string.
 * @param[in] y column of init point to show the string.
 * @param[in] ch char to print.
 * 
 */
void xyprintch(int x, int y, const char ch) {
    mvwaddch(my_screen, x, y, ch);
    wrefresh(my_screen);
}


/**
 * Print a integer from x line and y column.
 * 
 * @param[in] x line of init point to show the string.
 * @param[in] y column of init point to show the string.
 * @param[in] num integer number to print.
 * 
 */
void xyprintint(int x, int y, const int num) {
    mvwprintw(my_screen, x, y, "%d", num);
    wrefresh(my_screen);
}

/**
 * Input a string like scanf() on a screen coordinate.
 * 
 * @param[in] x line of init point to show the string.
 * @param[in] y column of init point to show the string.
 * @param[in] mask string of mask to print.
 * @param[in] str input string.
 * 
 */
void xyscanfstr(int x, int y, const char* mask, char* str) {
    xygoto(x, y);
    wscanw(my_screen, mask, str);
}


/**
 * Input a integer number like scanf() on a screen coordinate.
 * 
 * @param[in] x line of init point to show the string.
 * @param[in] y column of init point to show the string.
 * @param[in] mask string of mask to print.
 * 
 */
void xyscanfint(int x, int y, const char* mask, int* number) {
    xygoto(x, y);
    wscanw(my_screen, mask, number);
}


/**
 * Input a char like getch() on a screen coordinate.
 * 
 * @param[in] x line of init point to show the string.
 * @param[in] y column of init point to show the string.
 * @param[out] input char.
 * 
 */
char xygetch(int x, int y) {
    char ch[1];
    mvwscanw(my_screen, x, y, "%c", ch);
    return ch[0];
}


/**
 * Show a horizontal line.
 * 
 * @param[in] x line of line.
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
void xywindow(int x1, int y1, int x2, int y2, int border) {
    char *b[18] = {"┌","┐","┘","└","─","│","╔","╗","╝","╚","═","║","█","█","█","█","█","█"};
    int z=0;

    // desloc index to correct type character set
    z = (border - 1) * 6;

    // uppper left corner
    xygoto(x1, y1);
    wprintw(my_screen, "%s", b[z]);

    // uppper right corner
    xygoto(x1, y2);
    wprintw(my_screen, "%s", b[z+1]);

    // down left corner
    xygoto(x2, y1);
    wprintw(my_screen, "%s", b[z+3]);

    // down right corner
    xygoto(x2, y2);
    wprintw(my_screen, "%s", b[z+2]);

    // Horizontal bars
    xyhline(x1, y1+1, y2-1, b[z+4]);
    xyhline(x2, y1+1, y2-1, b[z+4]);

    // Vertical bars
    xyvline(y1, x1+1, x2-1, b[z+5]);
    xyvline(y2, x1+1, x2-1, b[z+5]);

    wrefresh(my_screen);
}
