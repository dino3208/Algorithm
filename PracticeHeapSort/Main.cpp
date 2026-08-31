#include <iostream>

#define ArraySize(array) (sizeof(array)/sizeof(array[0]))

template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

// 현재 노드를 루트로 하는 서브트리를 최대 힙으로 만든다
void Heapify(int array[], int length, int index)
{
	while(true)
	{
		int smallest = index;
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;

		// 왼쪽 자식이 더 크면 교환 대상을 변경
		if (leftChild < length && array[leftChild] < array[smallest])
		{
			smallest = leftChild;
		}
		// 오른쪽 자식이 더 크면 교환 대상을 변경
		if (rightChild < length && array[rightChild] < array[smallest])
		{
			smallest = rightChild;
		}

		// 현재 노드가 가장 크면 최대 힙 조건 만족
		if (smallest == index)
		{
			break;
		}

		Swap(array[index], array[smallest]);

		// 값이 내려간 위치에서 자식 노드와 다시 비교
		index = smallest;
	}
}

// 배열을 오름차순으로 힙 정렬
void HeapSort(int array[], int length)
{
	// 마지막 부모 노드부터 최대 힙을 구성
	for (int ix = length / 2 - 1;ix >= 0;--ix)
	{
		Heapify(array, length, ix);
	}

	// 루트의 최댓값을 배열 뒤쪽부터 차례대로 배치
	for (int ix = length - 1;ix > 0; --ix)
	{
		Swap(array[0], array[ix]);

		// ix 이후는 정렬된 범위이므로 힙에서 제외
		Heapify(array, ix, 0);
	}
}

void PrintArray(const int array[], int length)
{
	for (int ix = 0; ix < length;++ix)
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

	const int length = static_cast<int>(ArraySize(array));

	std::cout << "정렬 전 배열: ";
	PrintArray(array, length);

	HeapSort(array, length);

	std::cout << "정렬 후 배열: ";
	PrintArray(array, length);
}
