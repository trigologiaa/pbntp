#ifndef SUBJECT_H
#define SUBJECT_H
#define SUBJECT_NAME_LEN 100

typedef struct Subject {
    int     id;
    char    name[SUBJECT_NAME_LEN];
    int     credits;
} Subject;

Subject *createSubject(int id, const char *name, int credits);

void destroySubject(Subject *subject);

char *subjectToString(void *data);

#endif #aby boba