#include "../include/subject.h"
#include "../include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Creates a new Subject.
 *
 * Allocates memory for a new Subject, assigns a unique ID, copies the name,
 * sets the number of credits, and initializes an empty list of correlatives.
 *
 * @param name The name of the subject.
 * @param credits The number of credits for the subject.
 *
 * @return A pointer to the newly created Subject, or NULL if memory allocation
 * fails.
 */
Subject *create_subject(const char *name, int credits) {
  Subject *subject = malloc(sizeof(Subject));
  if (!subject) {
    return NULL;
  }
  static int id_counter = 1;
  subject->id = id_counter++;
  strncpy(subject->name, name, sizeof(subject->name) - 1);
  subject->name[sizeof(subject->name) - 1] = '\0';
  subject->credits = credits;
  subject->correlatives = create_list();
  return subject;
}

/**
 * @brief Frees the memory associated with a Subject.
 *
 * Destroys the list of correlatives and deallocates the subject structure.
 *
 * @param subject A pointer to the Subject to be destroyed.
 */
void destroy_subject(void *subject) {
  if (!subject) {
    return;
  }
  Subject *s = (Subject *)subject;
  if (s->correlatives) {
    destroy_list(s->correlatives, free);
  }
  free(s);
}

/**
 * @brief Converts a subject to a string representation.
 *
 * Allocates and returns a string containing the subject's ID, name, number of
 * credits, and the number of prerequisite subjects. The caller is responsible
 * for freeing the returned string.
 *
 * @param subject A pointer to the Subject.
 *
 * @return A pointer to the newly allocated string, or NULL if memory allocation
 * fails.
 */
char *subject_to_string(void *subject) {
  if (!subject) {
    return NULL;
  }
  Subject *s = (Subject *)subject;
  char *buffer = malloc(256);
  if (!buffer) {
    return NULL;
  }
  snprintf(buffer, 256, "[ID: %d] %s | Credits: %d | Correlatives: %d", s->id,
           s->name, s->credits, get_size(s->correlatives));
  return buffer;
}

/**
 * @brief Compares two subjects by their IDs.
 *
 * Returns true if both pointers refer to subjects with the same ID.
 *
 * @param a A pointer to the first Subject.
 * @param b A pointer to the second Subject.
 *
 * @return true if both subjects have the same ID, false otherwise.
 */
bool compare_subject_by_id(void *a, void *b) {
  if (!a || !b) {
    return false;
  }
  Subject *s1 = (Subject *)a;
  Subject *s2 = (Subject *)b;
  return s1->id == s2->id;
}
