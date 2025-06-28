#ifndef MENU_H

#define MENU_H

#include "linked_list.h"
#include "student.h"
#include "subject.h"

void menu(CircularList *students, CircularList *subjects);
void students_menu(CircularList *students, CircularList *subjects);
void subjects_menu(CircularList *subjects);
void tests_menu();
void enrollment_test_menu();
void linked_list_test_menu();
void persistence_test_menu();
void search_test_menu();
void student_test_menu();
void subject_test_menu();
void show_statistics(CircularList *students, CircularList *subjects);
void generate_sample_data(CircularList *students, CircularList *subjects,
                          int count);

#endif
