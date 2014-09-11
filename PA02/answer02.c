#include <stdio.h>
#include "answer02.h"
/*
void main()
{
  const char * s = "Hello World";
  printf("%d\n", my_strlen(s));
  char h ='o';
  char buffer[50];
  char ch ='5';
  printf("%d\n", my_countchar(s, h));
  printf("'%s'\n", my_strchr(s, h));
  printf("'%s'\n", my_strrchr(s, h));
  printf("'%s'\n", my_strstr(s, "World"));
  printf("'%s'\n", my_strcpy(buffer, "Hello "));
  printf("'%d'\n", my_isspace(ch));
  printf("%s\n", my_strcat(buffer, "Zippy!"));
  printf("%d\n", my_atoi("0"));
}
*/
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
  int i = 0;
  char * s = NULL;
  int len = my_strlen(str);
  while(i <= len + 1)
  {
    if(str[i] == ch)
    {
      s = (char *)&str[i];
      return s;
    }
    i++;
  }
  return s;
}

char * my_strrchr(const char * str, int ch)
{
  int len = my_strlen(str);
  char * s = NULL;
  while(len >= 0)
  {
    if(str[len] == ch)
    {
      s = (char *)&str[len];
      return s;
    }
    len--;
  }
  return s;
}

char * my_strstr(const char * haystack, const char * needle)
{
  int i = 0;
  int j = 0;
  int k = 0;
  if(needle[0] == '\0')
  {
    return (char *)&haystack[0];
  }
  while(haystack[k] != '\0')
  {
    i = k;
    j = 0;
    while(haystack[i] == needle[j] && haystack[i] != '\0')
    {
      i++;
      j++;
    }
    if(needle[j] == '\0')
    {
      return (char *)&haystack[k];
    }
    k++;
  }
  return NULL;
  
}

char *my_strcpy(char * dest, const char * src)
{
  int i = 0;
  while(src[i] != '\0')
  {
    dest[i] = src[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}

char * my_strcat(char * dest, const char * src)
{
  int len_dest = my_strlen((const char *)dest);
  int i = 0;
  while(src[i] != '\0')
  {
    dest[len_dest + i] = src[i];
    i++;
  }
  dest[i + len_dest] = '\0';
  return dest;
}

int my_isspace(int ch)
{
  return (ch == ' ' || ch == '\f' || ch == '\n' || ch == '\r' || ch == '\t' || ch =='\v' );
}

int my_atoi(const char * str)
{
  int j = 0;
  int ret = 0;
  while(str[0] == ' ' || str[0] == '\n' || str[0] == '\f' || str[0] == '\t' || str[0] == '\v' || str[0] == '\r')
  {
    str++;
  }
  if(str[0] == '-')
  {
    str++;
    j++;
  }
  if(str[ret] <= '9' && str[ret] >= '0')
  {
    while(str[0] >= '0' && str[0] <= '9')
    {
      ret = 10 * ret;
      ret += str[0] - '0';
      str++;
    }
    if(j == 1)
    {
      return -ret;
    }
    else
    {
      return ret;
    }
  }
  else
  {
    return 0;
  }
}
