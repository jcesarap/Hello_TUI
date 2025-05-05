/**
 * Programa base para uma biblioteca de interface texto com caracteres ASCII estendidos e
 * terminal baseado na biblioteca ncurses.
 * 
 * Ref:
 * https://stackoverflow.com/questions/74615279/problem-with-printing-extended-ascii-using-ncurses
 * 
 */

 /*
    Subconjunto de caracteres gráficos da Tabela ASCII
    {"■","┌","┐","┘","└","─","│","╔","╗","╝","╚","═","║","█","█","█","█","█","█"}
 */

 #include "bibtela.h"

 /**
  * Main program.
  * 
  * @return Return code to operating system.
  */
 int main(void)
 {
     char key, ch; // para ler tecla
     char palavra[70];
     int num;
 
     // configura dos caracteres do idioma configurado no sistema
     setlocale(LC_ALL, "");
     setlocale(LC_CTYPE, "");
 
     init_screen(25, 80);
     while (TRUE) {
         clear_screen();
        
         xywindow(0, 0, 24, 79, 2);

         xyprint(1, 3, "Digite uma palavra!");
         xyscanfstr(2, 3, "%s", palavra);
         xyprint(10,10,palavra);

         xyprint(4, 3, "Digite uma letra!");
         ch = xygetch(5, 3);
         xyprintch(11, 10, ch);

         xyprint(7, 3, "Digite um número inteiro!");
         xyscanfint(8, 3, "%d", &num);
         xyprintint(12, 10, num);
         
         xygoto(24,79);
         scanf("%c", &key);
 
         break;
     }
     end_screen();
 
     return 0;
 }
 
 
