#include "../include/menu.h"
#include "../include/enrollment.h"
#include "../include/persistence.h"
#include "../include/search.h"
#include "../include/system_utils.h"
#include "../include/enrollment_test.h"
#include "../include/linked_list_test.h"
#include "../include/persistence_test.h"
#include "../include/search_test.h"
#include "../include/student_test.h"
#include "../include/subject_test.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu(CircularList *students, CircularList *subjects) {
  int option;
  do {
    printf("\n╭── Main Menu ─────────────────────────────────╮\n");
    printf("│ 1. Manage students                           │\n");
    printf("│ 2. Manage subjects                           │\n");
    printf("│ 3. Show statistics                           │\n");
    printf("│ 4. Generate test data                        │\n");
    printf("│ 5. Tests                                     │\n");
    printf("│ 0. Exit                                      │\n");
    printf("╰──────────────────────────────────────────────╯\n");
    printf("\n  -> Choose an option: ");
    scanf("%d", &option);
    getchar();
    switch (option) {
    case 1:
      students_menu(students, subjects);
      break;
    case 2:
      subjects_menu(subjects);
      break;
    case 3:
      show_statistics(students, subjects);
      press_enter_to_continue();
      break;
    case 4:
      generate_sample_data(students, subjects, 5);
      printf("\nTest data created.\n");
      press_enter_to_continue();
      break;
    case 5:
      tests_menu();
      break;
    case 0:
      break;
    default:
      printf("Invalid option.\n");
    }
  } while (option != 0);
}

