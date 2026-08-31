#include <iostream>

class Person
{
public:
	Person(const char* name, int age)
		:age(age)
	{
		int length = static_cast<int>(strlen(name) + 1);
		this->name = new char[length];
		strcpy_s(this->name, length, name);
	}

	~Person()
	{
		delete[] name;
	}

	const char* GetName() const { return name; }
	int GetAge() const { return age; }

private:
	char* name;
	int age;
};

void Merge(
	Person* array[],
	Person* leftArray[], int leftArrayLength,
	Person* rightArray[], int rightArrayLength)
{
	int leftIndex = 0;
	int rightIndex = 0;
	int mergedIndex = 0;

	while (leftIndex < leftArrayLength && rightIndex < rightArrayLength)
	{
		if (leftArray[leftIndex]->GetAge() <= rightArray[rightIndex]->GetAge())
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

	// 잔여 원소 처리
	while (leftIndex < leftArrayLength)
	{
		array[mergedIndex] = leftArray[leftIndex];
		++leftIndex;
		++mergedIndex;
	}
	while (rightIndex < rightArrayLength)
	{
		array[mergedIndex] = rightArray[rightIndex];
		++rightIndex;
		++mergedIndex;
	}
}

void MergeSort(Person* array[], int length)
{
	if (length <= 1)
	{
		return;
	}

	int middle = length / 2;
	int leftArrayLength = middle;
	int rightArrayLength = length - middle;

	Person** leftArray = new Person * [leftArrayLength];
	Person** rightArray = new Person * [rightArrayLength];

	memcpy(leftArray, array, sizeof(Person*) * leftArrayLength);
	memcpy(rightArray, array, sizeof(Person*) * rightArrayLength);

	MergeSort(leftArray, leftArrayLength);
	MergeSort(rightArray, rightArrayLength);

	Merge(array,
		leftArray, leftArrayLength,
		rightArray, rightArrayLength);

	delete[] leftArray;
	delete[] rightArray;
}