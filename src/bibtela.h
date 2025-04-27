// Wrap library dependencies, define function prototypes
#ifndef _BIBTELA
#define _BIBTELA
// The condition above will make sure that libraries are only included if they weren't already

#include <locale.h>
#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <wchar.h>

typedef enum { HORIZONTAL, VERTICAL } LineDirection;

void init_screen(int x, int y);
void end_screen(void);
void clear_screen(void);
void cursor_to(int x, int y);
int write_to(int x, int y, const char *str);
void draw_window(int x1, int y1, int x2, int y2, int border);
void draw_line(LineDirection direction, int anchor, int start, int end, const char *symbol);

#endif
