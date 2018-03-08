#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Student.h"

void initStudents(Student students[], int student_id[], int num_students)
{
	/* which receives an array of struct Student, an array of student_ids, and the number of students.
	This function initializes the attributes of Student.
	The provided array student_ids contains non-duplicated integer number.
	The length of name is 5 ~ 15. The first	letter of name should be capital letter (¡®A¡¯ ~ ¡®Z¡¯),
	while the other letters are lower case letter (¡®a¡¯~ ¡®z¡¯).
	The department is composed of 3 ~ 5 capital letters.
	The grade is 1 ~ 8, and gpa is a double type value in the range of 0.00 ~ 99.99. */

	for (int i = 0; i < num_students; i++)
	{
		//set st_id
		students[i].st_id = student_id[i];

		//set name
		int nameLength = rand() % 11 + 5;		//prevent nameLength set as 0
		for (int j = 0; j <= nameLength; j++)
		{
			if (j == nameLength)
			{
				students[i].name[j] = '\0';
			}
			else if (j == 0)
			{
				students[i].name[j] = (char)(rand() % 26 + 'A');
			}
			else
			{
				students[i].name[j] = (char)(rand() % 26 + 'a');
			}
		}//end-for

		//set department
		int depLength = rand() % 3 + 3;	//prevent depLength set as 0
		for (int j = 0; j <= depLength; j++)
		{
			if (j == depLength)
			{
				students[i].department[j] = '\0';
			}
			else
			{
				students[i].department[j] = (char)(rand() % 26 + 'A');
			}
		}//end-for

		//set grade
		students[i].grade = rand() % 8 + 1;

		//set GPA
		students[i].GPA = rand() % 100 + (double)rand() / 32767;

	}//end-for
}

void printStudent(Student *pSt)
{
	//prints out the attributes of the given student(st_id, last_name, first_name, department, grade, and GPA).
	printf("Student (ID : %5d, Name : %15s, department : %5s, grade : %2d, GPA : %5.2f)", pSt->st_id, pSt->name, pSt->department, pSt->grade, pSt->GPA);
	
}

void printStudentArr(Student *pSt)
{
	//prints out the attributes of the given student(st_id, last_name, first_name, department, grade, and GPA).
	for (int i = 0; i < 10; i++)
	{
		printStudent(pSt + i);
		printf("\n");
	}
	printf(". . . . .\n");
	
}

void printStudents(Student students[], int num_students)
{
	for (int i = 0; i < num_students; i++)
	{
		printStudent(students + i);
	}
}

void printStudentID(Student students[], int num_students)
{
	//prints out the st_id of the given student.
	for (int i = 0; i < num_students; i++)
	{
		printf("%5d", students[i].st_id);
		if ((i + 1) % 20 == 0) {
			printf("\n");
		}
	}
}

void printStudentGPA_ID(Student students[], int num_students)
{
	//that prints out the (GPA, st_id) of the given student.
	for (int i = 0; i < num_students; i++)
	{
		printf("(%5.2f,%5d) ", students[i].GPA, students[i].st_id);
		if ((i + 1) % 10 == 0) {
			printf("\n");
		}
	}
}

void printBigArrayOfStudent_IDs(Student *pSt, int num_students, int num_print_block)
{
	printStudentID(pSt, num_print_block);
	printf(". . . . .\n");
	printStudentID(pSt+(num_students-num_print_block), num_print_block);
}

void printBigArrayOfStudent_GPA_IDs(Student *pSt, int num_students, int num_print_block)
{
	printStudentGPA_ID(pSt, num_print_block);
	printf(". . . . .\n");
	printStudentGPA_ID(pSt + (num_students - num_print_block), num_print_block);
}
