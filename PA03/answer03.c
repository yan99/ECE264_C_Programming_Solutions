#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer03.h"

char * strcat_ex(char * * dest, int * n, const char * src)
{
  if(* dest == NULL)
  {
    * n = 2 * strlen(src) + 1;
    * dest = malloc((* n) * sizeof(char));
    * dest[0] = '\0';
    strcpy(* dest, src);
    
  }
  else if(* n < (strlen(* dest) + strlen(src) + 1))
  {
    * n = 2 * (strlen(* dest) + strlen(src)) + 1;
    char * buffer = malloc((* n) * sizeof(char));
    strcpy(buffer, * dest);
    free(*dest);
    * dest = buffer;
    strcat(* dest, src);
  }
  else
  {
    strcat(* dest, src);
  }
  return * dest;
}

char * * explode(const char * str, const char * delims, int * arrLen)
{
  int N = 0;
  int ind = 0;
  int last = 0;
  for(ind = 0; ind < strlen(str); ind++)
    { 
      if(strchr(delims, str[ind]) != NULL)
	{
	  N++;
	}
    } 
  * arrLen = N + 1; 
  N = 0;
  char * * strArr = malloc((* arrLen + 1) * sizeof(char *));
  for(ind = 0; ind < strlen(str); ind++)
  {
    if(strchr(delims, str[ind]) != NULL)
    {
      char * mcpy = malloc((ind - last + 1) * sizeof(char));
      memcpy(mcpy, str + last, ind - last);
      mcpy[ind - last] = '\0';
      strArr[N++] = mcpy;
      last = ind + 1;
    }
  }
  char * mcpy = malloc((ind - last + 1) * sizeof(char));
  memcpy(mcpy, str + last, ind - last);
  mcpy[ind - last] = '\0';
  strArr[N++] = mcpy;
  return strArr;
}

char * implode(char * * strArr, int len, const char * glue)
{
  int N = 0;
  int cpy_len = 0;
  char * cpy = NULL;
  for(N = 0; N < len; N++)
  {
    cpy = strcat_ex(&cpy, &cpy_len, strArr[N]);
    cpy = strcat_ex(&cpy, &cpy_len, glue);
  }
  cpy[strlen(cpy) - strlen(glue)] = '\0';
  return cpy;  
}

int compareArr(const void * arr1, const void * arr2)
{
  return strcmp(*(const char * *)arr1, *(const char * *)arr2);
}

void sortStringArray(char * * arrString, int len)
{
  qsort(arrString, len, sizeof(char *), compareArr);
}

int compareCha(const void * arr1, const void * arr2)
{
  const char a1 = *(char *)arr1;
  const char a2 = *(char *)arr2;
  return((int)a1 - (int)a2);
}

void sortStringCharacters(char * str)
{
  qsort(str, strlen(str), sizeof(char), compareCha);
}

void destroyStringArray(char * * strArr, int len)
{
  int i;
  for(i = 0; i < len; i++)
  {
    free(strArr[i]);
  }
  free(strArr);
}