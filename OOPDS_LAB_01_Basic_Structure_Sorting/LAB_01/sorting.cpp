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

	if (num_students <= 1)	//더이상 sorting 할 항목이 없음!
	{
		return;
	}
	int right = num_students - 1;
	int storeIndex = 0;
	int pivotValue = students[right / 2].st_id;
	swapStd(students + right / 2, students + right);	//가운데값을 pivotIndex로 잡아 right 값과 스왑 후 pivotValue 추출

	if (num_students > 1)
	{
		for (int left = 0; left < num_students; left++)
		{
			if (students[left].st_id < pivotValue) {
				if (left == storeIndex)	//storeIndex와 left가 같다면 swap을 하는 것은 메모리 낭비!
				{
					storeIndex++;
					continue;
				}
				swapStd(students + left, students + storeIndex);	//left가 pivotVale보다 작다면 storeIndex와 스왑 후 storeIndex 1 증가
				storeIndex++;
			}
		}
		swapStd(students + storeIndex, students + right);	//원래대로 스왑
	}
	quickSortStudentsByID(students, storeIndex);	//recursive call - 왼쪽 / cut 할 배열이 없으니 최대값만 cut 해서 함수 호출
	quickSortStudentsByID(students + (storeIndex + 1), num_students - (storeIndex + 1));	//sorting이 완료된 왼쪽 배열은 잘라내고 오른쪽 배열만 인수로 전달

}

void selectionSortStudentsByGPA_ID(Student students[], int num_students)
{
	//sorts the given array of students in decreasing order of GPA.For the  GPA score
	//sort in increasing order of ID.Using the printArrayOfStudents()
	//print out the array of sorted array of students.

	int temp, maxV;
	for (int i = 0; i < num_students; i++)
	{
		maxV = i;	//첫번째 값을 maxValue로 잡음

		for (int j = i + 1; j < num_students; j++)
		{
			if (students[j].GPA > students[maxV].GPA)	//j 인덱스의 GPA 값이 maxValue보다 크면 maxValue의 인덱스를 j로 설정
			{
				maxV = j;
			}
		}

		if (maxV != i)	//i 인덱스가 최대값이 아니라면 스왑 수행
			swapStd(students + i, students + maxV);
	}
}

Student * binarySearchStudentByID(Student students[], int num_students, int st_id)
{
	//that searches the given student of st_id from the array of students using binary search
	//and returns the pointer to the student.Using printStudent(),printout the result.

	int low = 0, high = num_students - 1, mid;
	while (low <= high)	//탐색할 숫자가 남아 있다면 탐색 실행
	{
		mid = (low + high) / 2;
		if (st_id == students[mid].st_id)
			return students + mid;	//탐색 성공, 결과물 반환
		else if (students[mid].st_id > st_id)	//mid값보다 탐색할 값이 더 크다면 mid - 1 값으로 high 설정
			high = mid - 1;
		else //mid 값보다 탐색할 값이 더 작다면 mid + 1 값으로 low 설정
			low = mid + 1;
	}
	return 0;
}