#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer03.h"

int main (int argc,char **argv)
{
   int i;
   int number = 0;
   int* num = &number;

   char** arr;
   char* string;

   char *glue = NULL;
   char *s = NULL;
   const char * s1 = "what is your name!";

   glue = strdup(", ");
   s = strdup("good monrning !");
   arr =  explode(s1," ",num);
   for(i=0;i<number;i++)
     {
       printf("%s\n",arr[i]);
     }
   string = implode(arr,number,glue);
   printf("\n%s\n",string);

   free(s);
   free(glue);
   
   for(i=0;i<(*num);i++)
     {
       free(arr[i]);
     }
   free(arr);
   free(string);
   return 0;
}
