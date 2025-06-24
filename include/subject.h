#ifndef SUBJECT_H

#define SUBJECT_H

#include "../include/linked_list.h"

/**
 * @brief Structure representing a subject in the academic system.
 *
 * Each subject has a unique ID, a name, a number of credits, and an optional
 * list of correlatives (prerequisite subject IDs stored in a circular doubly
 * linked list).
 */
typedef struct Subject {
  int id;         // Unique identifier for the subject (auto-incremented).
  char name[100]; // Name of the subject.
  int credits;    // Number of credits assigned to the subject.
  CircularList *correlatives; // List of prerequisite subjects (as integers).
} Subject;

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
Subject *create_subject(const char *name, int credits);

/**
 * @brief Frees the memory associated with a Subject.
 *
 * Destroys the list of correlatives and deallocates the subject structure.
 *
 * @param subject A pointer to the Subject to be destroyed.
 */
void destroy_subject(void *subject);

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
char *subject_to_string(void *subject);

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
bool compare_subject_by_id(void *a, void *b);

#endif