#ifndef STUDENT_H
#define STUDENT_H

typedef struct Student {
	/* struct for Student that includes 5 attributes: 
	   st_id (integer student ID), name (up to 15 characters), department(up to 15 characters), grade(1 ~8), and GPA(double).
	   The struct Student is defined in a separate header file ¡°Student.h¡±.
	   The Student.h header file includes all function prototypes related to structure Student. */

	int st_id;
	char name[16];
	char department[6];
	unsigned int grade : 4;
	double GPA;

} Student;

void initStudents(Student students[], int student_id[], int num_students);
void printStudent(Student *pSt);
void printStudents(Student students[], int num_students);
void printStudentID(Student students[], int num_students);
void printStudentGPA_ID(Student students[], int num_students);

void printStudentArr(Student *pSt);
void printBigArrayOfStudent_IDs(Student *pSt, int num_students, int num_print_block);
void printBigArrayOfStudent_GPA_IDs(Student *pSt, int num_students, int num_print_block);

#endif