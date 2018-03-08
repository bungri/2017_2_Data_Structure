#include "Sorting.h"

void swap(int *src, int *dst)
{
	int temp = *src;
	*src = *dst;
	*dst = temp;
}

void swapStd(Student *src, Student *dst)
{
	Student temp = *src;
	*src = *dst;
	*dst = temp;
}

void quickSortStudentsByID(Student students[], int num_students)
{
	//sorts the given array of students in increasing order of ID.Using the printStudents()
	//print out the array of sorted array of students.

	if (num_students <= 1)	//���̻� sorting �� �׸��� ����!
	{
		return;
	}
	int right = num_students - 1;
	int storeIndex = 0;
	int pivotValue = students[right / 2].st_id;
	swapStd(students + right / 2, students + right);	//������� pivotIndex�� ��� right ���� ���� �� pivotValue ����

	if (num_students > 1)
	{
		for (int left = 0; left < num_students; left++)
		{
			if (students[left].st_id < pivotValue) {
				if (left == storeIndex)	//storeIndex�� left�� ���ٸ� swap�� �ϴ� ���� �޸� ����!
				{
					storeIndex++;
					continue;
				}
				swapStd(students + left, students + storeIndex);	//left�� pivotVale���� �۴ٸ� storeIndex�� ���� �� storeIndex 1 ����
				storeIndex++;
			}
		}
		swapStd(students + storeIndex, students + right);	//������� ����
	}
	quickSortStudentsByID(students, storeIndex);	//recursive call - ���� / cut �� �迭�� ������ �ִ밪�� cut �ؼ� �Լ� ȣ��
	quickSortStudentsByID(students + (storeIndex + 1), num_students - (storeIndex + 1));	//sorting�� �Ϸ�� ���� �迭�� �߶󳻰� ������ �迭�� �μ��� ����

}

void selectionSortStudentsByGPA_ID(Student students[], int num_students)
{
	//sorts the given array of students in decreasing order of GPA.For the  GPA score
	//sort in increasing order of ID.Using the printArrayOfStudents()
	//print out the array of sorted array of students.

	int temp, maxV;
	for (int i = 0; i < num_students; i++)
	{
		maxV = i;	//ù��° ���� maxValue�� ����

		for (int j = i + 1; j < num_students; j++)
		{
			if (students[j].GPA > students[maxV].GPA)	//j �ε����� GPA ���� maxValue���� ũ�� maxValue�� �ε����� j�� ����
			{
				maxV = j;
			}
		}

		if (maxV != i)	//i �ε����� �ִ밪�� �ƴ϶�� ���� ����
			swapStd(students + i, students + maxV);
	}
}

Student * binarySearchStudentByID(Student students[], int num_students, int st_id)
{
	//that searches the given student of st_id from the array of students using binary search
	//and returns the pointer to the student.Using printStudent(),printout the result.

	int low = 0, high = num_students - 1, mid;
	while (low <= high)	//Ž���� ���ڰ� ���� �ִٸ� Ž�� ����
	{
		mid = (low + high) / 2;
		if (st_id == students[mid].st_id)
			return students + mid;	//Ž�� ����, ����� ��ȯ
		else if (students[mid].st_id > st_id)	//mid������ Ž���� ���� �� ũ�ٸ� mid - 1 ������ high ����
			high = mid - 1;
		else //mid ������ Ž���� ���� �� �۴ٸ� mid + 1 ������ low ����
			low = mid + 1;
	}
	return 0;
}