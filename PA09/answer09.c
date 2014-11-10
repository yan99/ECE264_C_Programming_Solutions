#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "answer09.h"

BusinessNode * create_node(char * stars, char * name, char * address)
{
  BusinessNode * bn;
  bn = malloc(sizeof(BusinessNode));
  bn -> stars = stars;
  bn -> name = name;
  bn -> address = address;
  bn -> left = NULL;
  bn -> right = NULL;
  return bn;
}

BusinessNode * tree_insert(BusinessNode * node, BusinessNode * root)
{
  if(root == NULL)
    {
      return node;
    }
  if(strcmp((node -> name), (root -> name)) <= 0)
    {
      (root -> left) = tree_insert(node, root -> left);
    }
  else if(strcmp((node -> name), (root -> name)) > 0)
    {
      (root -> right) = tree_insert(node, root -> right);
    }
  return root;
}

char * * explode(const char * str, const char * delims)
{
  int N = 0;
  int ind = 0;
  int last = 0; 
  char * * strArr = malloc(4 * sizeof(char *));
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

BusinessNode * load_tree_from_file(char * filename)
{
  FILE * fp = fopen(filename, "r");
  char str[500];
  char * * lineArr = NULL;
  BusinessNode * root = NULL;
  BusinessNode * node = NULL;
  if (fp == NULL)
    {
      return NULL;
    }
  while(fgets(str, 500, fp) != NULL)
    {
      lineArr = explode(str,"\t");
      node = create_node(lineArr[0], lineArr[1], lineArr[2]);
      root = tree_insert(node, root);
      //free(lineArr[0]);
      //free(lineArr[1]);
      //free(lineArr[2]);
      free(lineArr);
    }
  fclose(fp);
  return root;
}

BusinessNode * tree_search_name(char * name, BusinessNode * root)
{
  if(root == NULL)
    {
      return NULL;
    }
  if(strcmp(name, (root -> name)) == 0)
    {
      return root;
    }
  if(strcmp(name, (root -> name)) < 0)
    {
      return tree_search_name(name, (root -> left));
    }
  if(strcmp(name, (root -> name)) > 0)
    {
      return tree_search_name(name, (root -> right));
    }
  return tree_search_name(name, (root -> right));
}

void print_node(BusinessNode * node)
{
  printf("\n\n%s\n", node -> name);
  printf("============\n");
  printf("Stars:\n");
  printf("   %s\n", node -> stars);
  printf("Address:\n");
  printf("   %s\n\n", node -> address);
}

void print_tree(BusinessNode * tree)
{
  if(tree == NULL)
    {
      return;
    }
  print_tree(tree -> left);
  print_node(tree);
  print_tree(tree -> right);
}

void destroy_tree(BusinessNode * root)
{
  if(root == NULL)
    {
      return;
    }
  free(root -> stars);
  free(root -> name);
  free(root -> address);
  destroy_tree(root -> left);
  destroy_tree(root -> right);
  free(root);
}
/*
int main(int argc, char * * argv)
{
  BusinessNode * root = create_node("5.0", "random name", "random address");
   root->left = create_node("3.5", "another name", "another address");
   root->right = create_node("4.0", "yet another name", "some address");
   root->left->right = create_node("1.5", "name 3", "address 3");
   print_tree(root);
   return 0;
}
*/
