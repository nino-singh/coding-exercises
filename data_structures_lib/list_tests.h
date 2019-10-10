#ifndef __LISTTESTS_H__
#define __LISTTESTS_H__

#include "include/common.h"
#include "include/list.h"

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

  printf("--- Get node ----\n");
  char * retrieved1 = (char*) list_get(artistList, 3);
  printf("Got node 3: %s\n", retrieved1);

  char * retrieved2 = (char*) list_get(artistList, 1);
  printf("Got node 1: %s\n", retrieved2);

  printf("--- Insert node at index 3 ----\n");
  char insertArtist[] = "insertedArist";
  list_insert(artistList, insertArtist, 3);
  list_print(artistList, printStringNode);

  printf("---- Remove node 3 from list ---\n");
  list_remove(artistList, 3);
  list_print(artistList, printStringNode);

  printf("---- Remove head from list ---\n");
  list_remove(artistList, 0);
  list_print(artistList, printStringNode);

  printf("---- Remove tail from list ---\n");
  list_remove(artistList, artistList->listLen-1);
  list_print(artistList, printStringNode);

  printf("---- Find Mashrou Leila in list ---\n");
  int index = list_search(artistList, nameMl);
  if( index < 0)
  {
    printf("Mashrou Leila not found.\n");
  }
  else
  {
    printf("Mashrou Leila found at index %d\n", index);
  }

  printf("---- Find Carlos Vives in list ---\n");
  int idx = list_search(artistList, nameCv);
  if( idx < 0)
  {
    printf("Carlos Vives not found.\n");
  }
  else
  {
    printf("Carlos Vives found at index %d\n", idx);
  }
}

#endif
