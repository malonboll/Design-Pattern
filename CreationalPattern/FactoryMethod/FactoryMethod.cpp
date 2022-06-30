#include <iostream>

using namespace std;

enum class eAnimal
{
	eDog,
	eCat
};

class Animal
{
public:
	virtual void speak() = 0;
};

class Cat : public Animal
{
public:
	void speak()
	{
		cout << "meow" << endl;
	};
};

class Dog : public Animal
{
public:
	void speak()
	{
		cout << "bark" << endl;
	};
};

class Factory
{
public:
	virtual Animal* CreateAnimal() = 0;
};

/*
���� Factory���� ������  ����̸� ��� �����ߴ��� �� �� �ְ� �ϴ� ����� �߰��߽��ϴ�.
*/
class CatFactory :public Factory
{
public:
	CatFactory() { num = 0; }
	int getNum() { return num; }	// Cat Factory�� �߰� ���
	Animal* CreateAnimal()
	{
		++num;
		return new Cat;
	}
private:
	int num;
};

/*
�� Ŭ���������� �����޸� �������� ��ȯ�� �� �ֽ��ϴ�.
*/
class DogFactory :public Factory
{
public:
	Animal* CreateAnimal() { return new Dog; }
	void upgrade()
	{
		cout << "add wings.." << endl;
	}
};

int main()
{
	CatFactory cf;
	DogFactory df;

	Animal* A;
	A = cf.CreateAnimal();
	A->speak();
	cout << cf.getNum() << endl;	// ����̰� ��� ����Ǿ����� ��� ! 


	Animal* B;
	B = df.CreateAnimal();
	B->speak();
	df.upgrade();				// ������ ���� ���׷��̵� ! 


	return 0;
}