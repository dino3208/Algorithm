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

}