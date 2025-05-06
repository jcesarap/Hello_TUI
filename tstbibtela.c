/*
Programa: Caça-Letras (e funcões abstratas para adições futuras)
Nome: Júlio César de Amoraes Pinheiro
ASCII Characters: "┌", "┐", "┘", "└", "─", "│", "╔", "╗", "╝", "╚", "═", "║",
"█", "█", "█", "█", "█", "█"
[PT-BR, IFCE]
*/
#include "bibtela.h"

char palavra[70];
char rasura[70] = "*";
char target[70] = "";
char key;
int coordenada_1, coordenada_2;

void warning_screen();
void invalid_screen();
void query_characters();
void target_word();
void prompt_screen();
void word_screen();
void word_hunt();
void boot();

int main(void) {
  boot();
  while (TRUE) {
    word_hunt();
    break;
  }
  end_screen();
  return 0;
}

void boot() { // Botei até isso em função kkkk, sou compulsivo
  setlocale(LC_ALL, "");
  setlocale(LC_CTYPE, "");
  init_screen(25, 80);
}
void word_hunt() {
  clear_screen();
  prompt_screen();
  target_word();
  query_characters();
  xyprint(coordenada_1 + 2, coordenada_2 + 2, "🥳 Parabéns - Você achou todas as letras!");
  scanf(" %c", &key);
}
void word_screen() {
  clear_screen();
  xyprint(coordenada_1, coordenada_2, rasura);
  xyprint(coordenada_1 + 1, coordenada_2, "[ Aperte qualquer LETRA para continuar ]");
  scanf(" %c", &key);
}
void prompt_screen() {
  xywindow(1, 1, 5, 30, 2);
  xyprint(2, 3, "📖 Escolha uma palavra ");
  xyscanfstr(3, 3, "%s", palavra);
  // copia para target para manter a original
  strcpy(target, palavra);
  xywindow(6, 1, 10, 30, 2); // start line, start column, end line, end column
  xyprint(7, 3, "📍 Escolha a coordenada 1 ");
  xyscanfint(8, 3, "%d", &coordenada_1);
  // xyprintint(9, 3, coordenada_1);
  xywindow(11, 1, 15, 30, 2); // start line, start column, end line, end column
  xyprint(12, 3, "📍 Escolha a coordenada 2 ");
  xyscanfint(13, 3, "%d", &coordenada_2);
  // xyprintint(12, 3, coordenada_2);
  if (coordenada_1 > 79 || coordenada_1 < 0 || coordenada_2 > 24 || coordenada_2 < 0) {
    invalid_screen();
  }
}
void target_word() {
  int len = strlen(target);
  for (int i = 0; i < len; i++) {
    rasura[i] = '*';
  }
  rasura[len] = '\0';
}
void query_characters() { // I know I could move variables through parameters, to not make them global, but I've spent too much time on this already playing around the other (git) branch
  while (1) {
    clear_screen();
    char ch;
    xywindow(6, 1, 10, 31, 2); // start line, start column, end line, end column
    xyprint(7, 3, "Escolha um caractere ");
    ch = xygetch(8, 3);
    int len = strlen(target);
    int found = 0;
    for (int i = 0; i < len; i++) {
      if (target[i] == ch) {
        rasura[i] = ch;
        found = 1;
      }
    }
    if (!found) {
      warning_screen();
    }
    word_screen();
    if (strcmp(rasura, target) == 0) {
      break;
    }
  }
}
void warning_screen() {
  clear_screen();
  xywindow(6, 1, 10, 70, 2); // start line, start column, end line, end column
  xyprint(7, 3, "❌ Caractere não encontrado (aperte qualquer letra para continuar)");
  scanf(" %c", &key);
}
void invalid_screen() {
  clear_screen();
  xywindow(6, 1, 10, 70, 2); // start line, start column, end line, end column
  xyprint(7, 3, "❌ Coordenadas inválidas... \n Escolha entre 0-24 para coordenada 1, e 0-79 para coordenada 2.");
  scanf(" %c", &key);
  exit(0);
}
