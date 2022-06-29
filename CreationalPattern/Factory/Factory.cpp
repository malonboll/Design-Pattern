#include <iostream>

enum class eObjects
{
	objDog,
	objCat
};

/*
�߻�Ŭ���� �Դϴ�
Factory�� ��ȯ Ŭ�����Դϴ�.
*/
class Animal
{
public:
	virtual void speak() = 0;
};

/*
Animal�� �ڽ� Ŭ���� Cat �Դϴ�.
*/
class Cat :public Animal
{
public:
	void speak()
	{
		std::cout << "meow" << std::endl;
	}
};

/*
Animal�� �ڽ� Ŭ���� Dog �Դϴ�.
*/
class Dog : public Animal
{
public:
	void speak()
	{
		std::cout << "bark" << std::endl;
	}
};

/*
Factory ������ Class�ε� ������ �� �ְ� Function���ε� ������ �� �ֽ��ϴ�.
*/

/*
Factory�� Function���� �����߽��ϴ�.
�Է¹��� enum ���� ���� Objcet�� �����ϰ� ������ Object�� pointer�� ��ȯ�մϴ�.
*/
Animal *FactoryFunction(eObjects obj)
{
	switch (obj)
	{
	case eObjects::objDog:
		return new Dog();
	case eObjects::objCat:
		return new Cat();
	default:
		return new Dog();
	}
}

/*
Factory�� Class�� �����߽��ϴ�.
*/
class Factoy
{
public:
	Animal *CreateAnimal(eObjects obj)
	{
		switch (obj)
		{
		case eObjects::objDog:
			return new Dog();
		case eObjects::objCat:
			return new Cat();
		default:
			return new Dog();
		}
	};
};

int main()
{
	// Factory Method ���
	Animal* A;
	A = FactoryFunction(eObjects::objCat);	// Cat Object ������
	A->speak();

	// Factory Class ���
	Factoy AnimalFactory;				// CreateAnimal �Լ��� ����ϱ� ���� Factory class ����
	Animal* B;
	B = AnimalFactory.CreateAnimal(eObjects::objDog);	// Dog Object ������
	B->speak();

	return 0;
}

/*
������ ���������� �ǹ������� Object�� ������ ������ �� �ֽ��ϴ�.
������ Factory ������ �ٽ��� ������ ���� ������ Factory�� ĸ��ȭ�Ͽ� ��ü ������ �����ϰ� ������ �� �ֽ��ϴ�.
Client�� Factory�� ���ϴ� Object�� Ű����(���⼭�� enum class�� eObjects)�� �Ѱ��ֱ⸸ �ϸ� Factory�� Object�� ��ȯ�մϴ�.
*/