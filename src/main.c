#include "../include/linked_list.h"
#include "../include/linked_list_test.h"
#include <stdio.h>
#include <wchar.h>

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
      test_createEmptyList();
      test_createListWithOneElement();
      test_appendElement();
      test_removeFirstElement();
      test_removeData();
      test_findElement();
      test_findUnexistingElement();
      test_size();
      break;
    case 0:
      printf("Returning to main menu...\n");
      break;
    default:
      printf("Invalid test option. Try again.\n");
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
        LinkedNode *node = find(list, value);
        if (node != NULL) {
          printf("\n ->> Element %d found in the Linked List\n", value);
        } else {
          printf("\n ->> Element not found\n");
        }
      }
      break;
    case 9:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        removeFirst(list);
        printf("\n ->> First element removed (if exist)\n");
      }
      break;
    case 10:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        removeLast(list);
        printf("\n ->> Last element removed (if exist)\n");
      }
      break;
    case 11:
      if (list == NULL) {
        printf("\n ->> You have to create a Linked List first\n");
      } else {
        printf("\n ->> Insert a value to remove: ");
        scanf("%d", &value);
        removeData(list, value);
        printf("\n ->> The element was removed (if existed)\n");
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
    case 0:
      printf("\n ->> Leaving...\n");
      if (list != NULL) {
        destroyList(list);
      }
      break;
    default:
      printf("\n ->> Invalid option. Try again.\n");
    }
  } while (option != 0);
  return 0;
}
