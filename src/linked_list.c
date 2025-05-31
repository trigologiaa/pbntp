#include <wchar.h>
#define _CRT_SECURE_NO_WARNINGS
#include "../include/linked_list.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define INITIAL_BUFFER_SIZE 256

/**
 * @brief creates a new node for a linked list
 *
 * allocates dynamic memory for a new node of type DoubleLinkedNode, assigns the
 * supplied data value, and sets the 'next' pointer to NULL
 *
 * @param data the integer value to be stored in the node
 *
 * @return a pointer to the newly created node, or NULL if memory alocation
 * fails
 */
DoubleLinkedNode *createNode(int data) {
  DoubleLinkedNode *node = (DoubleLinkedNode *)malloc(sizeof(DoubleLinkedNode));
  if (!node) {
    return NULL;
  }
  node->data = data;
  node->next = node->prev = NULL;
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
 * @param position the pointer to the position in the linked list
 *
 * @return a pointer to the matching node if found
 */
DoubleLinkedNode *find(const CircularList *list, int data, int *position) {
  if (list == NULL || list->head == NULL) {
    return NULL;
  }
  DoubleLinkedNode *current = list->head;
  int index = 0;
  do {
    if (current->data == data) {
      if (position)
        *position = index;
      return current;
    }
    current = current->next;
    index++;
  } while (current != list->head);
  return NULL;
}

/**
 * @brief creates a new empty linked list
 *
 * allocates memory for a new CircularList structure and initializes its
 * members
 *
 * @return a pointer to the newly created list, or NULL if memory allocation
 * fails
 */
CircularList *createList() {
  CircularList *list = (CircularList *)malloc(sizeof(CircularList));
  if (!list) {
    return NULL;
  }
  list->head = list->tail = NULL;
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
void destroyList(CircularList *list) {
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
void clear(CircularList *list) {
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
void prepend(CircularList *list, int data) {
  if (list == NULL) {
    return;
  }
  DoubleLinkedNode *node = createNode(data);
  if (!node) {
    return;
  }
  if (isEmpty(list)) {
    node->next = node->prev = node;
    list->head = list->tail = node;
  } else {
    node->next = list->head;
    node->prev = list->tail;
    list->head->prev = node;
    list->tail->next = node;
    list->head = node;
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
void append(CircularList *list, int data) {
  if (list == NULL) {
    return;
  }
  DoubleLinkedNode *node = createNode(data);
  if (!node) {
    return;
  }
  if (isEmpty(list)) {
    node->next = node->prev = node;
    list->head = list->tail = node;
  } else {
    node->prev = list->tail;
    node->next = list->head;
    list->tail->next = node;
    list->head->prev = node;
    list->tail = node;
  }
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
void removeFirst(CircularList *list) {
  if (list == NULL || isEmpty(list)) {
    return;
  }
  DoubleLinkedNode *temp = list->head;
  if (getSize(list) == 1) {
    list->head = list->tail = NULL;
  } else {
    list->head = list->head->next;
    list->head->prev = list->tail;
    list->tail->next = list->head;
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
void removeLast(CircularList *list) {
  if (list == NULL || isEmpty(list)) {
    return;
  }
  DoubleLinkedNode *temp = list->tail;
  if (getSize(list) == 1) {
    list->head = list->tail = NULL;
  } else {
    list->tail = list->tail->prev;
    list->tail->next = list->head;
    list->head->prev = list->tail;
  }
  free(temp);
  list->size--;
}

/**
 * @brief removes the first occurrence of the specified data from the list
 *
 * searches the list for a node with matching data and removes it
 *
 * @param list a pointer to the linked list
 * @param data the integer value to remove
 *
 * @return true if the element was removed, false otherwise
 */
bool removeData(CircularList *list, int data) {
  if (list == NULL || isEmpty(list)) {
    return false;
  }
  DoubleLinkedNode *current = list->head;

  do {
    if (current->data == data) {
      if (list->size == 1) {
        // Only one node
        list->head = list->tail = NULL;
      } else {
        if (current == list->head)
          list->head = current->next;
        if (current == list->tail)
          list->tail = current->prev;

        current->prev->next = current->next;
        current->next->prev = current->prev;
      }

      free(current);
      list->size--;
      return true;
    }
    current = current->next;
  } while (current != list->head);

  return false;
}

/**
 * @brief prints the contents of the linked list
 *
 * outputs each element in the list in order using the function listToString,
 * formatted as: CircularList: [data] -> ...
 *
 * @param list a pointer to the linked list
 */
void printList(CircularList *list) {
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
 * the format is: "CircularList: [data1] <-> [data2] <-> ...\n"
 * the caller is responsible for freeing the returned string
 *
 * @param list a pointer to the linked list
 *
 * @return a pointer to thenewly allocated string representing the list, or NULL
 * if memory allocation fails
 */
char *listToString(CircularList *list) {
  if (list == NULL || isEmpty(list)) {
    char *emptyStr = malloc(32);
    if (emptyStr) {
      snprintf(emptyStr, 32, "List: (empty)\n");
    }
    return emptyStr;
  }
  size_t bufferSize = INITIAL_BUFFER_SIZE;
  char *buffer = malloc(bufferSize);
  if (!buffer) {
    return NULL;
  }
  size_t used = 0;
  int written = snprintf(buffer, bufferSize, "List: -> ");
  if (written < 0) {
    free(buffer);
    return NULL;
  }
  used += written;
  DoubleLinkedNode *current = list->head;
  do {
    int nodeLen = snprintf(NULL, 0, "[%d]", current->data);
    size_t needed = used + nodeLen + 6 + 1; // 6 = len(" <-> ") or " <-\n"
    if (needed > bufferSize) {
      bufferSize *= 2;
      if (bufferSize < needed)
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
    current = current->next;
    if (current != list->head) {
      written = snprintf(buffer + used, bufferSize - used, " <-> ");
      used += written;
    } else {
      written = snprintf(buffer + used, bufferSize - used, " <-\n");
      used += written;
    }
  } while (current != list->head);
  return buffer;
}

/**
 * @brief checks whether the list is empty
 *
 * @param list a pointer to the linked list
 *
 * @return 1 if the list is empty, 0 otherwise
 */
bool isEmpty(const CircularList *list) {
  return (list == NULL || list->size == 0);
}

/**
 * @brief returns the number of elements in the list
 *
 * @param list a pointer to the linked list
 *
 * @return the number of nodes currently in the list
 */
int getSize(const CircularList *list) {
  if (list == NULL) {
    return 0;
  }
  return list->size;
}
