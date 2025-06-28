#include "../include/persistence_test.h"
#include "../include/enrollment.h"
#include "../include/persistence.h"
#include "../include/student.h"
#include "../include/subject.h"
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Run all persistence related tests.
 */
void run_persistence_tests() {
  printf("\n-> Running all Persistence tests <-\n");
  test_save_and_load_students();
  test_save_and_load_subjects();
  printf("\n-> Persistence tests passed <-\n");
}

/**
 * @brief Test saving and loading students from CSV.
 */
void test_save_and_load_students() {
  printf("\nRunning test_save_and_load_students()\n");
  CircularList *students = create_list();
  Student *s1 = malloc(sizeof(Student));
  s1->id = 1;
  strcpy(s1->name, "Juan");
  s1->age = 20;
  s1->average = 8.5;
  s1->enrollments = create_list();
  append(s1->enrollments, create_enrollment(101));
  append(s1->enrollments, create_enrollment(102));
  append(students, s1);
  Student *s2 = malloc(sizeof(Student));
  s2->id = 2;
  strcpy(s2->name, "Maria");
  s2->age = 22;
  s2->average = 9.0;
  s2->enrollments = create_list();
  append(s2->enrollments, create_enrollment(103));
  append(students, s2);
  assert(save_students_to_csv(students, "students_test.csv") == true);
  CircularList *loaded_students = create_list();
  assert(load_students_from_csv(loaded_students, "students_test.csv") == true);
  DoubleLinkedNode *node = loaded_students->head;
  assert(node != NULL);
  Student *loaded_s1 = (Student *)node->data;
  assert(loaded_s1->id == 1);
  assert(strcmp(loaded_s1->name, "Juan") == 0);
  assert(loaded_s1->age == 20);
  assert(loaded_s1->average == 8.5);
  assert(loaded_s1->enrollments->size == 2);
  node = node->next;
  Student *loaded_s2 = (Student *)node->data;
  assert(loaded_s2->id == 2);
  assert(strcmp(loaded_s2->name, "Maria") == 0);
  assert(loaded_s2->age == 22);
  assert(loaded_s2->average == 9.0);
  assert(loaded_s2->enrollments->size == 1);
  destroy_list(students, destroy_student);
  destroy_list(loaded_students, destroy_student);
  printf("test_save_and_load_students() test passed\n");
}

/**
 * @brief Test saving and loading subjects from CSV.
 */
void test_save_and_load_subjects() {
  printf("\nRunning test_save_and_load_subjects()\n");
  CircularList *subjects = create_list();
  Subject *sub1 = malloc(sizeof(Subject));
  sub1->id = 101;
  strcpy(sub1->name, "Matematica");
  sub1->credits = 6;
  sub1->correlatives = create_list();
  int *c1 = malloc(sizeof(int));
  *c1 = 100;
  append(sub1->correlatives, c1);
  append(subjects, sub1);
  Subject *sub2 = malloc(sizeof(Subject));
  sub2->id = 102;
  strcpy(sub2->name, "Fisica");
  sub2->credits = 5;
  sub2->correlatives = create_list();
  int *c2 = malloc(sizeof(int));
  *c2 = 100;
  int *c3 = malloc(sizeof(int));
  *c3 = 101;
  append(sub2->correlatives, c2);
  append(sub2->correlatives, c3);
  append(subjects, sub2);
  assert(save_subjects_to_csv(subjects, "subjects_test.csv") == true);
  CircularList *loaded_subjects = create_list();
  assert(load_subjects_from_csv(loaded_subjects, "subjects_test.csv") == true);
  DoubleLinkedNode *node = loaded_subjects->head;
  assert(node != NULL);
  Subject *loaded_sub1 = (Subject *)node->data;
  assert(loaded_sub1->id == 101);
  assert(strcmp(loaded_sub1->name, "Matematica") == 0);
  assert(loaded_sub1->credits == 6);
  assert(loaded_sub1->correlatives->size == 1);
  node = node->next;
  Subject *loaded_sub2 = (Subject *)node->data;
  assert(loaded_sub2->id == 102);
  assert(strcmp(loaded_sub2->name, "Fisica") == 0);
  assert(loaded_sub2->credits == 5);
  assert(loaded_sub2->correlatives->size == 2);
  destroy_list(subjects, destroy_subject);
  destroy_list(loaded_subjects, destroy_subject);
  printf("test_save_and_load_subjects() test passed\n");
}