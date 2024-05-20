#include <iostream>
#include <string>

struct MyPerson{
	std::string name;
	int age;
	std::string job;
};

void print_person(const MyPerson& MP) {
	std::cout << "Name: " << MP.name << std::endl;
	std::cout << "Age: " << MP.age << std::endl;
	std::cout << "Position: " << MP.job<< std::endl;
}

MyPerson input_person() {
	MyPerson result;
	
	std::cout << "Enter name -> ";
	std::getline(std::cin, result.name);
	
	std::cout << "Enter age -> ";
	std::cin >> result.age;
	std::cin.ignore();
	
	std::cout << "Enter position -> ";
	std::getline(std::cin, result.job);

	return result;
}

struct Date {
	int day = 1;
	int month = 1;
	int year = 1970;
};

struct CoinsKeeper {
	std::string name;
	Date birthday;
	int coins_numbers = 0;
	int* coins = nullptr;
};

void print_keeper(const CoinsKeeper& CK) {
	std::cout << "Имя: " << CK.name << std::endl;
	std::cout << "Дата рождения: " <<
		CK.birthday.day << '.' <<
		CK.birthday.month << '.' <<
		CK.birthday.year << std::endl;
	std::cout << "Монеты: ";
	for (int i = 0; i < CK.coins_numbers; i++) {
		std::cout << CK.coins[i] << ' ';
	}
	std::cout << std::endl;
}

	inline int age(const CoinsKeeper & CK, int year) {
		return (year - CK.birthday.year);
	}

	int cash(const CoinsKeeper& CK) {
		int result = 0;
		for (int i = 0; i < CK.coins_numbers; i++) {
			result += CK.coins[i];
		}
		return result;
	}

int main() {
	setlocale(LC_ALL, "Russian");

	/*
	Структура - это описание множества, состоящего из одной или более переменных, возможно имеющих различные типы, объедененных под одним именем.
	Является производным пользовательским типом данных используемым для создания объектов.
	*/

	//Синтаксис создания структуры
	
	struct Person {
		std::string name; 
		int age;
		std::string job;
		int salary;
	}p4, p5;

	Person p1;
	p1.name = "Tom Smith";
	p1.age = 20;
	p1.job = "programer";
	p1.salary = 300000;

	std::cout << "Name: " << p1.name << std::endl;
	std::cout << "Age: " << p1.age << std::endl;
	std::cout << "Position: " << p1.job << std::endl;
	std::cout << "Salary: " << p1.salary << std::endl;

	std::cout << "---------------------" << std::endl;

	Person p2{ "Ivan Ku", 22, "programer", 100000 };
	std::cout << "Name: " << p2.name << std::endl;
	std::cout << "Age: " << p2.age << std::endl;
	std::cout << "Position: " << p2.job << std::endl;
	std::cout << "Salary: " << p2.salary << std::endl;

	std::cout << "---------------------" << std::endl;

	Person p3 = p1;	//Копия p1, при этом можно записать другие значения по усмотрению, например возраст.
	p3.age = 30;
	std::cout << "Name: " << p3.name << std::endl;
	std::cout << "Age: " << p3.age << std::endl;
	std::cout << "Position: " << p3.job << std::endl;
	std::cout << "Salary: " << p3.salary << std::endl;

	//Поля по умолчанию, вложенные структуры и указатели на объекты структур
	struct Date {
		int day = 1;
		int month = 1;
		int year = 1970;
	};

	Date d1;
	std::cout << d1.day << '.' << d1.month << '.' << d1.year << std::endl;
	
	Date d2{20, 5, 2024};
	std::cout << d2.day << '.' << d2.month << '.' << d2.year << std::endl;

	struct Human{
		std::string name;
		Date birthday;
		std::string job;
	};

	Human h1{ "Omar", { 1,1,2000 }, "dvornyk" };
	std::cout << "Name: " << h1.name << std::endl;
	std::cout << "Birthday: " << h1.birthday.day << '.' << h1.birthday.month << '.' << h1.birthday.year << std::endl;
	std::cout << "Position: " << h1.job << std::endl;

	Human* ph = &h1;
	std::cout << ph->name << std::endl;
	std::cout << ph->birthday.day << std::endl;

	//Структуры и функции
	MyPerson mp1{ "Ivan Ku", 22, "Joon" };
	print_person(mp1);

	std::cout << "----------\n";
	MyPerson mp2 = input_person();
	print_person(mp2);

	//Задача 1. Хранитель монет

	std::cout << "Задача 1.\nИнформация о хранителе:\n";
	
	//Инициализация хранителя монет
	CoinsKeeper ck{
		"Адам Смит",
		{ 15, 7, 1900},
		5,
		new int[5] {1, 10, 2, 2, 10}
	};

	//Вывод информации о хранителе данных через функцию print_keeper
	print_keeper(ck);
	
	//Вывод информации о возрасте храниеля через функцию age
	std::cout << "Возраст: " << age(ck, 2024) << std::endl;

	//Вывод информации о состоянии хранителя через функцию cash
	std::cout << "Общие сбережения: " << cash(ck) << std::endl;

	return 0;
}