#ifndef SORTING_H
#define SORTING_H

#include "Student.h"

void swap(int *src, int *dst);
void swapStd(Student *src, Student *dst);

void quickSortStudentsByID(Student students[], int num_students);
void selectionSortStudentsByGPA_ID(Student students[], int num_students);
Student * binarySearchStudentByID(Student students[], int num_students, int st_id);

#endif