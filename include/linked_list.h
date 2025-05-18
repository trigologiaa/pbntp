#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <stdbool.h>

/**
 * @brief a node in a singly linked list
 */
typedef struct DoubleLinkedNode {
  int data;                      ///< the integer data stored in the node
  struct DoubleLinkedNode *next; ///< pointer to the next node in the list
  struct DoubleLinkedNode *prev; ///< pointer to the previous node in the list
} DoubleLinkedNode;

/**
 * @brief a singly linked list structure
 */
typedef struct DoubleLinkedList {
  DoubleLinkedNode *head; ///< pointer to the first node in the list
  DoubleLinkedNode *tail; ///< pointer to the last node in the list
  int size;               ///< number of elements in the list
} DoubleLinkedList;

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
DoubleLinkedNode *createNode(int data);

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
DoubleLinkedNode *find(const DoubleLinkedList *list, int data, int *position);

/**
 * @brief creates a new empty linked list
 *
 * allocates memory for a new DoubleLinkedList structure and initializes its
 * members
 *
 * @return a pointer to the newly created list, or NULL if memory allocation
 * fails
 */
DoubleLinkedList *createList();

/**
 * @brief destroys the list and frees all associated memory
 *
 * clears the list and frees the memory allocated for the list structure
 *
 * @param list a pointer to the linked list to destroy
 */
void destroyList(DoubleLinkedList *list);

/**
 * @brief clears all elements from the list without deallocating the list
 * structure itself
 *
 * removes all nodes from the list and frees their memory
 *
 * @param list a pointer to the linked list to clear
 */
void clear(DoubleLinkedList *list);

/**
 * @brief adds a new node containing the given data at the beginning of the
 * list
 *
 * allocates memory for a new node and inserts it at the head of the list
 *
 * @param list a pointer to the linked list
 * @param data the integer data to insert
 */
void prepend(DoubleLinkedList *list, int data);

/**
 * @brief adds a new node containing the given data at the end of the list
 *
 * allocates memory for a new node and appends it to the tail of the list
 *
 * @param list a pointer to the linked list
 * @param data the integer data to insert
 */
void append(DoubleLinkedList *list, int data);

/**
 * @brief removes the first node from the list and frees its memory
 *
 * updates the head pointer and list size, if the list becomes empty, also
 * updates the tail
 *
 * @param list a pointer to the linked list
 */
void removeFirst(DoubleLinkedList *list);

/**
 * @brief removes the last node from the list and frees its memory
 *
 * if the list is empty, the function does nothing
 *
 * @param list a pointer to the linked list
 */
void removeLast(DoubleLinkedList *list);

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
bool removeData(DoubleLinkedList *list, int data);

/**
 * @brief prints the contents of the linked list
 *
 * outputs each element in the list in order, formatted as: DoubleLinkedList:
 * [data]
 * -> ...
 *
 * @param list a pointer to the linked list
 */
void printList(DoubleLinkedList *list);

/**
 * @brief converts the linked list to a string representation
 *
 * allocates and returns a string describing the contents of the linked list
 * the format is: "DoubleLinkedList: [data1] -> [data2] -> ...\n"
 * the caller is responsible for freeing the returned string
 *
 * @param list a pointer to the linked list
 *
 * @return a pointer to thenewly allocated string representing the list, or NULL
 * if memory allocation fails
 */
char *listToString(DoubleLinkedList *list);

/**
 * @brief checks whether the list is empty
 *
 * @param list a pointer to the linked list
 *
 * @return 1 if the list is empty, 0 otherwise
 */
bool isEmpty(const DoubleLinkedList *list);

/**
 * @brief returns the number of elements in the list
 *
 * @param list a pointer to the linked list
 *
 * @return the number of nodes currently in the list
 */
int getSize(const DoubleLinkedList *list);

#endif
