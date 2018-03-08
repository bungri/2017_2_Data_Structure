/********************************************************************
 * 21411947 ������
 * LAB 01
 * Struct of Student Sorting and Searching Arrays of Students
 ********************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Student.h"
#include "Sorting.h"

#define NUM_STUDENTS 5000
#define NUM_SEARCH 5
#define NUM_FIRST_LAST_BLOCK 100

void genBigRandArray(int randArray[], int num_rands);

void main()
{
	int *student_ids;
	Student *students, *pSt;
	int student_search[NUM_SEARCH] = { 1, 123, 999, 2500, 4999 };

	student_ids = (int *)malloc(sizeof(int)* NUM_STUDENTS);
	students = (Student *)malloc(sizeof(Student)* NUM_STUDENTS);

	genBigRandArray(student_ids, NUM_STUDENTS);

	initStudents(students, student_ids, NUM_STUDENTS);
	//printStudentIDs(students, NUM_STUDENTS);

	printf("\n\n");
	printf("Initialized array of students : \n");
	printStudentArr(students);
	//printBigArrayOfStudent_IDs(students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);

	printf("\n\n");
	printf("Quick sorting the array of students by non-decreasing order of ID : \n");
	quickSortStudentsByID(students, NUM_STUDENTS);
	printBigArrayOfStudent_IDs(students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);

	printf("\n\n");
	printf("Selection sorting the array of students by (decreasing order of GPA, increasing order of ID) : \n");
	selectionSortStudentsByGPA_ID(students, NUM_STUDENTS); // non-increasing order
	printBigArrayOfStudent_GPA_IDs(students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);

	printf("\n\n");
	printf("Quick sorting the array of students by non-decreasing order of ID : \n");
	quickSortStudentsByID(students, NUM_STUDENTS);
	printBigArrayOfStudent_IDs(students, NUM_STUDENTS, NUM_FIRST_LAST_BLOCK);

	printf("\n\n");
	printf("Searching student with student_ID : \n");

	for (int i = 0; i < NUM_SEARCH; i++)
	{
		pSt = binarySearchStudentByID(students, NUM_STUDENTS, student_search[i]);
		printf("Student search by ID (%4d) : ", student_search[i]);
		if (pSt != NULL)
			printStudent(pSt);
		else
			printf("NULL - student was not found !!");
		printf("\n");
	}
}

void genBigRandArray(int randArray[], int num_rands)
{
	bool *flag = (bool*)calloc(sizeof(bool), num_rands);
	unsigned int uint_32 = 0;
	unsigned int bigRand = 0;
	int count = 0;

	srand(time(NULL));			//���� �ð��� seed�� ���

	if (flag == NULL)
	{
		printf("�޸� �Ҵ� ����!\n");
		exit(1);
	}

	while (count < num_rands)
	{
		uint_32 = ((long)rand() << 15) | rand();		//15-bit rand short integer�� 15��ŭ shift�� �� �ٽ� bit-wise or ������ ����

		bigRand = uint_32 % num_rands;
		if (flag[bigRand] == true)
		{
			continue;
		}
		else {
			flag[bigRand] = true;
			randArray[count++] = bigRand;
		}
	}

	free(flag);
}