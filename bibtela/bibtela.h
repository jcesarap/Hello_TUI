// Wrap library dependencies, define function prototypes
#ifndef _BIBTELA
#define _BIBTELA
// The condition above will make sure that libraries are only included if they weren't already

#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>
#include <locale.h>
#include <string.h>
#include <wchar.h>

void init_screen(int x, int y);
void end_screen(void);
void clear_screen(void);
void xygoto(int x, int y);
int xyprint(int x, int y, const char* str);

void xyhline(int x, int y1, int y2, const char *ch);
void xyvline(int y, int x1, int x2, const char *ch);

#endif
