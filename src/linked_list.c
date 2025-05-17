#include <wchar.h>
#define _CRT_SECURE_NO_WARNINGS

#include "../include/linked_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_BUFFER_SIZE 128

/**
 * @brief creates a new node for a linked list
 *
 * allocates dynamic memory for a new node of type LinkedNode, assigns the
 * supplied data value, and sets the 'next' pointer to NULL
 *
 * @param data the integer value to be stored in the node
 *
 * @return a pointer to the newly created node, or NULL if memory alocation
 * fails
 */
LinkedNode *createNode(int data) {
  LinkedNode *node = malloc(sizeof(LinkedNode));
  if (node == NULL) {
    return NULL;
  }
  node->data = data;
  node->next = NULL;
  return node;
}

/**
 * @brief searches for the first node in the list with the given data
 *
 * iterates through the linked list starting from the head and returns a pointer
 * to the first node that contains the specified data
 *
 * @param list the pointer to the linked list to search
 * @param data the integer value to search for
 *
 * @return a pointer to the matching node if found
 */
LinkedNode *find(const LinkedList *list, int data) {
  if (list == NULL) {
    return NULL;
  }
  for (LinkedNode *current = list->head; current != NULL;
       current = current->next) {
    if (current->data == data) {
      return current;
    }
  }
  return NULL;
}

/**
 * @brief creates a new empty linked list
 *
 * allocates memory for a new LinkedList structure and initializes its members
 *
 * @return a pointer to the newly created list, or NULL if memory allocation
 * fails
 */
LinkedList *createList() {
  LinkedList *list = malloc(sizeof(LinkedList));
  if (list == NULL) {
    return NULL;
  }
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  return list;
}

/**
 * @brief destroys the list and frees all associated memory
 *
 * clears the list and frees the memory allocated for the list structure
 *
 * @param list a pointer to the linked list to destroy
 */
void destroyList(LinkedList *list) {
  if (list == NULL) {
    return;
  }
  clear(list);
  free(list);
}

/**
 * @brief clears all elements from the list without deallocating the list
 * structure itself
 *
 * removes all nodes from the list and frees their memory
 *
 * @param list a pointer to the linked list to clear
 */
void clear(LinkedList *list) {
  if (list == NULL) {
    return;
  }
  while (!isEmpty(list)) {
    removeFirst(list);
  }
}

/**
 * @brief adds a new node containing the given data at the beginning of the
 * list
 *
 * allocates memory for a new node and inserts it at the head of the list
 *
 * @param list a pointer to the linked list
 * @param data the integer data to insert
 */
void prepend(LinkedList *list, int data) {
  if (list == NULL) {
    return;
  }
  LinkedNode *node = malloc(sizeof(LinkedNode));
  if (node == NULL) {
    return;
  }
  node->data = data;
  node->next = list->head;
  list->head = node;
  if (list->tail == NULL) {
    list->tail = node;
  }
  list->size++;
}

/**
 * @brief adds a new node containing the given data at the end of the list
 *
 * allocates memory for a new node and appends it to the tail of the list
 *
 * @param list a pointer to the linked list
 * @param data the integer data to insert
 */
void append(LinkedList *list, int data) {
  if (list == NULL) {
    return;
  }
  LinkedNode *node = malloc(sizeof(LinkedNode));
  if (node == NULL) {
    return;
  }
  node->data = data;
  node->next = NULL;
  if (isEmpty(list)) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
  list->size++;
}

/**
 * @brief removes the first node from the list and frees its memory
 *
 * updates the head pointer and list size, if the list becomes empty, also
 * updates the tail
 *
 * @param list a pointer to the linked list
 */
void removeFirst(LinkedList *list) {
  if (list == NULL) {
    return;
  }
  if (isEmpty(list)) {
    return;
  }
  LinkedNode *temp = list->head;
  list->head = list->head->next;
  if (list->head == NULL) {
    list->tail = NULL;
  }
  free(temp);
  list->size--;
}

