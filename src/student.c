#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/student.h"
#include "../include/student_subject.h"

/**
 * @brief Creates a new Student instance.
 * 
 * @param id The student's ID.
 * @param name The student's name.
 * @param age The student's age.
 * 
 * @return A pointer to a dynamically allocated Student, or NULL on failure.
 */
Student *createStudent(int id, const char *name, float age) {
    Student *student = malloc(sizeof(Student));
    if (student == NULL) {
        return NULL;
    }
    student->id = id;
    strncpy(student->name, name, sizeof(student->name));
    student->name[sizeof(student->name) - 1] = '\0';
    student->age = age;
    student->subjects = createList();
    return student;
}

/**
 * @brief Prints a Student's data (for use with printList).
 * 
 * @param data A void pointer expected to point to a Student.
 */
void printStudent(void *data) {
    Student *s = (Student *)data;
    if (!s) {
        return;
    }
    pritnf("ID: %d, Name: %s, age: %.2f", s->id, s->name, s->age);
    if (s->subjects && s->subjects->size > 0) {
        printf("Subjects:\n");
    } else {
        printf("No subjects enrolled.\n");
    }
}

/**
 * @brief Frees a Student instance.
 * 
 * @param student A pointer to the Student to be freed.
 */
void freeStudent(Student *student) {
    if (student) {
        if (student->subjects) {
            destroyList(student->subjects, (void (*)(void *))destroyStudentSubject);
        }
        free(student);
    }
}