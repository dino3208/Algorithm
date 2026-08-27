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
		: age(age)
	{
		int length = static_cast<int>(strlen(name) + 1);
		this->name = new char[length];
		strcpy_s(this->name, length, name);
	}

	~Person()
	{
		delete[] name;
	}

	int GetAge() const { return age; }
	const char* GetName() const { return name; }

private:
	char* name;
	int age;
};

void BubbleSort(Person* array[], int length)
{
	for (int ix = 0;ix < length - 1;++ix)
	{
		for (int jx = 0;jx < length - ix - 1;++jx)
		{
			if (strcmp(array[jx]->GetName(), array[jx + 1]->GetName()) >0)
			{
				Swap(array[jx], array[jx + 1]);
			}
		}
	}
}

void PrintArray(Person* array[], int length)
{
	for (int ix = 0; ix < length;++ix)
	{
		std::cout << "이름: " << array[ix]->GetName() << "나이: " << array[ix]->GetAge() << "\n";
	}
}

int main()
{
	// 객체 배열 생성
	Person* people[] =
	{
	new Person("Alice", 25),
	new Person("Bob", 30),
	new Person("Charlie", 20)
	};

	// 배열길이
	int length = sizeof(people) / sizeof(people[0]);

	// 정렬 전 출력
	std::cout << "정렬 전 배열\n";
	PrintArray(people, length);

	BubbleSort(people, length);

	std::cout << "정렬 후 배열\n";
	PrintArray(people, length);

	// 메모리 해제
	for (int ix = 0; ix < length; ++ix)
	{
		delete people[ix];
	}

	std::cin.get();
}