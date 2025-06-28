#include "../include/linked_list.h"
#include "../include/menu.h"
#include "../include/persistence.h"
#include "../include/student.h"
#include "../include/subject.h"
#include <stdio.h>
// #include <windows.h>

int main() {
  // SetConsoleOutputCP(CP_UTF8);
  CircularList *students = create_list();
  CircularList *subjects = create_list();
  load_students_from_csv(students, "students.csv");
  load_subjects_from_csv(subjects, "subjects.csv");
  menu(students, subjects);
  save_students_to_csv(students, "students.csv");
  save_subjects_to_csv(subjects, "subjects.csv");
  destroy_list(students, destroy_student);
  destroy_list(subjects, destroy_subject);
  printf("\nData saved. Goodbye!\n");
  return 0;
}