/**
 * @brief removes the last node from the list and frees its memory
 *
 * if the list is empty, the function does nothing
 *
 * @param list a pointer to the linked list
 */
void removeLast(LinkedList *list) {
  if (list == NULL) {
    return;
  }
  if (isEmpty(list)) {
    return;
  }
  if (list->head == list->tail) {
    free(list->head);
    list->head = NULL;
    list->tail = NULL;
  } else {
    LinkedNode *current = list->head;
    while (current->next != list->tail) {
      current = current->next;
    }
    free(list->tail);
    current->next = NULL;
    list->tail = current;
  }
  list->size--;
}

/**
 * @brief removes the first occurrence of the specified data from the list
 *
 * searches the list for a node with matching data and removes it
 *
 * @param list a pointer to the linked list
 * @param data the integer value to remove
 */
void removeData(LinkedList *list, int data) {
  if (list == NULL) {
    return;
  }
  if (isEmpty(list)) {
    return;
  }
  if (list->head->data == data) {
    removeFirst(list);
    return;
  }
  LinkedNode *current = list->head;
  while (current->next != NULL && current->next->data != data) {
    current = current->next;
  }
  if (current->next == NULL) {
    return;
  }
  LinkedNode *temp = current->next;
  current->next = temp->next;
  if (temp == list->tail) {
    list->tail = current;
  }
  free(temp);
  list->size--;
}

/**
 * @brief prints the contents of the linked list
 *
 * outputs each element in the list in order using the function listToString,
 * formatted as: LinkedList: [data] -> ...
 *
 * @param list a pointer to the linked list
 */
void printList(LinkedList *list) {
  if (list == NULL) {
    return;
  }
  char *output = listToString(list);
  if (output != NULL) {
    printf("%s", output);
    free(output);
  }
}

/**
 * @brief converts the linked list to a string representation
 *
 * allocates and returns a string describing the contents of the linked list
 * the format is: "LinkedList: [data1] -> [data2] -> ...\n"
 * the caller is responsible for freeing the returned string
 *
 * @param list a pointer to the linked list
 *
 * @return a pointer to thenewly allocated string representing the list, or NULL
 * if memory allocation fails
 */
char *listToString(LinkedList *list) {
  if (list == NULL) {
    return NULL;
  }
  size_t bufferSize = INITIAL_BUFFER_SIZE;
  char *buffer = malloc(bufferSize);
  if (!buffer) {
    return NULL;
  }
  size_t used = 0;
  int written = snprintf(buffer, bufferSize, "LinkedList: ");
  if (written < 0) {
    free(buffer);
    return NULL;
  }
  used += written;
  LinkedNode *current = list->head;
  while (current != NULL) {
    int nodeLen = snprintf(NULL, 0, "[%d]", current->data);
    if (nodeLen < 0) {
      free(buffer);
      return NULL;
    }
    size_t needed = used + nodeLen + (current->next ? 4 : 1) + 1;
    if (needed > bufferSize) {
      bufferSize = needed;
      char *newBuffer = realloc(buffer, bufferSize);
      if (!newBuffer) {
        free(buffer);
        return NULL;
      }
      buffer = newBuffer;
    }
    written = snprintf(buffer + used, bufferSize - used, "[%d]", current->data);
    if (written < 0) {
      free(buffer);
      return NULL;
    }
    used += written;
    if (current->next) {
      written = snprintf(buffer + used, bufferSize - used, " -> ");
      used += written;
    } else {
      written = snprintf(buffer + used, bufferSize - used, "\n");
      used += written;
    }
    current = current->next;
  }
  return buffer;
}

/**
 * @brief checks whether the list is empty
 *
 * @param list a pointer to the linked list
 *
 * @return 1 if the list is empty, 0 otherwise
 */
bool isEmpty(const LinkedList *list) {
  return (list == NULL || list->size == 0);
}

/**
 * @brief returns the number of elements in the list
 *
 * @param list a pointer to the linked list
 *
 * @return the number of nodes currently in the list
 */
int getSize(const LinkedList *list) {
  if (list == NULL) {
    return 0;
  }
  return list->size;
}
