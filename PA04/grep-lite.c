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
	     "Exit status is 0 if any line is selected, 1 otherwise;\n"
	     "if any error occurs, then the exit status is 2.\n"
	     "</help-message>\n");
    }
  }
  return EXIT_SUCCESS;
}
