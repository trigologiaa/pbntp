#include "../include/linked_list.h"
#include "../include/linked_list_test.h"
#include <stdio.h>
#include <wchar.h>

void runAllOperations(LinkedList *list) {
  int value;
  if (list == NULL) {
    list = createList();
    printf("\n ->> Linked List created\n");
  }
  printf("\n ->> Inserting 5 elements at the beginning...\n");
  for (value = 5; value > 0; value--) {
    prepend(list, value);
    printf("    -> Inserted %d at the beginning\n", value);
    printf("    -> Current ");
    printList(list);
  }
  printf("\n ->> Inserting 5 elements at the end...\n");
  for (value = 6; value <= 10; value++) {
    append(list, value);
    printf("    -> Inserted %d at the end\n", value);
    printf("    -> Current ");
    printList(list);
  }
  printf("\n ->> Size of the Linked List: %d\n", getSize(list));
  value = 5;
  printf("\n ->> Searching for element %d...\n", value);
  int position = -1;
  LinkedNode *node = find(list, value, &position);
  if (node != NULL) {
    printf("\n ->> Element %d found at index %d in the Linked List\n", value,
           position);
  } else {
    printf("\n ->> Element %d not found\n", value);
  }
  printf("\n ->> Removing the first element...\n");
  if (!isEmpty(list)) {
    removeFirst(list);
    printf("\n ->> First element removed\n");
    printf("    -> Current ");
    printList(list);
  } else {
    printf("\n ->> The list is empty, no element to remove\n");
  }
  printf("\n ->> Removing the last element...\n");
  if (!isEmpty(list)) {
    removeLast(list);
    printf("\n ->> Last element removed\n");
    printf("    -> Current ");
    printList(list);
  } else {
    printf("\n ->> The list is empty, no element to remove\n");
  }
  value = 3;
  printf("\n ->> Removing element %d...\n", value);
  if (!removeData(list, value)) {
    printf("\n ->> Element %d not found\n", value);
  } else {
    printf("\n ->> Element %d removed\n", value);
  }
  printf("\n ->> Current ");
  printList(list);
  printf("\n ->> Clearing the Linked List...\n");
  clear(list);
  printf("\n ->> Linked List cleared\n");
  printf("\n ->> Final Linked List (should be empty): ");
  printList(list);
}

void runTestMenu() {
  int testOption;
  do {
    printf("\n╭─── Linked List Test Menu ─────────────╮\n");
    printf("│ 1. Test: Create Empty List            │\n");
    printf("│ 2. Test: Create List With One Element │\n");
    printf("│ 3. Test: Append Element               │\n");
    printf("│ 4. Test: Remove First Element         │\n");
    printf("│ 5. Test: Remove Data                  │\n");
    printf("│ 6. Test: Find Element                 │\n");
    printf("│ 7. Test: Find Unexisting Element      │\n");
    printf("│ 8. Test: Size                         │\n");
    printf("│ 9. Run All Tests                      │\n");
    printf("│ 0. Return to Main Menu                │\n");
    printf("╰───────────────────────────────────────╯\n");
    printf("\n  -> Choose a test option: ");
    scanf("%d", &testOption);
    switch (testOption) {
    case 1:
      test_createEmptyList();
      break;
    case 2:
      test_createListWithOneElement();
      break;
    case 3:
      test_appendElement();
      break;
    case 4:
      test_removeFirstElement();
      break;
    case 5:
      test_removeData();
      break;
    case 6:
      test_findElement();
      break;
    case 7:
      test_findUnexistingElement();
      break;
    case 8:
      test_size();
      break;
    case 9:
      printf("\n ->> Initializing all tests...\n");
      test_createEmptyList();
      test_createListWithOneElement();
      test_appendElement();
      test_removeFirstElement();
      test_removeData();
      test_findElement();
      test_findUnexistingElement();
      test_size();
      printf("\n ->> All tests were executed successfully\n");
      break;
    case 0:
      printf("\n ->> Returning to main menu...\n");
      break;
    default:
      printf("\n ->> Invalid test option. Try again.\n");
    }
  } while (testOption != 0);
}

