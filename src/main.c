#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

void menu() {
  printf("\n<--- Linked List Menu --->\n");
  printf("1. Create Linked List\n");
  printf("2. Destroy Linked List\n");
  printf("3. Verify if the Linked List is empty\n");
  printf("4. Get size of Linked List\n");
  printf("5. Empty Linked List\n");
  printf("6. Insert at the beginning of the Linked List\n");
  printf("7. Insert at the end of the Linked List\n");
  printf("8. Find element\n");
  printf("9. Remove the first element\n");
  printf("10. Remove the last element\n");
  printf("11. Remove a specific element\n");
  printf("12. Print Linked List\n");
  printf("0. Out\n");
  printf("<--- Linked List Menu --->\n");
  printf("Choose an option: \n");
}

int main() {
  LinkedList *list = NULL;
  int option, value;
  do {
    menu();
    scanf("%d", &option);
    switch (option) {
    case 1:
      if (list != NULL) {
        printf("There is a list created. Destroy it first\n");
      } else {
        list = createList();
        printf("Linked List created\n");
      }
      break;
    case 2:
      if (list != NULL) {
        destroyList(list);
        list = NULL;
        printf("Linked List destroyed\n");
      } else {
        printf("There is no Linked List created\n");
      }
      break;
    case 3:
      if (list == NULL) {
        printf("You have to create a Linked List first\n");
      } else {
        printf(isEmpty(list) ? "The Linked List is empty\n"
                             : "The Linked List is not empty\n");
      }
      break;
    case 4:
      if (list == NULL) {
        printf("You have to create a Linked List first\n");
      } else {
        printf("Size of the Linked List: %d\n", size(list));
      }
      break;
    case 5:
      if (list == NULL) {
        printf("You have to create a Linked List first\n");
      } else {
        clear(list);
        printf("Linked List cleared\n");
      }
      break;
    case 6:
      if (list == NULL) {
        printf("You have to create a Linked List first\n");
      } else {
        printf("Insert a value to insert at the beginning\n");
        scanf("%d", &value);
        prepend(list, value);
        printf("Value inserted\n");
      }
      break;
    case 7:
      if (list == NULL) {
        printf("You have to create a Linked List first\n");
      } else {
        printf("Insert a value to insert at the end\n");
        scanf("%d", &value);
        append(list, value);
        printf("Value inserted\n");
      }
      break;
    case 8:
      if (list == NULL) {
        printf("You have to create a Linked List first\n");
      } else {
        printf("Insert a value to search: ");
        scanf("%d", &value);
        LinkedNode *node = find(list, value);
        if (node != NULL) {
          printf("Element %d found in the Linked List\n", value);
        } else {
          printf("Element not found\n");
        }
      }
      break;
    case 9:
      if (list == NULL) {
        printf("You have to create a Linked List first\n");
      } else {
        removeFirst(list);
        printf("First element removed (if exist)\n");
      }
      break;
    case 10:
      if (list == NULL) {
        printf("You have to create a Linked List first\n");
      } else {
        removeLast(list);
        printf("Last element removed (if exist)\n");
      }
      break;
    case 11:
      if (list == NULL) {
        printf("You have to create a Linked List first\n");
      } else {
        printf("Insert a value to remove: ");
        scanf("%d", &value);
        removeData(list, value);
        printf("The element was removed (if existed)\n");
      }
      break;
    case 12:
      if (list == NULL) {
        printf("You have to create a Linked List first\n");
      } else {
        printList(list);
      }
      break;
    case 0:
      printf("Leaving...\n");
      if (list != NULL) {
        destroyList(list);
      }
      break;
    default:
      printf("Invalid option. Try again.\n");
    }
  } while (option != 0);
  return 0;
}
