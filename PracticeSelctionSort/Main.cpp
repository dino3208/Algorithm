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
	int GetAge() const { return age; }


private:
	char* name;
	int age;
};


void SelectionSoft(Person* array[], int length)
{
	for (int ix = 0; ix < length - 1;++ix)
	{
		int minIndex = ix;
		for (int jx = ix + 1;jx < length;++jx)
		{
			if (strcmp(array[jx]->GetName(), array[minIndex]->GetName())<0)
			{
				minIndex = jx;
			}
		}

		if (minIndex != ix)
		{
			Swap(array[ix], array[minIndex]);
		}
	}
}

void PrintArray(Person* array[], int length)
{
	for (int ix = 0;ix < length;++ix)
	{
		std::cout << "이름: " << array[ix]->GetName() << ", 나이: " << array[ix]->GetAge() << "\n";
	}
}

int main()
{
	// 배열 선언.
	Person* people[] =
	{
		new Person("Alice", 25),
		new Person("Bob", 30),
		new Person("Charlie", 20)
	};

	int length = sizeof(people) / sizeof(people[0]);

	PrintArray(people, length);

	SelectionSoft(people, length);

	PrintArray(people, length);

	for (int ix = 0;ix < length; ++ix)
	{
		delete people[ix];
	}

	std::cin.get();
}