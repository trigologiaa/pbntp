#ifndef STUDENT_H
#define STUDENT_H
#include "../include/linked_list.h"
#include "../include/student_subject.h"
#define NAME_LEN 100

/**
 * 
 */
typedef struct Student {
    int             id;             //<
    char            name[NAME_LEN]; //< 
    int             age;            //<
    CircularList    *subjects;      //<
} Student;

/**
 * @brief Creates a new Student instance.
 * 
 * @param id The student's ID.
 * @param name The student's name.
 * @param average The student's average grade.
 * 
 * @return A pointer to a dynamically allocated Student, or NULL on failure.
 */
Student *createStudent(int id, const char *name, float age);

/**
 * @brief Prints a Student's data (for use with printList).
 * 
 * @param data A void pointer expected to point to a Student.
 */
void printStudent(void *data);

/**
 * @brief Frees a Student instance.
 * 
 * @param student A pointer to the Student to be freed.
 */
void destroyStudent(Student *student);

#endif