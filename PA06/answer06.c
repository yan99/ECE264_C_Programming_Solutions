#include "answer06.h"
#include <stdio.h>
/* #define SPACE ' ' */
/* #define WALL 'X' */
/* #define TRACK '.' */
#define STEPS 1
void print_path(int deltaX, int deltaY, int step)
{
  if(deltaX == 1)
    {
      printf("E %d\n", step);
    }
  if(deltaX == -1)
    {
      printf("W %d\n", step);
    }
  if(deltaY == 1)
    {
      printf("S %d\n", step);
    }
  if(deltaY == -1)
    {
      printf("N %d\n", step);
    }
}
int countspace(char * * maze, int w, int h)
{
  int i;
  int j;
  int count = 0;
  for(i = 0; i < h; i++)
    {
      for(j = 0; j < w; j++)
	{
	  if(maze[i][j] == SPACE)
	    {
	      count++;
	    }
	}
    }
  if(count)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}
void recurr(char * * maze, int w, int h, int x, int y, int deltax, int deltay)
{
  x += deltax;
  y += deltay;
  if(countspace(maze, w, h))
    {
      maze[y][x] = TRACK;

      print_path(deltax, deltay,STEPS);
      int east =((x + 1) < w) && (maze[y][x + 1] == ' ');
      int west = ((x - 1) >= 0) && (maze[y][x - 1] == ' ');
      int north = ((y - 1) >= 0 )&&(maze[y - 1][x] == ' ');
      int south =((y + 1) < h )&& (maze[y + 1][x] == ' ');

    
      if (east == 0 &&  west == 0 &&  north == 0 && south == 0 )
      {
        maze[y][x] = WALL;  
      

        int east_track = ((x + 1) < (w - 1) ) &&(maze[y][x + 1] == TRACK) ;
        int west_track = ((x - 1) > 0)&& (maze[y][x - 1] == TRACK);
        int north_track = ((y - 1) >  0) && (maze[y - 1][x] == TRACK );
        int south_track = ((y + 1) < (h - 1) )&& (maze[y + 1][x] == TRACK );
	  if(east_track)
	    {
	      recurr(maze, w, h, x, y, 1, 0);
	    }
	  if(west_track)
	    {
	      recurr(maze, w, h, x, y, -1, 0);
	    }
	  if(north_track)
	    {
	      recurr(maze, w, h, x, y, 0, -1);
	    }
	  if(south_track)
	    {
	      recurr(maze, w, h, x, y, 0, 1);
	    }
	}
      else if(east + west + north + south >= 1)
	{
	  if(east)
	    {
	      recurr(maze, w, h, x, y, 1, 0);
	    }
	  if(west)
	    {
	      recurr(maze, w, h, x, y, -1, 0);
	    }
	  if(north)
	    {
	      recurr(maze, w, h, x, y, 0, -1);
	    }
	  if(south)
	    {
	      recurr(maze, w, h, x, y, 0, 1);
	    }
	}
    }
  else
    {
      return;
    }
}
  //  print_path(-deltaX, -deltaY, step_count);
void print_directions(char * * maze, int w, int h)
{
  int start = 0;
  while(maze[0][start] == WALL)
    {
      start++;
    }
  maze[0][start] = TRACK;
  recurr(maze, w, h, start, 0, 0, 1);
}
