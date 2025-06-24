#include "../include/enrollment.h"
#include "../include/linked_list.h"
#include "../include/student.h"
#include "../include/subject.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief Creates a new subject enrollment instance.
 *
 * Allocates dynamic memory for a new SubjectEnrollment structure, sets the
 * subject ID, initializes the `passed` flag to false, and assings an initial
 * grade of -1.
 *
 * @param subjectId The id of the subject for which the enrollment is created.
 *
 * @return A pointer to the newly allocated SubjectEnrollment, or NULL if memory
 * allocation fails.
 */
SubjectEnrollment *create_enrollment(int subjectId) {
  SubjectEnrollment *e = malloc(sizeof(SubjectEnrollment));
  if (!e) {
    return NULL;
  }
  e->subjectId = subjectId;
  e->passed = false;
  e->grade = -1.0f;
  return e;
}

/**
 * @brief Frees the memory associated with an enrollment.
 *
 * Deallocates the memory previously allocated for a SubjectEnrollment.
 *
 * @param enrollment A pointer to the SubjectEnrollment to be destroyed.
 */
void destroy_enrollment(void *enrollment) {
  if (enrollment) {
    free(enrollment);
  }
}

/**
 * @brief Determines if a student can enroll in a given subject.
 *
 * Checks whether the student has passed all the correlatives (prerequisites)
 * required for the given subject. If the subject has no correlative, the
 * student is allowed to enroll.
 *
 * @param student A pointer to the Student.
 * @param subject A pointer to the Subject the student wishes to enroll in.
 * @param allSubjects A list containing all subjects (not used in current
 * implementation but reserved for context).
 *
 * @return true if the student meets the prerequisites, false otherwise.
 */
bool can_enroll(Student *student, Subject *subject, CircularList *allSubjects) {
  if (!student || !subject) {
    return false;
  }
  CircularList *correlatives = subject->correlatives;
  if (isEmpty(correlatives)) {
    return true;
  }
  bool has_all = true;
  DoubleLinkedNode *node = correlatives->head;
  do {
    int *correlativeId = (int *)node->data;
    bool passed = false;
    DoubleLinkedNode *en = student->enrollments->head;
    do {
      SubjectEnrollment *enrollment = (SubjectEnrollment *)en->data;
      if (enrollment->subjectId == *correlativeId && enrollment->passed) {
        passed = true;
        break;
      }
      en = en->next;
    } while (en != student->enrollments->head);
    if (!passed) {
      has_all = false;
      break;
    }
    node = node->next;
  } while (node != correlatives->head);
  return has_all;
}

/**
 * @brief Enrolls a student in a subject if eligible.
 *
 * Verifies that the student is not already enrolled in the subject, and meets
 * the necessary prerequisites. If so, a new enrollment is created and added to
 * the student's list of enrollments.
 *
 * @param student A pointer to the Student.
 * @param subject A pointer to the Subject.
 * @param A list of all available subjects.
 *
 * @return true if the student was successfully enrolled, false otherwise.
 */
bool enroll_student(Student *student, Subject *subject, CircularList *allSubjects) {
  if (!student || !subject) {
    return false;
  }
  DoubleLinkedNode *current = student->enrollments->head;
  if (current) {
    do {
      SubjectEnrollment *enrollment = (SubjectEnrollment *)current->data;
      if (enrollment->subjectId == subject->id) {
        return false;
      }
      current = current->next;
    } while (current != student->enrollments->head);
  }
  if (!can_enroll(student, subject, allSubjects)) {
    return false;
  }
  SubjectEnrollment *enrollment = create_enrollment(subject->id);
  if (!enrollment) {
    return false;
  }
  append(student->enrollments, enrollment);
  return true;
}

/**
 * @brief Records the grade of a student for a specific subject.
 *
 * Searches the student's enrollments for the given subject and updates the
 * grade and passed status. A grade of 6.0 or higher is considered passing.
 *
 * @param student A pointer to the Student.
 * @param subjectId The ID of the subject.
 * @param grade The grade obtained in the exam (must be betweeen 0.0 and 10.0).
 *
 * @return true if the grade was recorded successfully, false otherwise.
 */
bool record_exam(Student *student, int subjectId, float grade) {
  if (!student || grade < 0.0f || grade > 10.0f) {
    return false;
  }
  DoubleLinkedNode *current = student->enrollments->head;
  if (!current) {
    return false;
  }
  do {
    SubjectEnrollment *enrollment = (SubjectEnrollment *)current->data;
    if (enrollment->subjectId == subjectId) {
      enrollment->subjectId = grade;
      enrollment->passed = grade >= 6.0f;
      return true;
    }
    current = current->next;
  } while (current != student->enrollments->head);
  return false;
}