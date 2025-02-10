#include <stdlib.h>
#include <time.h>

#include "linkedList.h"

int main(int argc, char const *argv[])
{
  int nodes[] = {8, 3, 7, 1, 6, 2, 5, 4};
  LinkedListNode *list = createLinkedList(nodes, sizeof(nodes) / sizeof(nodes[0]));

  srand((unsigned int)time(NULL));
  for (int i = 0; i < 100; i++)
  {
    int randomValue = (rand() % 201) - 100;
    insertLinkedListNode(list, randomValue);
  }

  printLinkedList(list);

  freeLinkedList(&list);

  return 0;
}