void menu() {
  printf("\n╭──── Linked List Menu ──────────────────────────╮\n");
  printf("│  1. Create Linked List                         │\n");
  printf("│  2. Destroy Linked List                        │\n");
  printf("│  3. Verify if the Linked List is empty         │\n");
  printf("│  4. Get size of Linked List                    │\n");
  printf("│  5. Empty Linked List                          │\n");
  printf("│  6. Insert at the beginning of the Linked List │\n");
  printf("│  7. Insert at the end of the Linked List       │\n");
  printf("│  8. Find element                               │\n");
  printf("│  9. Remove the first element                   │\n");
  printf("│ 10. Remove the last element                    │\n");
  printf("│ 11. Remove a specific element                  │\n");
  printf("│ 12. Print Linked List                          │\n");
  printf("│ 13. Linked List Test Menu                      │\n");
  printf("│ 14. Run all operations (simulation of use)     │\n");
  printf("│  0. Out                                        │\n");
  printf("╰────────────────────────────────────────────────╯\n");
  printf("\n  -> Choose an option: ");
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
        printf("\n ->> There is a Linked List created. Destroy it first\n");
      } else {
        list = createList();
        printf("\n ->> Linked List created\n");
      }
      break;
    case 2:
      if (list != NULL) {
        destroyList(list);
        list = NULL;
        printf("\n ->> Linked List destroyed\n");
      } else {
        printf("\n ->> There is no Linked List created\n");
      }
      break;
    case 3:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        printf(isEmpty(list) ? "\n ->> The Linked List is empty\n"
                             : "\n ->> The Linked List is not empty\n");
      }
      break;
    case 4:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        printf("\n ->> Size of the Linked List: %d\n", getSize(list));
      }
      break;
    case 5:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        clear(list);
        printf("\n ->> Linked List cleared\n");
      }
      break;
    case 6:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        printf("\n  -> Insert a value to insert at the beginning: ");
        scanf("%d", &value);
        prepend(list, value);
        printf("\n ->> Value inserted\n");
        printf("\n ->> Currently -> ");
        printList(list);
      }
      break;
    case 7:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        printf("\n  -> Insert a value to insert at the end: ");
        scanf("%d", &value);
        append(list, value);
        printf("\n ->> Value inserted\n");
        printf("\n ->> Currently -> ");
        printList(list);
      }
      break;
    case 8:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        printf("\n ->> Insert a value to search: ");
        scanf("%d", &value);
        int position = -1;
        LinkedNode *node = find(list, value, &position);
        if (node != NULL) {
          printf("\n ->> Element %d found at index %d in the Linked List\n",
                 value, position);
        } else {
          printf("\n ->> Element not found\n");
        }
      }
      break;
    case 9:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        if (isEmpty(list)) {
          printf("\n ->> The list is empty, no element to remove\n");
        } else {
          removeFirst(list);
          printf("\n ->> First element removed\n");
        }
      }
      break;
    case 10:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        if (isEmpty(list)) {
          printf("\n ->> The list is empty, no element to remove\n");
        } else {
          removeLast(list);
          printf("\n ->> Last element removed\n");
        }
      }
      break;
    case 11:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        printf("\n  -> Insert a value to remove: ");
        scanf("%d", &value);
        if (!removeData(list, value)) {
          printf("\n ->> Element not found\n");
        } else {
          printf("\n ->> The element was removed\n");
        }
      }
      break;
    case 12:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        printf("\n ->> ");
        printList(list);
      }
      break;
    case 13:
      runTestMenu();
      break;
    case 14:
      if (list == NULL) {
        list = createList();
        printf("\n --> Linked List created\n");
      }
      runAllOperations(list);
      break;
    case 0:
      printf("\n ->> Leaving...\n");
      if (list != NULL) {
        destroyList(list);
      }
      break;
    default:
      printf("\n ->> Invalid option, try again\n");
    }
  } while (option != 0);
  return 0;
}
