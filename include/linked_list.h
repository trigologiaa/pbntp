#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <stdbool.h>

/**
 * @brief a node in a singly linked list
 */
typedef struct LinkedNode {
  int data;                ///< the integer data stored in the node
  struct LinkedNode *next; ///< pointer to the next node in the list
} LinkedNode;

/**
 * @brief a singly linked list structure
 */
typedef struct LinkedList {
  LinkedNode *head; ///< pointer to the first node in the list
  LinkedNode *tail; ///< pointer to the last node in the list
  int size;         ///< number of elements in the list
} LinkedList;

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
LinkedNode *createNode(int data);

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
LinkedNode *find(const LinkedList *list, int data);

/**
 * @brief creates a new empty linked list
 *
 * allocates memory for a new LinkedList structure and initializes its members
 *
 * @return a pointer to the newly created list, or NULL if memory allocation
 * fails
 */
LinkedList *createList();

/**
 * @brief destroys the list and frees all associated memory
 *
 * clears the list and frees the memory allocated for the list structure
 *
 * @param list a pointer to the linked list to destroy
 */
void destroyList(LinkedList *list);

/**
 * @brief clears all elements from the list without deallocating the list
 * structure itself
 *
 * removes all nodes from the list and frees their memory
 *
 * @param list a pointer to the linked list to clear
 */
void clear(LinkedList *list);

/**
 * @brief adds a new node containing the given data at the beginning of the
 * list
 *
 * allocates memory for a new node and inserts it at the head of the list
 *
 * @param list a pointer to the linked list
 * @param data the integer data to insert
 */
void prepend(LinkedList *list, int data);

/**
 * @brief adds a new node containing the given data at the end of the list
 *
 * allocates memory for a new node and appends it to the tail of the list
 *
 * @param list a pointer to the linked list
 * @param data the integer data to insert
 */
void append(LinkedList *list, int data);

/**
 * @brief removes the first node from the list and frees its memory
 *
 * updates the head pointer and list size, if the list becomes empty, also
 * updates the tail
 *
 * @param list a pointer to the linked list
 */
void removeFirst(LinkedList *list);

/**
 * @brief removes the last node from the list and frees its memory
 *
 * if the list is empty, the function does nothing
 *
 * @param list a pointer to the linked list
 */
void removeLast(LinkedList *list);

/**
 * @brief removes the first occurrence of the specified data from the list
 *
 * searches the list for a node with matching data and removes it
 *
 * @param list a pointer to the linked list
 * @param data the integer value to remove
 */
void removeData(LinkedList *list, int data);

/**
 * @brief prints the contents of the linked list
 *
 * outputs each element in the list in order, formatted as: LinkedList: [data]
 * -> ...
 *
 * @param list a pointer to the linked list
 */
void printList(LinkedList *list);

/**
 * @brief pepe
 */
char *listToString(LinkedList *list);

/**
 * @brief checks whether the list is empty
 *
 * @param list a pointer to the linked list
 *
 * @return 1 if the list is empty, 0 otherwise
 */
bool isEmpty(const LinkedList *list);

/**
 * @brief returns the number of elements in the list
 *
 * @param list a pointer to the linked list
 *
 * @return the number of nodes currently in the list
 */
int getSize(const LinkedList *list);

#endif