void students_menu(CircularList *students, CircularList *subjects) {
  int option;
  do {
    printf("\n╭── Students Menu ─────────────────────────────╮\n");
    printf("│ 1. Register new student                      │\n");
    printf("│ 2. Modify student                            │\n");
    printf("│ 3. Delete student                            │\n");
    printf("│ 4. List all students                         │\n");
    printf("│ 5. Enroll in subject                         │\n");
    printf("│ 6. Record exam                               │\n");
    printf("│ 7. Search students by name                   │\n");
    printf("│ 8. Search students by age range              │\n");
    printf("│ 0. Back to main menu                         │\n");
    printf("╰──────────────────────────────────────────────╯\n");
    printf("\n  -> Choose an option: ");
    scanf("%d", &option);
    getchar();
    int id, age;
    char name[100];
    float grade;
    Student *student;
    Subject *subject;
    switch (option) {
    case 1:
      printf("Enter name: ");
      fgets(name, sizeof(name), stdin);
      name[strcspn(name, "\n")] = 0;
      printf("Enter age: ");
      scanf("%d", &age);
      getchar();
      student = create_student(name, age);
      student->id = generate_unique_id();
      append(students, student);
      printf("Student registered with ID: %d\n", student->id);
      break;
    case 2:
      printf("Enter student ID to modify: ");
      scanf("%d", &id);
      getchar();
      student = get_student_by_id(students, id);
      if (student) {
        printf("New name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;
        printf("New age: ");
        scanf("%d", &age);
        getchar();
        strcpy(student->name, name);
        student->age = age;
        printf("Student updated.\n");
      } else {
        printf("Student not found.\n");
      }
      break;
    case 3:
      printf("Enter student ID to delete: ");
      scanf("%d", &id);
      getchar();
      student = get_student_by_id(students, id);
      if (student && remove_data(students, student, compare_student_by_id)) {
        destroy_student(student);
        printf("Student removed.\n");
      } else {
        printf("Student not found.\n");
      }
      break;
    case 4:
      paginate_list(students, 5, student_to_string);
      break;
    case 5:
      printf("Student ID: ");
      scanf("%d", &id);
      getchar();
      student = get_student_by_id(students, id);
      printf("Subject ID: ");
      scanf("%d", &id);
      getchar();
      subject = get_subject_by_id(subjects, id);
      if (student && subject) {
        if (enroll_student(student, subject, subjects)) {
          printf("Enrolled.\n");
        } else {
          printf("Cannot enroll (check correlatives).\n");
        }
      } else {
        printf("Invalid student or subject.\n");
      }
      break;
    case 6:
      printf("Student ID: ");
      scanf("%d", &id);
      getchar();
      student = get_student_by_id(students, id);
      printf("Subject ID: ");
      scanf("%d", &id);
      getchar();
      printf("Grade: ");
      scanf("%f", &grade);
      getchar();
      if (record_exam(student, id, grade)) {
        printf("Exam recorded.\n");
      } else {
        printf("Could not record exam.\n");
      }
      break;
    case 7:
      printf("Enter name: ");
      fgets(name, sizeof(name), stdin);
      name[strcspn(name, "\n")] = 0;
      find_students_by_name(students, name);
      break;
    case 8:
      printf("Enter min age: ");
      scanf("%d", &age);
      getchar();
      int maxAge;
      printf("Enter max age: ");
      scanf("%d", &maxAge);
      getchar();
      find_students_by_age_range(students, age, maxAge);
      break;
    case 0:
      break;
    default:
      printf("Invalid option.\n");
    }
  } while (option != 0);
}

void subjects_menu(CircularList *subjects) {
  int option;
  do {
    printf("\n╭── Subjects Menu ─────────────────────────────╮\n");
    printf("│ 1. Create new subject                        │\n");
    printf("│ 2. Modify subject                            │\n");
    printf("│ 3. Delete subject                            │\n");
    printf("│ 4. List all subjects                         │\n");
    printf("│ 0. Back to main menu                         │\n");
    printf("╰──────────────────────────────────────────────╯\n");
    printf("\n  -> Choose an option: ");
    scanf("%d", &option);
    getchar();
    int id, credits;
    char name[100];
    Subject *subject;
    switch (option) {
    case 1:
      printf("Subject name: ");
      fgets(name, sizeof(name), stdin);
      name[strcspn(name, "\n")] = 0;
      printf("Credits: ");
      scanf("%d", &credits);
      getchar();
      subject = create_subject(name, credits);
      subject->id = generate_unique_id();
      append(subjects, subject);
      printf("Subject created with ID: %d\n", subject->id);
      break;
    case 2:
      printf("Subject ID to modify: ");
      scanf("%d", &id);
      getchar();
      subject = get_subject_by_id(subjects, id);
      if (subject) {
        printf("New name: ");
        fgets(name, sizeof(name), stdin);
        name[strcspn(name, "\n")] = 0;
        printf("New credits: ");
        scanf("%d", &credits);
        getchar();
        strcpy(subject->name, name);
        subject->credits = credits;
        printf("Subject updated.\n");
      } else {
        printf("Subject not found.\n");
      }
      break;
    case 3:
      printf("Subject ID to delete: ");
      scanf("%d", &id);
      getchar();
      subject = get_subject_by_id(subjects, id);
      if (subject && remove_data(subjects, subject, compare_subject_by_id)) {
        destroy_subject(subject);
        printf("Subject removed.\n");
      } else {
        printf("Subject not found.\n");
      }
      break;
    case 4:
      paginate_list(subjects, 5, subject_to_string);
      break;
    case 0:
      break;
    default:
      printf("Invalid option.\n");
    }
  } while (option != 0);
}

void tests_menu() {
  int option;
  do {
    printf("\n╭── Test Menu ─────────────────────────────────╮\n");
    printf("│ 1. Run All Tests                             │\n");
    printf("│ 2. Enrollment Test Menu                      │\n");
    printf("│ 3. Linked List Test Menu                     │\n");
    printf("│ 4. Persistence Test Menu                     │\n");
    printf("│ 5. Search Test Menu                          │\n");
    printf("│ 6. Student Test Menu                         │\n");
    printf("│ 7. Subject Test Menu                         │\n");
    printf("│ 0. Back to Main Menu                         │\n");
    printf("╰──────────────────────────────────────────────╯\n");
    printf("\n  -> Choose an option: ");
    scanf("%d", &option);
    getchar();
    switch (option) {
    case 1:
      run_enrollment_tests();
      run_linked_list_tests();
      run_persistence_tests();
      run_search_tests();
      run_student_tests();
      run_subject_tests();
      break;
    case 2:
      enrollment_test_menu();
      break;
    case 3:
      linked_list_test_menu();
      break;
    case 4:
      persistence_test_menu();
      break;
    case 5:
      search_test_menu();
      break;
    case 6:
      student_test_menu();
      break;
    case 7:
      subject_test_menu();
      break;
    case 0:
      break;
    default:
      printf("Invalid option.\n");
    }
  } while (option != 0);
}

void enrollment_test_menu() {
  int option;
  do {
    printf("\n╭── Test Menu ─────────────────────────────────╮\n");
    printf("│ 1. Run All Enrollment Tests                  │\n");
    printf("│ 2. Test Create Enrollment                    │\n");
    printf("│ 3. Test Can Enroll No Correlatives           │\n");
    printf("│ 4. Test Can Enroll With Correlatives         │\n");
    printf("│ 5. Test Enroll Student Success And Duplicate │\n");
    printf("│ 6. Test Record Exam Success And Failure      │\n");
    printf("│ 0. Back to Test Main Menu                    │\n");
    printf("╰──────────────────────────────────────────────╯\n");
    printf("\n  -> Choose an option: ");
    scanf("%d", &option);
    getchar();
    switch (option) {
    case 1:
      run_enrollment_tests();
      break;
    case 2:
      test_create_enrollment();
      break;
    case 3:
      test_can_enroll_no_correlatives();
      break;
    case 4:
      test_can_enroll_with_correlatives();
      break;
    case 5:
      test_enroll_student_success_and_duplicate();
      break;
    case 6:
      test_record_exam_success_and_failure();
      break;
    case 0:
      break;
    default:
      printf("Invalid option.\n");
    }
  } while (option != 0);
}

void linked_list_test_menu() {
  int option;
  do {
    printf("\n╭── Linked List Test Menu ─────────────────────╮\n");
    printf("│ 1. Run All Linked List Tests                 │\n");
    printf("│ 2. Test Create And Destroy List              │\n");
    printf("│ 3. Test Prepend And Append                   │\n");
    printf("│ 4. Test Remove First And Last                │\n");
    printf("│ 5. Test Remove Data                          │\n");
    printf("│ 6. Test Find                                 │\n");
    printf("│ 7. Test Clear                                │\n");
    printf("│ 8. Test For Each                             │\n");
    printf("│ 9. Test List To String And Print             │\n");
    printf("│ 0. Back to Test Main Menu                    │\n");
    printf("╰──────────────────────────────────────────────╯\n");
    printf("\n  -> Choose an option: ");
    scanf("%d", &option);
    getchar();
    switch (option) {
      case 1:
        run_linked_list_tests();
        break;
      case 2:
        test_create_and_destroy_list();
        break;
      case 3:
        test_prepend_and_append();
        break;
      case 4:
        test_remove_first_and_last();
        break;
      case 5:
        test_remove_data();
        break;
      case 6:
        test_find();
        break;
      case 7:
        test_clear();
        break;
      case 8:
        test_for_each();
        break;
      case 9:
        test_list_to_string_and_print();
        break;
      case 0:
        break;
      default:
        printf("Invalid option.\n");
    }
  } while (option != 0);
}

void persistence_test_menu() {
  int option;
  do {
    printf("\n╭── Persistence Test Menu ─────────────────────╮\n");
    printf("│ 1. Run All Persistence Tests                 │\n");
    printf("│ 2. Test Save And Load Students               │\n");
    printf("│ 3. Test Save And Load Subjects               │\n");
    printf("│ 0. Back to Test Main Menu                    │\n");
    printf("╰──────────────────────────────────────────────╯\n");
    printf("\n  -> Choose an option: ");
    scanf("%d", &option);
    getchar();
    switch (option) {
      case 1:
        run_persistence_tests();
        break;
      case 2:
        test_save_and_load_students();
        break;
      case 3:
        test_save_and_load_subjects();
        break;
      case 0:
        break;
      default:
        printf("Invalid option.\n");
    }
  } while (option != 0);
}

void search_test_menu() {
  int option;
  do {
    printf("\n╭── Search Test Menu ──────────────────────────╮\n");
    printf("│ 1. Run All Search Tests                      │\n");
    printf("│ 2. Test Find Students By Name (Found)        │\n");
    printf("│ 3. Test Find Students By Name (Not Found)    │\n");
    printf("│ 4. Test Find Students By Age Range (Found)   │\n");
    printf("│ 5. Test Find Students By Age Range (None)    │\n");
    printf("│ 6. Test Get Student By ID                    │\n");
    printf("│ 7. Test Get Subject By ID                    │\n");
    printf("│ 0. Back to Test Main Menu                    │\n");
    printf("╰──────────────────────────────────────────────╯\n");
    printf("\n  -> Choose an option: ");
    scanf("%d", &option);
    getchar();
    switch (option) {
      case 1:
        run_search_tests();
        break;
      case 2:
        test_find_students_by_name_found();
        break;
      case 3:
        test_find_students_by_name_not_found();
        break;
      case 4:
        test_find_students_by_age_range_found();
        break;
      case 5:
        test_find_students_by_age_range_not_found();
        break;
      case 6:
        test_get_student_by_id();
        break;
      case 7:
        test_get_subject_by_id();
        break;
      case 0:
        break;
      default:
        printf("Invalid option.\n");
    }
  } while (option != 0);
}

void student_test_menu() {
  int option;
  do {
    printf("\n╭── Student Test Menu ─────────────────────────╮\n");
    printf("│ 1. Run All Student Tests                     │\n");
    printf("│ 2. Test Create Student                       │\n");
    printf("│ 3. Test Student To String                    │\n");
    printf("│ 4. Test Compare Student By ID And Name       │\n");
    printf("│ 0. Back to Test Main Menu                    │\n");
    printf("╰──────────────────────────────────────────────╯\n");
    printf("\n  -> Choose an option: ");
    scanf("%d", &option);
    getchar();
    switch (option) {
      case 1:
        run_student_tests();
        break;
      case 2:
        test_create_student();
        break;
      case 3:
        test_student_to_string();
        break;
      case 4:
        test_compare_student_by_id_and_name();
        break;
      case 0:
        break;
      default:
        printf("Invalid option.\n");
    }
  } while (option != 0);
}

void subject_test_menu() {
  int option;
  do {
    printf("\n╭── Subject Test Menu ─────────────────────────╮\n");
    printf("│ 1. Run All Subject Tests                     │\n");
    printf("│ 2. Test Create Subject                       │\n");
    printf("│ 3. Test Correlatives List                    │\n");
    printf("│ 4. Test Subject To String                    │\n");
    printf("│ 5. Test Compare Subject By ID                │\n");
    printf("│ 0. Back to Test Main Menu                    │\n");
    printf("╰──────────────────────────────────────────────╯\n");
    printf("\n  -> Choose an option: ");
    scanf("%d", &option);
    getchar();
    switch (option) {
      case 1:
        run_subject_tests();
        break;
      case 2:
        test_create_subject();
        break;
      case 3:
        test_correlatives_list();
        break;
      case 4:
        test_subject_to_string();
        break;
      case 5:
        test_compare_subject_by_id();
        break;
      case 0:
        break;
      default:
        printf("Invalid option.\n");
    }
  } while (option != 0);
}

void enroll_and_grade(Student *s, CircularList *subjects, CircularList *allSubjects) {
  DoubleLinkedNode *node = subjects->head;
  if (!node) {
    return;
  }
  do {
    Subject *subject = (Subject *)node->data;
    if (can_enroll(s, subject, allSubjects)) {
      enroll_student(s, subject, allSubjects);
      float grade = (float)(6 + rand() % 5);
      record_exam(s, subject->id, grade);
    }
    node = node->next;
  } while (node != subjects->head);
}

void generate_sample_data(CircularList *students, CircularList *subjects, int count) {
  const char *names[] = {"Juan", "Ana", "Carlos", "Lucía", "Marcos"};
  const char *subject_names[] = {"Matemática", "Historia", "Física", "Programación", "Química"};
  for (int i = 0; i < count; i++) {
    Student *s = create_student(names[i % 5], 18 + rand() % 10);
    s->id = generate_unique_id();
    append(students, s);
  }
  for (int i = 0; i < count; i++) {
    Subject *subj = create_subject(subject_names[i % 5], 4 + rand() % 3);
    subj->id = generate_unique_id();
    append(subjects, subj);
  }
  for (int i = 1; i < count; i++) {
    Subject *subject = get_subject_by_id(subjects, i + 1);
    Subject *prev = get_subject_by_id(subjects, i);
    if (subject && prev) {
      append(subject->correlatives, prev);
    }
  }
  DoubleLinkedNode *node = students->head;
  if (!node) {
    return;
  }
  do {
    Student *s = (Student *)node->data;
    enroll_and_grade(s, subjects, subjects);
    node = node->next;
  } while (node != students->head);
}

void show_statistics(CircularList *students, CircularList *subjects) {
  printf("\n─── Student Rankings by Average ───\n");
  sort_students_by_average(students);
  int shown = 0;
  DoubleLinkedNode *node = students->head;
  if (!node) {
    return;
  }
  do {
    Student *s = (Student *)node->data;
    printf("• %s (avg: %.2f)\n", s->name, s->average);
    shown++;
    if (shown >= 3) {
      break;
    }
    node = node->next;
  } while (node != students->head);
  printf("\n─── Subjects with Most Correlatives ───\n");
  int maxCorrelatives = 0;
  Subject *mostDemanding = NULL;
  node = subjects->head;
  if (!node) {
    return;
  }
  do {
    Subject *s = (Subject *)node->data;
    int count = get_size(s->correlatives);
    if (count > maxCorrelatives) {
      maxCorrelatives = count;
      mostDemanding = s;
    }
    node = node->next;
  } while (node != subjects->head);
  if (mostDemanding) {
    printf("• %s (requires %d subject(s))\n", mostDemanding->name, maxCorrelatives);
  } else {
    printf("• No subjects with correlatives.\n");
  }
}