#include "../include/student.h"
#include "../include/enrollment.h"
#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Creates a new student.
 *
 * Allocates memory for a Student structure, assigns a unique ID, initializes
 * the name, age, average grade, and creates an empty list of enrollments.
 *
 * @param name The name of the student.
 * @param age The age of the student.
 *
 * @return A pointer to the newly created Student, or NULL if memory allocation
 * fails.
 */
Student *create_student(const char *name, int age) {
  Student *s = malloc(sizeof(Student));
  if (!s) {
    return NULL;
  }
  static int id_counter = 1;
  s->id = id_counter++;
  strncpy(s->name, name, sizeof(s->name) - 1);
  s->name[sizeof(s->name) - 1] = '\0';
  s->age = age;
  s->average = 0.0f;
  s->enrollments = create_list();
  return s;
}

/**
 * @brief Frees the memory associated with a Student.
 *
 * Deallocates the memory used by the student, including the list of enrollments
 * and its elements.
 *
 * @param student A pointer to the Student to be destroyed.
 */
void destroy_student(void *student) {
  if (!student) {
    return;
  }
  Student *s = (Student *)student;
  if (s->enrollments) {
    destroy_list(s->enrollments, destroy_enrollment);
  }
  free(s);
}

/**
 * @brief Converts a student to a string representation.
 *
 * Allocates and returns a string containing the student's ID, name, age,
 * average grade, and the number of enrolled subjects. The caller is responsible
 * for freeing the returned string.
 *
 * @param student A pointer to the Student.
 *
 * @return A pointer to the newly allocated string, or NULL if memory allocation
 * fails.
 */
char *student_to_string(void *student) {
  if (!student) {
    return NULL;
  }
  Student *s = (Student *)student;
  char *buffer = malloc(256);
  if (!buffer) {
    return NULL;
  }
  snprintf(buffer, 256, "[ID: %d] Name: %s | Age: %d | Average: %.2f | Subjects: %d", s->id, s->name, s->age, s->average, get_size(s->enrollments));
  return buffer;
}

/**
 * @brief Compares two students by their IDs.
 *
 * Returns true if the two student pointers point to students with the same ID.
 *
 * @param a A pointer to the first Student.
 * @param b A pointer to the second Student.
 *
 * @return true if both students have the same ID, false otherwise.
 */
bool compare_student_by_id(void *a, void *b) {
  if (!a || !b) {
    return false;
  }
  Student *s1 = (Student *)a;
  Student *s2 = (Student *)b;
  return s1->id == s2->id;
}

/**
 * @brief Compares two students by their names.
 *
 * Returns true if the names of the two students are equal(case-sensitive).
 *
 * @param a A pointer to the first Student.
 * @param b A pointer to the second Student.
 *
 * @return true if both students have the same name, false otherwise.
 */
bool compare_student_by_name(void *a, void *b) {
  if (!a || !b) {
    return false;
  }
  Student *s1 = (Student *)a;
  Student *s2 = (Student *)b;
  return strcmp(s1->name, s2->name) == 0;
}