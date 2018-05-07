#include <stdio.h>
#define OPENBRACE '{'
#define OPENPAREN '('
#define CLOSINGBRACE '}'
#define CLOSINGPAREN ')'
#define DOUBLEQUOTE ' " ' //cant define single or double quotes
#define OPENBRACKET '['   //1_24.c:26:13: warning: multi-character character constant [-Wmultichar]
#define CLOSINGBRAKET ']'

int
main(void)
{
  int SQ, DQ, OB, OP, CP, OBRA, c;
  SQ = DQ = OB = OP = OBRA= 0;

  while((c = getchar()) != EOF)
  {
    if(c == OPENBRACE)
      OB += 1;

    if(c == CLOSINGBRACE)
      OB -=1;
    if ( OB < 0 )
      return printf("brace mismatch \n");
    
    // if(c == DOUBLEQUOTE)
    //   DQ++;
    
    if(c == OPENBRACKET)
      OBRA += 1;
    
    if(c == CLOSINGBRAKET)
      OBRA -= 1;
    
    if(OPENBRACKET < 0)
      return printf("bracket mismatch \n");

    if(c == OPENPAREN)
      OP += 1;

    if(c == CLOSINGPAREN)
      OP -= 1;

    if( OP < 0 )
      return printf("parentheses mismatch 1\n");
    
  }


  //validate all const variables are equal to 0;
  if (c == EOF)
    if(OB != 0)
      return printf("brace mismatch \n");
    if(OP != 0)
      return printf("parentheses mismatch \n");
    if(OBRA != 0)
      return printf("bracket mismatch \n");
    if(DQ%2 != 0)
      return printf("double quote mismatch \n");
  if (OB == 0 && OP == 0 && OBRA == 0 && DQ == 0)
    return printf("balanced \n");

}

