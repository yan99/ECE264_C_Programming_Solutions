#include <stdlib.h>
#include "answer01.h"

int arraySum(int * array, int len)
{
  int sum=0;
  int i;

  for(i=0; i<len; i++)
  {
    sum+=array[i];
  }
  return sum;
}

int arrayCountNegative(int * array, int len)
{
  int count=0;
  int i;

  for(i=0; i<len; i++)
  {
    if(array[i]<0)
    {
      count++;
    }
  }
  return count;
}

int arrayIsIncreasing(int * array, int len)
{
  int i;

  if(len<=1)
  {
    return 1;
  }
  else
  {
    for(i=0; i<len-1; i++)
    {
      if(array[i]>array[i+1])
      {
        return 0;
      }
    }
    return 1;
  }
}

int arrayIndexRFind(int needle, const int * haystack, int len)
{
  int i;
  for(i=len-1; i>=0; i--)
  {
    if(haystack[i]==needle)
    {
      return i;  
    }
  }
  return -1;
}

int arrayFindSmallest(int * array, int len)
{
  int i=0;
  int j;

  if(len==0)
  {
    return 0;
  }
  else
  {
    for(j=1; j<=len-1; j++)
    {
      if(array[i]>array[j])
      {
        i=j;
      }
    }
    return i;
  }
}
