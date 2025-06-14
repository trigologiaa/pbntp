#include "../include/linked_list.h"
#include "../include/student.h"
#include <stdio.h>
#include <wchar.h>

void menu() {
  printf("\n╭───── Students Administrator Control Panel ─────╮\n");
  printf("│  1. Add student                                 │\n");
  printf("│  2. Modify student data                         │\n");
  printf("│  3. List student                                │\n");
  printf("│  4. Delete student                              │\n");
  printf("│  5. Search students by age                      │\n");
  printf("│  6. Search students by name                     │\n");
  printf("│  7. Search students by ID                       │\n");
  printf("│  0. Out                                         │\n");
  printf("╰─────────────────────────────────────────────────╯\n");
  printf("\n  -> Choose an option: ");
}

void studentsMenu() {
  printf("\n╭──────────── Students Control Panel ────────────╮\n");
  printf("│  1. Register for course                         │\n");
  printf("│  2. Modify course                               │\n");
  printf("│  3. List student                                │\n");
  printf("│  4. Delete course                               │\n");
  printf("│  5. List courses                                │\n");
  printf("│  6. Take exam                                   │\n");
  printf("│  0. Out                                         │\n");
  printf("╰─────────────────────────────────────────────────╯\n");
  printf("\n  -> Choose an option: ");
}

int main() {
    CircularList *list = NULL;
    int option, value;
    do {
      menu();
      scanf("%d", &option);
      switch (option) {
        case 1: 
          if (list == NULL) {
            list = createList();
            printf("\n -> Name the student: ");
            
          }
        case 0:
          printf("\n ->> Leaving... \n");
          if (list != NULL) {
            // destroyList(list);
          }
          break;
      }
      
    } while (option != 0);
    return 0;
}