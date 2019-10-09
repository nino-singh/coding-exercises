#ifndef __LISTTESTS_H__
#define __LISTTESTS_H__

#include <stdio.h>
#include "include/list.h"

void printStringNode(void * s)
{
  printf("%s ", (char *) s);
}

void run_list_tests()
{
  List *artistList = (List *)malloc(sizeof(List));

  artistList->listLen = 0;
  artistList->elementSize = sizeof(char *);
  artistList->head = NULL;
  artistList->tail = NULL;

  printf("--Append artists to list ---\n");
  char nameJd[] = "Jason Derulo";
  char nameJb[] = "J Balvin";
  char namePf[] = "Paloma Faith";
  char nameCv[] = "Carlos Vives";
  char nameMl[] = "Mashrou Leila";

  list_append(artistList, nameJd);
  list_append(artistList, nameJb);
  list_append(artistList, namePf);
  list_append(artistList, nameCv);
  list_append(artistList, nameMl);
  list_print(artistList, printStringNode);

  char nameMs[] = "Mustafa Sandal";
  char nameDp[] = "DJ Project";

  printf("--Prepend artists to list ---\n");
  list_prepend(artistList, nameMs);
  list_prepend(artistList, nameDp);
  list_print(artistList, printStringNode);

}

#endif
