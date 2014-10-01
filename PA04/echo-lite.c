#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * * argv)
{
  int i;
  if(argc > 1)
    {
      for(i = 1; i < argc; i++)
	{
	  printf("%s ", argv[i]);
	}
      printf("\n");
    }
  else
    {
      printf("\n");
    }
  return EXIT_SUCCESS;
}
