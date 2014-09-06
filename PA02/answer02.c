#include <stdio.h>
#include "answer02.h"

char main()
{
  const char * s = "Hello World";
//  printf("%d\n", my_strlen(s));
  char h ='H';
  printf("%d\n", my_countchar(s, h));
}

size_t my_strlen(const char * str)
{
  int len = 0;
  while(str[len] != '\0')
  {
    len++;
  }
  return len;
}

int my_countchar(const char * str, char ch)
{
  int i;
  int len = my_strlen(str);
  int count = 0;
  for(i=0; i<len; i++)
  {
    if(str[i] == ch)
    {
      count++;
    }
  }
  return count;
}

char * my_strchr(const char * str, int ch);
{
    
}

