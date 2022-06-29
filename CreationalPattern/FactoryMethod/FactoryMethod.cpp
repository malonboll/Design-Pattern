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
기존 Factory에선 없었던  고양이를 몇마리 생산했는지 알 수 있게 하는 기능을 추가했습니다.
*/
class CatFactory :public Factory
{
public:
	CatFactory() { num = 0; }
	int getNum() { return num; }	// Cat Factory의 추가 기능
	Animal* CreateAnimal()
	{
		++num;
		return new Cat;
	}
private:
	int num;
};

/*
이 클래스에서는 날개달린 강아지를 반환할 수 있습니다.
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
	cout << cf.getNum() << endl;	// 고양이가 몇마리 생산되었는지 출력 ! 


	Animal* B;
	B = df.CreateAnimal();
	B->speak();
	df.upgrade();				// 강아지 날개 업그레이드 ! 


	return 0;
}