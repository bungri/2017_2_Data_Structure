/* StudentArray.h */

#include "StudentArray.h"

ostream &operator<<(ostream &output, const StudentArray &studArr)
{
	output << "StudentArray (Size : " << studArr.num_students << ")" << endl;
	for (int i = 0; i < studArr.num_students; i++)
		output << studArr[i];
	output << endl;
	return output;
}

StudentArray::StudentArray(int size) // constructor
{
	this->num_students = size;
	students = new Student[size];
}

StudentArray::StudentArray(const StudentArray &obj)
{
	this->num_students = obj.num_students;
	students = new Student[num_students];
	for (int i = 0; i < num_students; i++)
		students[i] = obj.students[i];
}

StudentArray::~StudentArray()
{
	cout << "Destructor for [" << typeid(*this).name() << "], delete (students)" << endl;;
	delete[](this->students);
	students = NULL;
}

Student &StudentArray::operator[](int index) const
{
	if (!isValidIndex(index))
		returnError();
	return students[index];
}

void StudentArray::sortByBirthDate()
{
	Date *dateArr = new Date[num_students];
	for (int i = 0; i < num_students; i++)
		dateArr[i] = students[i].birthDate;
	QuickSort(students, num_students, dateArr);
	delete[] dateArr;
	dateArr = NULL;
}

void StudentArray::sortByName()
{
	string *stringArr = new string[num_students];
	for (int i = 0; i < num_students; i++)
		stringArr[i] = students[i].name;
	QuickSort(students, num_students, stringArr);
	delete[] stringArr;
	stringArr = NULL;
}

void StudentArray::sortByST_ID()
{
	int *idArr = new int[num_students];
	for (int i = 0; i < num_students; i++)
		idArr[i] = students[i].st_id;
	QuickSort(students, num_students, idArr);
	delete[] idArr;
	idArr = NULL;
}

void StudentArray::sortByGPA()
{
	double *gpaArr = new double[num_students];
	for (int i = 0; i < num_students; i++)
		gpaArr[i] = students[i].gpa;
	QuickSort(students, num_students, gpaArr);
	delete[] gpaArr;
	gpaArr = NULL;
}

bool StudentArray::isValidIndex(int index) const
{
	return (index >= 0) && (index < num_students);
}

void StudentArray::returnError() const
{
	cout << "invaild operation. halt program." << endl;
	exit(1);
}

template<typename T>
void StudentArray::QuickSort(Student *arr, int size, T *subArr)
{
	if (size <= 1)	//���̻� sorting �� �׸��� ����!
	{
		return;
	}
	int right = size - 1;
	int storeIndex = 0;
	Student Stud_Temp;
	T T_Temp;
	T pivotValue = subArr[right / 2];

	Stud_Temp = arr[right / 2];	//������� pivotIndex�� ��� right ���� ���� �� pivotValue ����
	arr[right / 2] = arr[right];
	arr[right] = Stud_Temp;

	T_Temp = subArr[right / 2];	//subArray�� ������� pivotIndex�� ��� right ���� ���� �� pivotValue ����
	subArr[right / 2] = subArr[right];
	subArr[right] = T_Temp;

	if (size > 1)
	{
		for (int left = 0; left < size; left++)
		{
			if (subArr[left] < pivotValue) {
				if (left == storeIndex)	//storeIndex�� left�� ���ٸ� swap�� �ϴ� ���� �޸� ����!
				{
					storeIndex++;
					continue;
				}
				Stud_Temp = arr[left];	//left�� pivotVale���� �۴ٸ� storeIndex�� ���� �� storeIndex 1 ����
				arr[left] = arr[storeIndex];
				arr[storeIndex] = Stud_Temp;

				T_Temp = subArr[left];	//subArray�� left�� pivotVale���� �۴ٸ� storeIndex�� ���� �� storeIndex 1 ����
				subArr[left] = subArr[storeIndex];
				subArr[storeIndex] = T_Temp;
				storeIndex++;
			}
		}
		Stud_Temp = arr[storeIndex];	//������� ����
		arr[storeIndex] = arr[right];
		arr[right] = Stud_Temp;

		T_Temp = subArr[storeIndex];	//subArray�� ������� ����
		subArr[storeIndex] = subArr[right];
		subArr[right] = T_Temp;
		storeIndex++;

	}
	QuickSort(arr, storeIndex, subArr);	//recursive call - ���� cut �� �迭�� ������ �ִ밪�� cut �ؼ� �Լ� ȣ��
	QuickSort(arr + (storeIndex + 1), size - (storeIndex + 1), subArr + (storeIndex + 1));	//sorting�� �Ϸ�� ���� �迭�� �߶󳻰� ������ �迭�� �μ��� ����

}