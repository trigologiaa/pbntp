#include "../include/enrollment.h"
#include "../include/linked_list.h"
#include "../include/persistence.h"
#include "../include/search.h"
#include "../include/student.h"
#include "../include/subject.h"
#include "../include/system_utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void menu(CircularList *students, CircularList *subjects);
void studentsMenu(CircularList *students, CircularList *subjects);
void subjectsMenu(CircularList *subjects);
void show_statistics(CircularList *students, CircularList *subjects);
void generate_sample_data(CircularList *students, CircularList *subjects, int count);

int main() {
  CircularList *students = createList();
  CircularList *subjects = createList();
  load_students_from_csv(students, "students.csv");
  load_subjects_from_csv(subjects, "subjects.csv");
  menu(students, subjects);
  save_students_to_csv(students, "students.csv");
  save_subjects_to_csv(subjects, "subjects.csv");
  destroyList(students, destroy_student);
  destroyList(subjects, destroy_subject);
  printf("\nData saved. Goodbye!\n");
  return 0;
}

void menu(CircularList *students, CircularList *subjects) {
  int option;
  do {
    printf("\n╭──────────── Main Menu ────────────╮\n");
    printf("│  1. Manage students               │\n");
    printf("│  2. Manage subjects               │\n");
    printf("│  3. Show statistics               │\n");
    printf("│  4. Generate test data            │\n");
    printf("│  0. Exit                          │\n");
    printf("╰───────────────────────────────────╯\n");
    printf("\n  -> Choose an option: ");
    scanf("%d", &option);
    getchar();
    switch (option) {
    case 1:
      studentsMenu(students, subjects);
      break;
    case 2:
      subjectsMenu(subjects);
      break;
    case 3:
      show_statistics(students, subjects);
      press_enter_to_continue();
      break;
    case 4:
      generate_sample_data(students, subjects, 5);
      printf("Test data created.\n");
      press_enter_to_continue();
      break;
    case 0:
      break;
    default:
      printf("Invalid option.\n");
    }
  } while (option != 0);
}

void studentsMenu(CircularList *students, CircularList *subjects) {
  int option;
  do {
    printf("\n╭──────────── Students Menu ─────────────╮\n");
    printf("│ 1. Register new student                │\n");
    printf("│ 2. Modify student                      │\n");
    printf("│ 3. Delete student                      │\n");
    printf("│ 4. List all students                   │\n");
    printf("│ 5. Enroll in subject                   │\n");
    printf("│ 6. Record exam                         │\n");
    printf("│ 7. Search students by name             │\n");
    printf("│ 8. Search students by age range        │\n");
    printf("│ 0. Back to main menu                   │\n");
    printf("╰────────────────────────────────────────╯\n");
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
      if (student && removeData(students, student, compare_student_by_id)) {
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

void subjectsMenu(CircularList *subjects) {
  int option;
  do {
    printf("\n╭──────────── Subjects Menu ─────────────╮\n");
    printf("│ 1. Create new subject                  │\n");
    printf("│ 2. Modify subject                      │\n");
    printf("│ 3. Delete subject                      │\n");
    printf("│ 4. List all subjects                   │\n");
    printf("│ 0. Back to main menu                   │\n");
    printf("╰────────────────────────────────────────╯\n");
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
      if (subject && removeData(subjects, subject, compare_subject_by_id)) {
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

void enroll_and_grade(Student *s, CircularList *subjects, CircularList *allSubjects) {
  DoubleLinkedNode *node = subjects->head;
  if (!node)
    return;
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
    int count = getSize(s->correlatives);
    if (count > maxCorrelatives) {
      maxCorrelatives = count;
      mostDemanding = s;
    }
    node = node->next;
  } while (node != subjects->head);
  if (mostDemanding) {
    printf("• %s (requires %d subject(s))\n", mostDemanding->name,
           maxCorrelatives);
  } else {
    printf("• No subjects with correlatives.\n");
  }
}