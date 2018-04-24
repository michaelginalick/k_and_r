#include <stdio.h>
#define MAXLINELENGTH 40
#define TABLENGTH 4


int
main(void) {
  int c, blanks, newcnt, linecnt;

  linecnt = 0;
  while((c = getchar()) != EOF) {
    if (c == '\n') {
      if (linecnt > 0) {
        putchar('\n');
        if (linecnt > MAXLINELENGTH)
          printf("%d\n", linecnt);
      }
      linecnt = 0;
    } else {
      if (c == '\t') {
        newcnt = TABLENGTH * (linecnt/TABLENGTH + 1);
        if (linecnt < MAXLINELENGTH) {
          if (newcnt > MAXLINELENGTH)
            blanks = MAXLINELENGTH - linecnt;
          else
            blanks = newcnt - linecnt;
            while (blanks > 0) {
              putchar(' ');
              --blanks;
            }
        }
      } else {
        newcnt = linecnt + 1;
        if (linecnt < MAXLINELENGTH)
          putchar(c);
      }
      linecnt = newcnt;
    }
  }
}
