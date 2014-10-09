#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "answer05.h"
void printPartition(int * arr, int length)//code from book
{
  int ind;
  if(length != 1)
    {
      printf("= %d + ", arr[0]);
      for(ind = 1; ind < length-1; ind++)
	{
	  printf("%d + ",arr[ind]);
	}
      printf("%d\n",arr[length-1]);
    }
  else
    {
      printf("= %d\n", arr[0]);
    }
}
void partition(int * arr, int ind, int left)//this code from book
{
  int val;
  if(left == 0)
    {
      printPartition(arr, ind);
      return;
    }
  for(val = 1;val <= left; val++)
    {
      arr[ind]=val;
      partition(arr, ind + 1, left-val) ;
    }
}
void partitionAll(int n)//code from book
{
  int * arr = malloc(sizeof(int) * n);
  partition(arr, 0, n);
  free(arr);
}
void partitionIn(int * arr, int ind, int left)//part of code from book
{
  int val;
  int i;
  if(left == 0)
    {
      for(i = 0; i < ind-1; i++)
	{
	  if(arr[i] >= arr[i + 1])
	    {
	      return;
	    }
	}
      printPartition(arr, ind);
      return;
    }
  for(val = 1;val <= left; val++)
    {
      arr[ind]=val;
      partitionIn(arr, ind + 1, left-val) ;
    }
}
void partitionIncreasing(int n)//code from book
{
  int * arr = malloc(sizeof(int) * n);
  partitionIn(arr, 0, n);
  free(arr);
}
void partitionDe(int * arr, int ind, int left)//part of code from book
{
  int val;
  int i;
  if(left == 0)
    {
      for(i = 0; i < ind-1; i++)
	{
	  if(arr[i] <= arr[i + 1])
	    {
	      return;
	    }
	}
      printPartition(arr, ind);
      return;
    }
  for(val = 1;val <= left; val++)
    {
      arr[ind]=val;
      partitionDe(arr, ind + 1, left-val) ;
    }
}
void partitionDecreasing(int n)//code from book
{
  int * arr = malloc(sizeof(int) * n);
  partitionDe(arr, 0, n);
  free(arr);
}
void partitionO(int * arr, int ind, int left)//part of this code from book
{
  int val;
  int i;
  if(left == 0)
    {
      for(i = 0; i < ind; i++)
	{
	  if(arr[i] % 2 == 0)
	    {
	      return;
	    }
	}
      printPartition(arr, ind);
      return;
    }
  for(val = 1;val <= left; val++)
    {
      arr[ind]=val;
      partitionO(arr, ind + 1, left-val) ;
    }
}
void partitionOdd(int n)//code from book
{
  int * arr = malloc(sizeof(int) * n);
  partitionO(arr, 0, n);
  free(arr);
}
void partitionE(int * arr, int ind, int left)//part of this code from book
{
  int val;
  int i;
  if(left == 0)
    {
      for(i = 0; i < ind; i++)
	{
	  if(arr[i] % 2 != 0)
	    {
	      return;
	    }
	}
      printPartition(arr, ind);
      return;
    }
  for(val = 1;val <= left; val++)
    {
      arr[ind]=val;
      partitionE(arr, ind + 1, left-val) ;
    }
}
void partitionEven(int n)//code from book
{
  int * arr = malloc(sizeof(int) * n);
  partitionE(arr, 0, n);
  free(arr);
}
void partitionONE(int * arr, int ind, int left)//part of this code from book
{
  int val;
  int i;
  if(left == 0)
    {
      for(i = 0; i < ind - 1; i++)
	{
	  if(arr[i] % 2 == arr[i + 1] % 2)
	    {
	      return;
	    }
	}
      printPartition(arr, ind);
      return;
    }
  for(val = 1;val <= left; val++)
    {
      arr[ind]=val;
      partitionONE(arr, ind + 1, left-val) ;
    }
}
void partitionOddAndEven(int n)//code from book
{
  int * arr = malloc(sizeof(int) * n);
  partitionONE(arr, 0, n);
  free(arr);
}
void partitionP(int * arr, int ind, int left)//part of this code from book
{
  int val;
  int i;
  int j;
  if(left == 0)
    {
      for(i = 0; i < ind; i++)
	{
	  for(j = 2; j < arr[i]; j++)
	    {
	      if(arr[i] % j == 0 && arr[i] != 2)
		{
		  return;
		}
	    }
	  if(arr[i] == 1)
	    {
	      return;
	    }
	}
      printPartition(arr, ind);
      return;
    }
  for(val = 1;val <= left; val++)
    {
      arr[ind]=val;
      partitionP(arr, ind + 1, left-val) ;
    }
}
void partitionPrime(int n)//code from book
{
  int * arr = malloc(sizeof(int) * n);
  partitionP(arr, 0, n);
  free(arr);
}
/* int main(int argc, char * * argv)//code from book */
/* { */
/*   if(argc < 2) */
/*   { */
/*     printf("need one positive integer.\n"); */
/*     return EXIT_FAILURE; */
/*   } */
/*   int n = (int)strtol(argv[1], NULL, 10); */
/*   if(n < 0) */
/*   { */
/*     printf("need one positive integer.\n"); */
/*     return EXIT_FAILURE; */
/*   } */
/*   partitionAll(n); */
/*   partitionIncreasing(n); */
/*   partitionDecreasing(n); */
/*   partitionOdd(n); */
/*   partitionEven(n); */
/*   partitionOddAndEven(n); */
/*   partitionPrime(n); */
/*   return EXIT_SUCCESS; */
/* } */
