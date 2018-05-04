#include <stdio.h>
#define MAXLENGTH 100

void checkcomment(int c);
void incomment();

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
      incomment(p);
    else if( d == '/' )
      incomment(p);
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
