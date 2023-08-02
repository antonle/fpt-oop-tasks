#include "Management.h"

void Management::run() {
	int option;
	is_done_ = false;
	while (!is_done_) {
		printMenu();
		std::cin >> option;
		std::cout << '\n';
		if (option == 1) {
			addNewStudent();
		}
		else if (option == 2) {
			showAllInfo();
		}
		else if (option == 3) {
			findStudentById();
		}
		else if (option == 4) {
			exit();
		}
	}
}

void Management::printMenu() {
	std::cout << "1. Add new student. \n";;
	std::cout << "2. Show info \n";
	std::cout << "3. Find by ID \n";
	std::cout << "4. Exit \n";

	std::cout << "Please pick an option: ";
}

void Management::addNewStudent() {
	std::cout << "What is the student's id? ";
	int id;
	std::cin >> id;

	std::cout << "What is the student's name? ";
	std::string name;
	std::cin.ignore();
	std::getline(std::cin, name);

	std::cout << "What is the student's address? ";
	std::string address;
	std::cin.ignore();
	std::getline(std::cin, address);

	std::cout << "What is the student's level of priority?(number) ";
	int priority;
	std::cin >> priority;

	std::cout << "What type is the student?(A, B, C) ";
	std::string type;
	std::cin >> type;

	if (type == "A") {
		students_.push_back(std::shared_ptr<Student>(new StudentA(id, name, address, priority)));
	}
	else if (type == "B") {
		students_.push_back(std::shared_ptr<Student>(new StudentB(id, name, address, priority)));
	}
	else if (type == "C") {
		students_.push_back(std::shared_ptr<Student>(new StudentC(id, name, address, priority)));
	}

	std::cout << '\n' << '\n';
}

void Management::showAllInfo() {
	for (auto s: students_) {
		s->printInfo();
	}
}

void Management::findStudentById() {
	std::cout << "Who do you want to find?(id) ";
	int id;
	std::cin >> id;

	for (auto s: students_) {
		if (s->getId() == id) {
			s->printInfo();
			return;
		}
	}
	std::cout << "No such student\n";
	std::cout << '\n';
}

void Management::exit() {
	is_done_ = true;
}
