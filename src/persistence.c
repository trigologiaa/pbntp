#include "../include/persistence.h"
#include "../include/enrollment.h"
#include "../include/linked_list.h"
#include "../include/student.h"
#include "../include/subject.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
bool save_students_to_csv(CircularList *students, const char *filename) {
  if (!students || !filename) {
    return false;
  }
  char path[256];
  snprintf(path, sizeof(path), "data/%s", filename);
  FILE *f = fopen(path, "w");
  if (!f) {
    return false;
  }
  fprintf(f, "id,name,age,average,enrolled_subject_ids\n");
  DoubleLinkedNode *node = students->head;
  if (node) {
    do {
      Student *s = (Student *)node->data;
      char subjectIds[512] = "";
      DoubleLinkedNode *e = s->enrollments->head;
      if (e) {
        do {
          SubjectEnrollment *enroll = (SubjectEnrollment *)e->data;
          char idStr[16];
          sprintf(idStr, "%d;", enroll->subjectId);
          strcat(subjectIds, idStr);
          e = e->next;
        } while (e != s->enrollments->head);
      }
      fprintf(f, "%d,%s,%d,%.2f,%s\n", s->id, s->name, s->age, s->average,
              subjectIds);
      node = node->next;
    } while (node != students->head);
  }
  fclose(f);
  return true;
}

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
bool load_students_from_csv(CircularList *students, const char *filename) {
  if (!students || !filename) {
    return false;
  }
  char path[256];
  snprintf(path, sizeof(path), "data/%s", filename);
  FILE *f = fopen(path, "r");
  if (!f) {
    return false;
  }
  char line[1024];
  fgets(line, sizeof(line), f);
  while (fgets(line, sizeof(line), f)) {
    Student *s = malloc(sizeof(Student));
    s->enrollments = create_list();
    char subjectsRaw[512];
    sscanf(line, "%d,%49[^,],%d,%f,%511[^\n]", &s->id, s->name, &s->age,
           &s->average, subjectsRaw);
    char *token = strtok(subjectsRaw, ";");
    while (token) {
      int subId = atoi(token);
      SubjectEnrollment *e = create_enrollment(subId);
      append(s->enrollments, e);
      token = strtok(NULL, ";");
    }
    append(students, s);
  }
  fclose(f);
  return true;
}

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
bool save_subjects_to_csv(CircularList *subjects, const char *filename) {
  if (!subjects || !filename) {
    return false;
  }
  char path[256];
  snprintf(path, sizeof(path), "data/%s", filename);
  FILE *f = fopen(path, "w");
  if (!f) {
    return false;
  }
  fprintf(f, "id,name,credits,correlative_ids\n");
  DoubleLinkedNode *node = subjects->head;
  if (node) {
    do {
      Subject *s = (Subject *)node->data;
      char correlativeStr[512] = "";
      DoubleLinkedNode *c = s->correlatives->head;
      if (c) {
        do {
          int *cid = (int *)c->data;
          char temp[16];
          sprintf(temp, "%d;", *cid);
          strcat(correlativeStr, temp);
          c = c->next;
        } while (c != s->correlatives->head);
      }
      fprintf(f, "%d,%s,%d,%s\n", s->id, s->name, s->credits, correlativeStr);
      node = node->next;
    } while (node != subjects->head);
  }
  fclose(f);
  return true;
}

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
bool load_subjects_from_csv(CircularList *subjects, const char *filename) {
  if (!subjects || !filename) {
    return false;
  }
  char path[256];
  snprintf(path, sizeof(path), "data/%s", filename);
  FILE *f = fopen(path, "r");
  if (!f) {
    return false;
  }
  char line[1024];
  fgets(line, sizeof(line), f);
  while (fgets(line, sizeof(line), f)) {
    Subject *s = malloc(sizeof(Subject));
    s->correlatives = create_list();
    char correlativesRaw[512];
    sscanf(line, "%d,%49[^,],%d,%511[^\n]", &s->id, s->name, &s->credits,
           correlativesRaw);
    char *token = strtok(correlativesRaw, ";");
    while (token) {
      int *cid = malloc(sizeof(int));
      *cid = atoi(token);
      append(s->correlatives, cid);
      token = strtok(NULL, ";");
    }
    append(subjects, s);
  }
  fclose(f);
  return true;
}
