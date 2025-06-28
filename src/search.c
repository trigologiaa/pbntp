#include "../include/search.h"
#include "../include/linked_list.h"
#include "../include/student.h"
#include "../include/subject.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Searches for students with a specific name and prints them.
 *
 * Iterates through the list of students and compares each student's name with
 * the given name. If one or more matches are found, their string
 * representations are printed. Otherwise, a message is printed indicating that
 * no match was found.
 *
 * @param students A pointer to a CircularList containing Student elements.
 * @param name The name to search for.
 */
void find_students_by_name(CircularList *students, const char *name) {
  if (!students || !name) {
    return;
  }
  bool found = false;
  DoubleLinkedNode *current = students->head;
  if (!current) {
    return;
  }
  do {
    Student *s = (Student *)current->data;
    if (strcmp(s->name, name) == 0) {
      char *str = student_to_string(s);
      printf("%s\n", str);
      free(str);
      found = true;
    }
    current = current->next;
  } while (current != students->head);
  if (!found) {
    printf("No student found with name: %s\n", name);
  }
}

/**
 * @brief Finds and prints students whose age falls within a given range.
 *
 * Iterates through the list of students and prints those whose age is between
 * `minAge` and `maxAge` (inclusive). If no students match, a message is printed
 * indicating that no matches were found.
 *
 * @param students A pointer to a CircularList containing Student elements.
 * @param minAge The minimum age to include.
 * @param maxAge The maximum age to include.
 */
void find_students_by_age_range(CircularList *students, int minAge, int maxAge) {
  if (!students) {
    return;
  }
  bool found = false;
  DoubleLinkedNode *current = students->head;
  if (!current) {
    return;
  }
  do {
    Student *s = (Student *)current->data;
    if (s->age >= minAge && s->age <= maxAge) {
      char *str = student_to_string(s);
      printf("%s\n", str);
      free(str);
      found = true;
    }
    current = current->next;
  } while (current != students->head);
  if (!found) {
    printf("No students found in age range %d - %d.\n", minAge, maxAge);
  }
}

/**
 * @brief Retrieves a student by their ID.
 *
 * Searches through the student list and returns a pointer to the Student with
 * the specified ID. If no such student exists, returns NULL.
 *
 * @param students A pointer to a CircularList containing Student elements.
 * @param id The ID of the student to search for.
 *
 * @return A pointer to the matching Student, or NULL if not found.
 */
Student *get_student_by_id(CircularList *students, int id) {
  if (!students) {
    return NULL;
  }
  DoubleLinkedNode *current = students->head;
  if (!current) {
    return NULL;
  }
  do {
    Student *s = (Student *)current->data;
    if (s->id == id) {
      return s;
    }
    current = current->next;
  } while (current != students->head);
  return NULL;
}

/**
 * @brief Retrieves a subject by its ID.
 *
 * Searches through the subject list and returns a pointer to the Subject with
 * the specified ID. If no such subject exists, returns NULL.
 *
 * @param subjects A pointer to a CircularList containing Subject elements.
 * @param id The ID of the subject to search for.
 *
 * @return A pointer to the matching Subject, or NULL if not found.
 */
Subject *get_subject_by_id(CircularList *subjects, int id) {
  if (!subjects) {
    return NULL;
  }
  DoubleLinkedNode *current = subjects->head;
  if (!current) {
    return NULL;
  }
  do {
    Subject *s = (Subject *)current->data;
    if (s->id == id) {
      return s;
    }
    current = current->next;
  } while (current != subjects->head);
  return NULL;
}
