#ifndef STUDENT_SUBJECT_H
#define STUDENT_SUBJECT_H
#include "../include/subject.h"

typedef struct StudentSubject {
    Subject *subject;
    float   grade;
    int     passed;
} StudentSubject;

StudentSubject *createStudentSubject(Subject *subject);

void destroyStudentSubject(StudentSubject *ss);

char *studentSubjectToString(void *data);

#endif