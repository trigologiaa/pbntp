#ifndef STUDENT_H

#define STUDENT_H

#include "../include/linked_list.h"
#include <stdbool.h>

/**
 * @brief Structure representing a student.
 *
 * Contains basic student information such as ID, name, age, average grade, and
 * a list of subject enrollments. The list of enrollments is a circular doubly
 * linked list storing SubjectEnrollment records.
 */
typedef struct Student {
  int id;         // Unique identifier for the student (auto-incremented).
  char name[100]; // Student's name.
  int age;        // Student's age.
  float average;  // Student's average grade across subjects.
  CircularList *enrollments; // List of the student's subject enrollments.
} Student;

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
Student *create_student(const char *name, int age);

/**
 * @brief Frees the memory associated with a Student.
 *
 * Deallocates the memory used by the student, including the list of enrollments
 * and its elements.
 *
 * @param student A pointer to the Student to be destroyed.
 */
void destroy_student(void *student);

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
char *student_to_string(void *student);

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
bool compare_student_by_id(void *a, void *b);

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
bool compare_student_by_name(void *a, void *b);

#endif
