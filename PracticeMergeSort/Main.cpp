#include <cstring>
#include <iostream>

void Merge(
	const char* array[],
	const char* leftArray[], int leftArrayLength,
	const char* rightArray[], int rightArrayLength
)
{
	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
	{
		if (strcmp(leftArray[leftIndex], rightArray[rightIndex]) <= 0)
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
}

void MergeSort(const char* array[], int length)
{
	if (length <= 1)
	{
		return;
	}

	int middle = length / 2;
	int leftArrayLength = middle;
	int rightArrayLength = length - middle;

	const char** leftArray = new const char* [leftArrayLength];
	const char** rightArray = new const char* [leftArrayLength];

	memcpy(leftArray, array, sizeof(int) * leftArrayLength);
	memcpy(rightArray, array + middle, sizeof(int) * rightArrayLength);

	MergeSort(leftArray, leftArrayLength);
	MergeSort(rightArray, rightArrayLength);

	Merge(array,
		leftArray, leftArrayLength,
		rightArray, rightArrayLength);

	delete[] leftArray;
	delete[] rightArray;

}