#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

typedef struct LinkedNode {
  int data;
  struct LinkedNode *next;
} LinkedNode;

typedef struct LinkedList {
  LinkedNode *head;
  LinkedNode *tail;
  int size;
} LinkedList;

LinkedNode *createNode(int data);
LinkedNode *find(LinkedList *list, int data);

LinkedList *createList();

void destroyList(LinkedList *list);
void clear(LinkedList *list);
void prepend(LinkedList *list, int data);
void append(LinkedList *list, int data);
void removeFirst(LinkedList *list);
void removeLast(LinkedList *list);
void removeData(LinkedList *list, int data);
void printList(LinkedList *list);
bool isEmpty(LinkedList *list);
int size(LinkedList *list);

#endif