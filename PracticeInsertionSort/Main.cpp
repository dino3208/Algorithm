#include <cstring>
#include <iostream>

void InsertionSort(const char* array[], int length)
{
	for (int ix = 1;ix < length;++ix)
	{
		const char* keyValue = array[ix];
		int jx = ix - 1;

		while (jx >= 0 && strcmp(array[jx], keyValue) > 0)
		{
			array[jx + 1] = array[jx];
			--jx;
		}

		array[jx + 1] = keyValue;
	}
}
void PrintArray(const char* array[], int length)
{
	for (int ix = 0; ix < length;++ix)
	{
		std::cout << array[ix];

		if (ix < length - 1)
		{
			std::cout << ", ";
		}

		std::cout << "\n";
	}
}

int main()
{
	// 자료 집합
	const char* array[] = { "banana", "apple", "orange", "grape", "kiwi" };

	int length = sizeof(array) / sizeof(array[0]);

	PrintArray(array, length);

	InsertionSort(array, length);

	PrintArray(array, length);

	std::cin.get();
}