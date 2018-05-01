#include <stdio.h>
#define MAXLINE 45
#define TABNO   8
#define YES     1
#define NO      0

int c, i;
int wordsave;
int prtcnt, wordcnt, blankcnt;
char word[MAXLINE];

void linebrk(void);
void blnkchar(void);
void prtblank(void);
void prtword(void);
void nonblank(void);

int
main()
{
  wordsave = NO;
  prtcnt = wordcnt = blankcnt = 0;
  while ((c = getchar()) != EOF)
    if (c == '\n')
      linebrk();
    else if(c == ' ' || c == '\t')
      blnkchar();
    else
      nonblank();

  linebrk();

  return 0;
}

void linebrk(void)
{
  if (wordsave == YES && blankcnt > 0)
    prtblank();
  prtword();
  if (prtcnt > 0)
      putchar('\n');
  wordsave = NO;
  prtcnt = wordcnt = blankcnt = 0;
}

void blnkchar(void)
{
  int newcnt;

  if (wordsave == YES && blankcnt > 0)
    prtblank();
  prtword();
  wordcnt = 0;
  newcnt = prtcnt + blankcnt + 1;
  if (newcnt >= MAXLINE) {
    if (prtcnt > 0) {
      putchar('\n');
      prtcnt = 0;
    }
    blankcnt = newcnt - MAXLINE;
  }
  else
    blankcnt = newcnt - prtcnt;
}

void prtblank(void)
{
  int tabs, newcnt;

  newcnt = prtcnt + blankcnt;
  tabs = (newcnt / TABNO) - (prtcnt / TABNO);
  if (tabs > 0) {
    blankcnt = newcnt - TABNO * (newcnt / TABNO);
    while (tabs > 0) {
      putchar('\t');
      --tabs;
    }
  }
  while (blankcnt > 0) {
    putchar(' ');
    --blankcnt;
  }
  prtcnt = newcnt;
}

void prtword(void)
{
  if ((prtcnt + wordcnt) > MAXLINE) {
    if (prtcnt > 0) {
      putchar('\n');
      prtcnt = 0;
    }
  }
  for (i = 0; i < wordcnt; ++i)
     putchar(word[i]);
  prtcnt = prtcnt + wordcnt;
  if (prtcnt >= MAXLINE) {
    putchar('\n');
    prtcnt = 0;
  }
  wordsave = NO;
}

void nonblank(void)
{
  if (wordcnt < MAXLINE) {
    wordsave = YES;
    word[wordcnt] = c;
    ++wordcnt;
  }
  else {
    if (wordsave == YES && blankcnt > 0)
      prtblank();
    prtword();
    if (prtcnt >= MAXLINE) {
        putchar('\n');
        prtcnt = 0;
    }
    putchar(c);
    ++prtcnt;
  }
}
