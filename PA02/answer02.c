#include <stdio.h>
#include "answer02.h"

char main()
{
  const char * s = "Hello World";
//  printf("%d\n", my_strlen(s));
  char h ='\0';
  printf("%d\n", my_countchar(s, h));
  printf("'%s'\n", my_strchr(s, h));
  printf("'%s'\n", my_strrchr(s, h));
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
  for(i=0; i<=len; i++)
  {
    if(str[i] == ch)
    {
      count++;
    }
  }
  return count;
}

char * my_strchr(const char * str, int ch)
{
  char * s;
  int i = 0;
  int len = 0;
  int count = my_countchar(str, ch);
  if(count != 0)
  {
    while(str[len] != ch)
    {
      len++;
    }
    while(str[len] != '\0')
    {
      s[i] = str[len];
      i++;
      len++;
    }
  }
  else
  {
    s = "NULL";
  }
  return s;
}

char * my_strrchr(const char * str, int ch)
{
  char * s;
  int i = 0;
  int len = my_strlen(str);
  int count = my_countchar(str, ch);
  if(count != 0)
  {
    while(str[len] != ch)
    {
      len--;
    }
    while(str[len] != '\0')
    {
      s[i] = str[len];
      i++;
      len++;
    }
  }
  else
  {
    s = "NULL";
  }
  return s;
}
/*
char * my_strstr(const char * haystack, const char * needle)
{
}
*/
