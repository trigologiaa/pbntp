#ifndef ENROLLMENT_H

#define ENROLLMENT_H

#include "../include/linked_list.h"
#include "../include/student.h"
#include "../include/subject.h"

/**
 * @brief Structure representing a student's enrollment in a subject.
 *
 * Contains the subject's identifier (`subjectId`), a flag indicating whether
 * the subject was passed (`passed`), and the grade obtained (`grade`). Used to
 * track a student's academic progress in individual subjects.
 */
typedef struct SubjectEnrollment {
  int subjectId; // Unique identifier of the subject.
  bool passed;   // Indicates whether the student passed the subject.
  float grade;   // Grade obtained. Initialized to -1 if not yet assigned.
} SubjectEnrollment;

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
SubjectEnrollment *create_enrollment(int subjectId);

/**
 * @brief Frees the memory associated with an enrollment.
 *
 * Deallocates the memory previously allocated for a SubjectEnrollment.
 *
 * @param enrollment A pointer to the SubjectEnrollment to be destroyed.
 */
void destroy_enrollment(void *enrollment);

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
bool can_enroll(Student *student, Subject *subject, CircularList *allSubjects);

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
bool enroll_student(Student *student, Subject *subject,
                    CircularList *allSubjects);

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
bool record_exam(Student *student, int subjectId, float grade);

#endif
