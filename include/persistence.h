#ifndef PERSISTENCE_H

#define PERSISTENCE_H

#include "../include/linked_list.h"

/**
 * @brief Saves a list of students to a CSV file.
 *
 * Serializes each student in the list to a line in CSV format including: ID,
 * name, age, average, and a semicolon-separated list of enrolled subject IDs.
 * The file will be overwritten if it already exists.
 *
 * @param students A pointer to a CircularList containing Student elements.
 * @param filename The name of the file to save to.
 *
 * @return true if the operation was successful, false otherwise.
 */
bool save_students_to_csv(CircularList *students, const char *filename);

/**
 * @brief Loads students from a CSV file into a list.
 *
 * Parses a CSV file where each line contains: ID, name, age, average, and a
 * semicolon-separated list of enrolled subject IDs. For each line, a new
 * Student is created and added to the given list.
 *
 * @param students A pointer to a CircularList where students will be appended.
 * @param filename The name of the CSV file to read from.
 *
 * @return true if the file was loaded successfully, false otherwise.
 */
bool load_students_from_csv(CircularList *students, const char *filename);

/**
 * @brief Saves a list of subjects to a CSV file.
 *
 * Serializes each subject in the list to a line in CSV format including: ID,
 * name, credits, and a semicolon-separated list of correlative subject IDs. The
 * file will be overwritten if it already exists.
 *
 * @param subjectss A pointer to a CircularList containing Subject elements.
 * @param filename The name of the file to save to.
 *
 * @return true if the operation was successful, false otherwise.
 */
bool save_subjects_to_csv(CircularList *subjects, const char *filename);

/**
 * @brief Loads subjects from a CSV file into a list.
 *
 * Parses a CSV file where each line contains: ID, name, credits, and a
 * semicolon-separated list of correlative subject IDs. For each line, a new
 * Subject is created and added to the given list.
 *
 * @param subjects A pointer to a CircularList where subjects will be appended.
 * @param filename The name of the CSV file to read from.
 *
 * @return true if the file was loaded successfully, false otherwise.
 */
bool load_subjects_from_csv(CircularList *subjects, const char *filename);

#endif
