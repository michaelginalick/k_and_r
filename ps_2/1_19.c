#include <stdio.h>
#define MAXLINE 1000
void reverse(char line[]);
int getaline(char s[], int lim);

int
main(void) {
  int len, i;
  char line[MAXLINE];

  while ((len = getaline(line, MAXLINE)) >0) {
    reverse(line);
    printf("%s\n", line);
  }

}


void reverse(char line[]) 
{
  int i, s;
  char temp;
  i = 0;
  while(line[i] != '\0')
    ++i;

  s = i-1;
  for(i = 0; i < s; ++i) {
    temp = line[i];
    line[i] = line[s];
    line[s] = temp;
    --s;
  }

}

int getaline(char s[], int lim)
{
  int c, i;

  for(i = 0; i < lim-1 && (c = getchar()) != EOF && c!= '\n'; ++i)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}

