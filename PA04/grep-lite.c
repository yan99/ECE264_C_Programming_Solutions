#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char * * argv)
{
  int i;
  for(i = 1; i < argc; i++)
    {
      if(strcmp(argv[i], "--help") == 0)
	{
	  printf("Usage: grep-lite [OPTION]... PATTERN\n"
		 "Search for PATTERN in standard input. PATTERN is a\n"
		 "string. grep-lite will search standard input line by\n"
		 "line, and (by default) print out those lines which\n"
		 "contain pattern as a substring.\n"
		 "\n"
		 "  -v, --invert-match     print non-matching lines\n"
		 "  -n, --line-number      print line numbers with output\n"
		 "  -q, --quiet            suppress all output\n"
		 "\n"
		 "Exit status is 0 if any line is selected, 1 otherwise;\n"
		 "if any error occurs, then the exit status is 2.\n");
	  return EXIT_SUCCESS;
	}
    }
  for(i = 1; i < argc-1; i++)
    {
      if((strcmp(argv[i], "-v")) != 0 && (strcmp(argv[i], "--invert-match")) != 0 && (strcmp(argv[i], "-n")) != 0 && (strcmp(argv[i], "--line-number")) != 0 && (strcmp(argv[i], "-q")) != 0 && (strcmp(argv[i], "--quiet")) != 0)
	{
	  fprintf(stderr, "Error with Arguments.\n");
	  return 2;
	}
    }
  if(argv[argc-1][0] == '-')
    {
      fprintf(stderr, "Error with PATTERN.\n");
      return 2;
    }
  int v = 0;
  int n = 0;
  int q = 0;
  int str_num = 0;
  int count = 0;
  char str[2000];
  for(i = 1; i < argc-1; i++)
    {
      if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--invert-match") ==0)
	{
	  v++;
	}
      if(strcmp(argv[i], "-n") == 0 || strcmp(argv[i], "--line-number") ==0)
	{
	  n++;
	}
      if(strcmp(argv[i], "-q") == 0 || strcmp(argv[i], "--quiet") == 0)
	{
	  q++;
	}
    }
  while(fgets(str, 2000, stdin) != NULL)
    {
      str_num++;
      if(strstr(str, argv[argc-1]) != NULL)
	{
	  count++;
	  if(q == 0 && v == 0)
	    {
	      if(n != 0)
		{
		  printf("%d:", str_num);
		}
	      printf("%s", str);
	    }
	}
      else
	{
	  if(q == 0 && v != 0)
	    {
	      if(n != 0)
		{
		  printf("%d:", str_num);
		}
	      printf("%s", str);
	    }
	}
    }
  if(count == 0)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}
