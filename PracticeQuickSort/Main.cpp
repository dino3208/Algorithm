#include <cstdlib>
#include <ctime>
#include <iostream>

template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

int RandomRange(int min, int max)
{
	int diff = (max - min) + 1;
	return ((diff * rand()) / (RAND_MAX + 1)) + min;
}

int Partition(int* array, int left, int right)
{
	int pivot = array[left];
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		// 피벗보다 큰 값을 찾는다
		while (low <= right && array[low] <= pivot)
		{
			++low;
		}

		// 피벗보다 작은 값을 찾는다
		while (high > left && array[high] >= pivot)
		{
			--high;
		}

		if (low > high)
		{
			break;
		}

		Swap(array[low], array[high]);
		return high;
	}
}

void QuickSort(int array[], int left, int right)
{
	if (left < right)
	{
		int pivotIndex = Partition(array, left, right);

		QuickSort(array, left, pivotIndex - 1);
		QuickSort(array, pivotIndex + 1, right);
	}
}

int main()
{
	const int length = 10;
	int array[length];

	// 프로그램이 시작될 때 한 번만 종자값을 설정한다
	srand(static_cast<unsigned int>(time(nullptr)));

	std::cout << "선택된 수: \n";
	for (int ix = 0;ix < length;++ix)
	{
		int value = RandomRange(1, 100);
		array[ix] = value;
		std::cout << value << " ";
	}

	std::cout << "\n\n";

	QuickSort(array, 0, length - 1);

	std::cout << "퀵 정렬 후 데이터: \n";
	for (int ix = 0;ix < length;++ix)
	{
		std::cout << array[ix] << " ";
	}

	std::cout << "\n";

	std::cin.get();
}