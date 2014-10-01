#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{
  int i;
  char str[100];
  for(i = 1; i < argc; i++)
  {
      if(strcmp(argv[i], "--help") == 0)
	{
	  printf("Usage: cat-lite [--help] [FILE]...\n"
		 "With no FILE, or when FILE is -, read standard input.\n"
		 "\n"
		 "Examples:\n"
		 "  cat-lite README   Print the file README to standard output.\n"
		 "  cat-lite f - g    Print f's contents, then standard input, \n"
		 "                    then g's contents.\n"
		 "  cat-lite          Copy standard input to standard output.\n"
		 "");
	  return EXIT_SUCCESS;
	}
    }
  if(argc == 1)
    {
      while(fgets(str, 1000, stdin) != NULL)
	{
	  fprintf(stdout, "%s", str);
	}
      return EXIT_SUCCESS;
    }
  for(i = 1; i < argc; i++)
    { 
      if(strcmp(argv[i], "-") == 0)
	{
	  while(fgets(str, 1000, stdin) != NULL)
	    {
	      printf("%s\n", str);
	    }
	}
	else
	{
	  char c;
	  FILE * fp = fopen(argv[i], "r");
	  if(fp == NULL)
	    {
	      fprintf(stderr, "cat cannot open %s\n", argv[i]);
	      return EXIT_FAILURE;
	    }
	  while((c = fgetc(fp)) != EOF)
	    {
	      printf("%c", c);
	    }
	  fclose(fp);
	 }
    }
  return EXIT_SUCCESS;
}
