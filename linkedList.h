#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <stdlib.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct LinkedListNode LinkedListNode;

struct LinkedListNode
{
  int data;
  LinkedListNode *prev;
  LinkedListNode *next;
};

int compare(const void *a, const void *b);
LinkedListNode *createLinkedListNode(int data);
LinkedListNode *createLinkedList(const int nodes[], const unsigned int nodeCount);
void insertLinkedListNode(LinkedListNode *const head, const int data);
void printLinkedList(const LinkedListNode *const head);
void freeLinkedList(LinkedListNode **head);

#endif // LINKEDLIST_H