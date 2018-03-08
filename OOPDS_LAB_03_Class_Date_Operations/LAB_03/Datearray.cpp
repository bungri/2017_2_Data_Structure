#include "DateArray.h"
#include "Date.h"

DateArray::DateArray(int size) // constructor
{
	arraySize = size;
	pDate = new Date[size];
	for (int i = 0; i<size; i++) {
		pDate[i].setDate(1, 1, 1);
		pDate[i].name = "";
	}
}

DateArray::DateArray(const DateArray &obj) // constructor
{
	arraySize = obj.arraySize;
	pDate = new Date[arraySize];
	for (int i = 0; i<arraySize; i++) {
		pDate[i] = obj.pDate[i]; // *(pCA+i) = obj.pCA[i];
	}
}

DateArray::~DateArray() // destructor
{
	if (arraySize > 0)
		delete[] pDate;
}

Date &DateArray::operator [](int sub)
{
	if (sub < 0 || sub >= arraySize) // checking validity of range
		returnError();
	return pDate[sub];
}

void DateArray::returnError()
{
	cout << "Invaild operation! halt program." << endl;
	exit(1);
}

void DateArray::sort()
{
	quickSort(this->pDate, this->arraySize);
}

bool DateArray::isValidIndex(int index)
{
	return index < arraySize;
}

void DateArray::quickSort(Date *arr, int size)
{
	Date tempDate;
	if (size <= 1)	//���̻� sorting �� �׸��� ����!
	{
		return;
	}
	int right = size - 1;
	int storeIndex = 0;
	int pivotValue = arr[right / 2].getElapsedDays();

	tempDate = arr[right / 2];
	arr[right / 2]  = arr[right];
	arr[right] = tempDate; //������� pivotIndex�� ��� right ���� ���� �� pivotValue ����

	if (size > 1)
	{
		for (int left = 0; left < size; left++)
		{
			int temp = arr[left].getElapsedDays();
			if (arr[left].getElapsedDays() == pivotValue)
				continue;
			if (arr[left].getElapsedDays() < pivotValue) {
				if (left == storeIndex)	//storeIndex�� left�� ���ٸ� swap�� �ϴ� ���� �޸� ����!
				{
					storeIndex++;
					continue;
				}
				tempDate = arr[storeIndex];
				arr[storeIndex] = arr[left];
				arr[left] = tempDate; //left�� pivotVale���� �۴ٸ� storeIndex�� ���� �� storeIndex 1 ����

				storeIndex++;
			}
		}
		tempDate = arr[right];
		arr[right] = arr[storeIndex];
		arr[storeIndex] = tempDate; //������� ����
	}

	quickSort(arr, storeIndex);	//recursive call - ���� / cut �� �迭�� ������ �ִ밪�� cut �ؼ� �Լ� ȣ��
	quickSort(arr + (storeIndex + 1), size - (storeIndex + 1));	//sorting�� �Ϸ�� ���� �迭�� �߶󳻰� ������ �迭�� �μ��� ����
}