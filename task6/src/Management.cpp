#include "Management.h"

void Management::run() {
	int option;
	is_done_ = false;
	while (!is_done_) {
		printMenu();
		std::cout << "Pick an option: ";
		std::cin >> option;
		if (option == 1) {
			addNewStudent();
		}
		else if (option == 2) {
			showInfoStudentsByAge();
		}
		else if (option == 3) {
			showInfoStudentsByAgeAndOrigin();
		}
		else if (option == 4) {
			exit();
		}
	}
}

void Management::printMenu() {
	std::cout << "1. Add new student.\n";
	std::cout << "2. Show info of students that are 20 years old.\n";
	std::cout << "3. Show info of students that are 23 years old\n";
	std::cout << "and originate from DN.\n";
	std::cout << "4. Exit.\n";
	std::cout << '\n';
}

void Management::addNewStudent() {
	std::cout << "Enter name: ";
	std::string name;
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << '\n';

	std::cout << "Enter age: ";
	int age;
	std::cin >> age;
	std::cout << '\n';

	std::cout << "Enter origin: ";
	std::string origin;
	std::cin.ignore();
	std::getline(std::cin, origin);
	std::cout << '\n';

	std::cout << "Enter classroom: ";
	std::string classroom;
	std::cin.ignore();
	std::getline(std::cin, classroom);
	std::cout << '\n';

	students_.push_back(std::shared_ptr<Student>(new Student(name, age, origin, classroom)));
}

void Management::showInfoStudentsByAge() {
	int age = 20;

	for (auto s: students_) {
		if (s->getAge() == age) {
			s->printInfo();
		}
	}
}

void Management::showInfoStudentsByAgeAndOrigin() {
	int age = 23;
	std::string origin = "DN";

	int count = 0;
	for (auto s: students_) {
		if (s->getAge() == age && s->getOrigin() == origin) {
			s->printInfo();
			++count;
		}
	}
	std::cout << '\n';
	std::cout << "There are a total of " << count << " students.\n";
	std::cout << '\n';
}

void Management::exit() {
	is_done_ = true;
}
