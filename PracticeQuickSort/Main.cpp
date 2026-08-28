#include <cstring>
#include <iostream>

template<typename T>
void Swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

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
	int GetAge() const { return age;}
	void SetAge(int newAge) { age = newAge; }

private:
	char* name;
	int age;
};

int Partition(Person** array, int left, int right)
{
	int pivot = array[left]->GetAge();
	int low = left + 1;
	int high = right;

	while (low <= high)
	{
		// 피벗 나이보다 큰 객체를 찾는다
		while (low <= right && array[low]->GetAge() <= pivot)
		{
			++low;
		}

		// 피벗 나이보다 작은 객체를 찾는다
		while (high > left && array[high]->GetAge() >= pivot)
		{
			--high;
		}

		if (low > high)
		{
			break;
		}

		Swap(array[low], array[high]);
	}

	Swap(array[left], array[high]);
	return high;
}

void QuickSort(Person* array[], int left, int right)
{
	if (left < right)
	{
		int pivotIndex = Partition(array, left, right);

		QuickSort(array, left, pivotIndex - 1);
		QuickSort(array, pivotIndex + 1, right);
	}
}

void PrintArray(Person* array[], int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << "이름: " << array[ix]->GetName()
			<< "나이: " << array[ix]->GetAge() << "\n";
	}

	std::cout << "\n";
}

int main()
{
	Person* people[] =
	{
		new Person("Alice", 25),
		new Person("Mother", 70),
		new Person("Bob", 30),
		new Person("Father", 72),
		new Person("Charlie", 20),
		new Person("Ronnie", 40)
	};
	
	int length = sizeof(people) / sizeof(people[0]);

	std::cout << "====== 퀵 정렬 전 배열 ======\n";
	PrintArray(people, length);

	QuickSort(people, 0, length - 1);

	std::cout << "====== 퀵 정렬 후 배열 ======\n";
	PrintArray(people, length);

	for (int ix = 0; ix < length; ++ix)
	{
		delete people[ix];
	}

	std::cin.get();
	return 0;
}