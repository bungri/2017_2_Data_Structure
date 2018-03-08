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
	if (size <= 1)	//더이상 sorting 할 항목이 없음!
	{
		return;
	}
	int right = size - 1;
	int storeIndex = 0;
	int pivotValue = arr[right / 2].getElapsedDays();

	tempDate = arr[right / 2];
	arr[right / 2]  = arr[right];
	arr[right] = tempDate; //가운데값을 pivotIndex로 잡아 right 값과 스왑 후 pivotValue 추출

	if (size > 1)
	{
		for (int left = 0; left < size; left++)
		{
			int temp = arr[left].getElapsedDays();
			if (arr[left].getElapsedDays() == pivotValue)
				continue;
			if (arr[left].getElapsedDays() < pivotValue) {
				if (left == storeIndex)	//storeIndex와 left가 같다면 swap을 하는 것은 메모리 낭비!
				{
					storeIndex++;
					continue;
				}
				tempDate = arr[storeIndex];
				arr[storeIndex] = arr[left];
				arr[left] = tempDate; //left가 pivotVale보다 작다면 storeIndex와 스왑 후 storeIndex 1 증가

				storeIndex++;
			}
		}
		tempDate = arr[right];
		arr[right] = arr[storeIndex];
		arr[storeIndex] = tempDate; //원래대로 스왑
	}

	quickSort(arr, storeIndex);	//recursive call - 왼쪽 / cut 할 배열이 없으니 최대값만 cut 해서 함수 호출
	quickSort(arr + (storeIndex + 1), size - (storeIndex + 1));	//sorting이 완료된 왼쪽 배열은 잘라내고 오른쪽 배열만 인수로 전달
}