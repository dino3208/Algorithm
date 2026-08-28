#include <cstring>
#include <iostream>

// 정렬된 두 배열을 하나로 병합하는 함수
void Merge(
	int array[],
	int leftArray[], int leftArrayLength,
	int rightArray[], int rightArrayLength)
{
	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	// 두 배열의 현재 원소를 비교해 작은 값을 저장한다.
	while (leftIndex < leftArrayLength &&
		rightIndex < rightArrayLength)
	{
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			array[mergedIndex] = leftArray[leftIndex];
			++leftIndex;
		}
		else
		{
			array[mergedIndex] = rightArray[rightIndex];
			++rightIndex;
		}
		++mergedIndex;
	}
	// 왼쪽 배열에 남은 원소를 복사한다
	while (leftIndex < leftArrayLength)
	{
		array[mergedIndex] = leftArray[leftIndex];
		++leftIndex;
		++mergedIndex;
	}

	// 오른쪽 배열에 남은 원소를 복사한다
	while (rightIndex < rightArrayLength)
	{
		array[mergedIndex] = rightArray[rightIndex];
		++rightIndex;
		++mergedIndex;
	}
}

void MergeSort(int array[], int length)
{
	// 원소가 하나 이하면 이미 정렬된 상태
	if (length <= 1)
	{
		return;
	}

	int middle = length / 2;
	int leftArrayLength = middle;
	int rightArrayLength = length - middle;

	int* leftArray = new int[leftArrayLength];
	int* rightArray = new int[rightArrayLength];

	// 인덱스 0부터 middle -1 까지 복사
	memcpy(leftArray, array, sizeof(int) * leftArrayLength);

	// 인덱스 middle부터 length -1까지 복사
	memcpy(rightArray, array + middle, sizeof(int) * rightArrayLength);

	MergeSort(leftArray, leftArrayLength);
	MergeSort(rightArray, rightArrayLength);

	Merge(array,
		leftArray, leftArrayLength,
		rightArray, rightArrayLength);

	delete[] leftArray;
	delete[] rightArray;
}

void PrintArray(int array[], int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix];

		if (ix < length - 1)
		{
			std::cout << ", ";
		}
	}

	std::cout << "\n";
}

int main()
{
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };
	int length = sizeof(array) / sizeof(array[0]);

	std::cout << "정렬 전 배열: ";
	PrintArray(array, length);

	MergeSort(array, length);

	std::cout << "정렬 후 배열: ";
	PrintArray(array, length);

	std::cin.get();
	return 0;
}