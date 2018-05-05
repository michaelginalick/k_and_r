#include <stdio.h>

void checkcomment(int c);
void incomment();
void insinglecomment();
void echo_quote(int c);

int
main(void) 
{
  int c;

  while((c = getchar()) != EOF) {
    checkcomment(c);
  }

}


void checkcomment(int c)
{
  int d, p;
  if(c == '/')
  {
    d = getchar();

    if (d == '*')
      incomment();
    else if (d == '/' && c == '/')
      insinglecomment();
    else if( d == '/' )
      checkcomment(p);
  }
  else
    putchar(c);
}

void incomment()
{
  int c,d;   
  c = getchar();
  d = getchar();

  while(c !='*' || d !='/')
  {
    c = d;
    d = getchar();
  }

}

void insinglecomment()
{
  int c;
  while (c != '\n') {
    c = getchar();
  }
}
