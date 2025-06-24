#ifndef SYSTEM_UTILS_H

#define SYSTEM_UTILS_H

#include "../include/linked_list.h"

/**
 * @brief Generates a unique integer ID.
 *
 * Returns a sequential integer each time the function is called. Used for
 * assigning unique identifiers to the new entities (e.g., students or
 * subjects).
 *
 * @return A unique integer ID.
 */
int generate_unique_id();

/**
 * @brief Waits for the user to press ENTER to continue.
 *
 * Displays a prompt and pauses the program until the user presses the ENTER
 * key. Useful for paginating output or waiting for user confirmation.
 */
void press_enter_to_continue();

/**
 * @brief Sorts a list of students in descending order by average grade.
 *
 * Rearranges the elements of the given student list in-place using a
 * bubble-sort-like algorithm. Students with higher average grades appear first.
 *
 * @param students A pointer to a CircularList containing Student elements.
 */
void sort_students_by_average(CircularList *students);

/**
 * @brief Displays a paginated view of a list.
 *
 * Prints the elements of the given list in pages of a specified size. Each
 * element is converted to a string using a provided `toString` function. After
 * each page, the user is prompted to press ENTER to continue.
 *
 * @param list A pointer to the CircularList to be displayed.
 * @param pageSize The number of items to display per page.
 * @param toString A function that converts a list item to a string.
 */
void paginate_list(CircularList *list, int pageSize, char *(*toString)(void *));

#endif