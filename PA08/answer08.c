#include <stdlib.h>
#include <stdio.h>
#include <libgen.h>
#include <string.h>
#include "answer08.h"

List * List_createNode(const char * str)
{
  List * new_list = malloc(sizeof(List));
  if(new_list == NULL)
  {
    return NULL;
  }
  new_list -> str = strdup(str);
  new_list -> next = NULL;
  return new_list;
}

void List_destroy(List * list)
{
  if(list != NULL)
  {
    free(list -> str);
    List_destroy(list -> next);
  }
  free(list);
}

int List_length(List * list)
{
  int len = 0;
  if (list == NULL)
  {
    return 0;
  }
  while (list != NULL)
  {
    len++;
    list = list -> next;
  }
  return len;
}

void move_nextPtr(List ** resultNext, List ** small)
{
  List * temp = * small;
  * small = temp -> next;
  temp -> next = * resultNext;
  * resultNext = temp;
}

List * List_merge(List * lhs, List * rhs, int (*compar)(const char *, const char*))
{
  List * result = NULL;
  List ** ptr = &result;
  while(1)
    {
      if(lhs == NULL)
	{
	  * ptr = rhs;
	  break;
	}
      else if(rhs == NULL)
	{
	  * ptr = lhs;
	  break;
	}
      else
	{
	  if(compar(lhs -> str, rhs -> str) <= 0)
	    {
	      move_nextPtr(ptr, &lhs);
	    }
	  else
	    {
	      move_nextPtr(ptr, &rhs);
	    }
	  ptr = &((*ptr) -> next);
	}
    }
  return result;
}

List * List_sort(List * list, int(*compar)(const char *, const char *))
{
  int length = List_length(list);
  if (length == 1 || length == 0)
  {
    return list;
  }
  int i;
  List * lhs = list;
  for (i = 1; i < (length / 2); i++)
  {
    list = list -> next;
  }
  List * rhs = list -> next;
  list -> next = NULL;
  lhs = List_sort(lhs, compar);
  rhs = List_sort(rhs, compar);
  list = List_merge(lhs, rhs, compar);
  return list;
}

