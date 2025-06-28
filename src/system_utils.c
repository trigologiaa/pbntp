#include "../include/system_utils.h"
#include "../include/linked_list.h"
#include "../include/student.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int global_id_counter = 1;

/**
 * @brief Generates a unique integer ID.
 *
 * Returns a sequential integer each time the function is called. Used for
 * assigning unique identifiers to the new entities (e.g., students or
 * subjects).
 *
 * @return A unique integer ID.
 */
int generate_unique_id() { return global_id_counter++; }

/**
 * @brief Waits for the user to press ENTER to continue.
 *
 * Displays a prompt and pauses the program until the user presses the ENTER
 * key. Useful for paginating output or waiting for user confirmation.
 */
void press_enter_to_continue() {
  printf("\nPress ENTER to continue...");
  getchar();
}

/**
 * @brief Sorts a list of students in descending order by average grade.
 *
 * Rearranges the elements of the given student list in-place using a
 * bubble-sort-like algorithm. Students with higher average grades appear first.
 *
 * @param students A pointer to a CircularList containing Student elements.
 */
void sort_students_by_average(CircularList *students) {
  if (!students || students->size < 2)
    return;
  for (DoubleLinkedNode *i = students->head; i != NULL; i = i->next) {
    for (DoubleLinkedNode *j = i->next; j != NULL; j = j->next) {
      Student *a = (Student *)i->data;
      Student *b = (Student *)j->data;
      if (a->average < b->average) {
        void *tmp = i->data;
        i->data = j->data;
        j->data = tmp;
      }
    }
  }
}

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
void paginate_list(CircularList *list, int pageSize,
                   char *(*toString)(void *)) {
  if (!list || pageSize <= 0 || !toString) {
    return;
  }
  int total = get_size(list);
  if (total == 0) {
    printf("No data to display.\n");
    return;
  }
  int currentIndex = 0;
  DoubleLinkedNode *node = list->head;
  while (currentIndex < total) {
    system("clear || cls");
    printf("Showing items %d to %d of %d:\n", currentIndex + 1,
           (currentIndex + pageSize > total ? total : currentIndex + pageSize),
           total);
    for (int i = 0; i < pageSize && currentIndex < total; i++) {
      char *str = toString(node->data);
      printf("%s\n", str);
      free(str);
      node = node->next;
      currentIndex++;
    }
    if (currentIndex < total) {
      press_enter_to_continue();
    }
  }
}
