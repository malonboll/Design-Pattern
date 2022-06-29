#include <iostream>

enum class eObjects
{
	objDog,
	objCat
};

/*
추상클래스 입니다
Factory의 반환 클래스입니다.
*/
class Animal
{
public:
	virtual void speak() = 0;
};

/*
Animal의 자식 클래스 Cat 입니다.
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
Animal의 자식 클래스 Dog 입니다.
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
Factory 패턴을 Class로도 구현할 수 있고 Function으로도 구현할 수 있습니다.
*/

/*
Factory를 Function으로 구현했습니다.
입력받은 enum 값에 따라 Objcet를 생성하고 생성된 Object의 pointer를 반환합니다.
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
Factory를 Class로 구현했습니다.
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
	// Factory Method 기반
	Animal* A;
	A = FactoryFunction(eObjects::objCat);	// Cat Object 생성됨
	A->speak();

	// Factory Class 기반
	Factoy AnimalFactory;				// CreateAnimal 함수를 사용하기 위한 Factory class 정의
	Animal* B;
	B = AnimalFactory.CreateAnimal(eObjects::objDog);	// Dog Object 생성됨
	B->speak();

	return 0;
}

/*
예제는 간단하지만 실무에서는 Object의 생성이 복잡할 수 있습니다.
하지만 Factory 패턴의 핵심은 복잡한 생성 과정은 Factory에 캡슐화하여 겍체 생성을 심플하게 유지할 수 있습니다.
Client는 Factory에 원하는 Object의 키워드(여기서는 enum class인 eObjects)만 넘겨주기만 하면 Factory는 Object를 반환합니다.
*/