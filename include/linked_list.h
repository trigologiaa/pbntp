#ifndef LINKED_LIST_H

#define LINKED_LIST_H

#include <stdbool.h>

/**
 * @brief A node structure in a singly linked list.
 *
 * This struct represents a single node in a doubly linked list, containing a
 * pointer to the data, the next node, and the previous node.
 */
typedef struct DoubleLinkedNode {
  void *data;                    // Pointer to the data stored in the node.
  struct DoubleLinkedNode *next; // Pointer to the next node in the list.
  struct DoubleLinkedNode *prev; // Pointer to the previous node in the list.
} DoubleLinkedNode;

/**
 * @brief A circular doubly linked list structure.
 *
 * This struct represents a circular doubly linked list, containing pointers to
 * the head and tail nodes, as well as the size of the list.
 */
typedef struct CircularList {
  DoubleLinkedNode *head; ///< Pointer to the first node in the list.
  DoubleLinkedNode *tail; ///< Pointer to the last node in the list.
  int size;               ///< Number of elements in the list.
} CircularList;

/**
 * @brief Creates a new node for a linked list.
 *
 * Allocates dynamic memory for a new node of type DoubleLinkedNode, assigns the
 * supplied data value, and sets the 'next' pointer to NULL.
 *
 * @param data The data value to be stored in the node.
 *
 * @return A pointer to the newly created node, or NULL if memory allocation
 * fails.
 */
DoubleLinkedNode *create_node(void *data);

/**
 * @brief Searches for the first node in the list with the given data.
 *
 * Iterates through the linked list starting from the head and returns a pointer
 * to the first node that contains the specified data.
 *
 * @param list The pointer to the linked list to search.
 * @param data The data value to search for.
 * @param position The pointer to the position in the linked list.
 * @param cmp Comparison function that takes two pointers to data and returns
 * true if they are equal.
 *
 * @return A pointer to the matching node if found, NULL otherwise.
 */
DoubleLinkedNode *find(const CircularList *list, void *data, int *position,
                       bool (*cmp)(void *, void *));

/**
 * @brief Creates a new empty linked list.
 *
 * Allocates memory for a new CircularList structure and initializes its
 * members.
 *
 * @return A pointer to the newly created list, or NULL if memory allocation
 * fails.
 */
CircularList *create_list();

/**
 * @brief Destroys the list and frees all associated memory.
 *
 * Clears the list and frees the memory allocated for the list structure.
 *
 * @param list A pointer to the linked list to destroy.
 */
void destroy_list(CircularList *list, void (*destroyData)(void *));

/**
 * @brief Clears all elements from the list without deallocating the list
 * structure itself.
 *
 * Removes all nodes from the list and frees their memory.
 *
 * @param list A pointer to the linked list to clear.
 */
void clear(CircularList *list, void (*destroyData)(void *));

/**
 * @brief Adds a new node containing the given data at the beginning of the
 * list.
 *
 * Allocates memory for a new node and inserts it at the head of the list.
 *
 * @param list A pointer to the linked list.
 * @param data The data to insert in the new node.
 */
void prepend(CircularList *list, void *data);

/**
 * @brief Adds a new node containing the given data at the end of the list.
 *
 * Allocates memory for a new node and appends it to the tail of the list.
 *
 * @param list A pointer to the linked list.
 * @param data The data to insert in the new node.
 */
void append(CircularList *list, void *data);

/**
 * @brief Removes the first node from the list and frees its memory.
 *
 * Updates the head pointer and list size, if the list becomes empty, also
 * updates the tail.
 *
 * @param list A pointer to the linked list.
 */
void remove_first(CircularList *list);

/**
 * @brief Removes the last node from the list and frees its memory.
 *
 * If the list is empty, the function does nothing.
 *
 * @param list A pointer to the linked list.
 */
void remove_last(CircularList *list);

/**
 * @brief Removes the first occurrence of the specified data from the list.
 *
 * Searches the list for a node with matching data and removes it.
 *
 * @param list A pointer to the linked list.
 * @param data The data value to remove.
 * @param cmp Comparison function that takes two pointers to data and returns
 * true if they are equal.
 *
 * @return true if the element was removed, false otherwise.
 */
bool remove_data(CircularList *list, void *data, bool (*cmp)(void *, void *));

/**
 * @brief Prints the contents of the linked list.
 *
 * Outputs each element in the list in order, formatted as: CircularList: [data]
 * -> ...
 *
 * @param list A pointer to the linked list.
 * @param toString Function that converts the data to a string representation.
 */
void print_list(CircularList *list, char *(*toString)(void *));

/**
 * @brief Converts the linked list to a string representation.
 *
 * Allocates and returns a string describing the contents of the linked list.
 * The format is: "CircularList: [data1] -> [data2] -> ...\n".
 * The caller is responsible for freeing the returned string.
 *
 * @param list A pointer to the linked list.
 * @param toString Function that converts the data to a string representation.
 *
 * @return A pointer to the newly allocated string representing the list, or
 * NULL if memory allocation fails.
 */
char *list_to_string(CircularList *list, char *(*toString)(void *));

/**
 * @brief Checks whether the list is empty.
 *
 * @param list A pointer to the linked list.
 *
 * @return true if the list is empty, false otherwise.
 */
bool is_empty(const CircularList *list);

/**
 * @brief Returns the number of elements in the list.
 *
 * @param list A pointer to the linked list.
 *
 * @return The number of nodes currently in the list.
 */
int get_size(const CircularList *list);

/**
 * @brief Applies a function to each element in the circular doubly linked list.
 *
 * Iterate through all nodes in the list and applies the specified action to the
 * data of each node. This function is useful for performing operations such as
 * printing, modifying, or freeing the contents of each node.
 *
 * @param list A pointer to the CircularList.
 * @param action A function pointer that takes a void pointer to the data and
 * performs an action on it. The function is applied to each element in the
 * list.
 */
void for_each(CircularList *ist, void (*action)(void *));

#endif
