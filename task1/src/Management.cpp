#include <iostream>

#include "Management.h"
#include "Worker.h"
#include "Engineer.h"
#include "Staff.h"

Management::Management() {}

Management::~Management() {
	for (int i = 0; i < list_.size(); ++i) {
		delete list_[i];
	}
}

void Management::addNewWorker(const std::string& name, int age, Sex sex, const std::string& address, int level) {
	list_.push_back(new Worker(name, age, sex, address, level));
}

void Management::addNewEngineer(const std::string& name, int age, Sex sex, const std::string& address, const std::string& major) {
	list_.push_back(new Engineer(name, age, sex, address, major));
}

void Management::addNewStaff(const std::string& name, int age, Sex sex, const std::string& address, const std::string& job) {
	list_.push_back(new Staff(name, age, sex, address, job));
}

void Management::find(const std::string& name) {
	for (int i = 0; i < list_.size(); ++i) {
		if (list_[i] != nullptr && list_[i]->getName() == name) {
			list_[i]->printDetailedInfo();
		}
	}
}

void Management::printAll() const {
	for (int i = 0; i < list_.size(); ++i) {
		if (list_[i] != nullptr) {
			list_[i]->printDetailedInfo();
		}
	}
}

void Management::run() {
	int option = 0;
	isDone = false;
	while (!isDone) {
		printMenu();
		option = getOption();
		if (option == 1) {
			getEmployeeInfo();
		}
		else if (option == 2) {
			std::string name = getNameToFind();
			find(name);
		}
		else if (option == 3) {
			printAll();
		}
		else {
			done();
		}
	}
}

void Management::printMenu() const {
	std::cout << "1. Add New Employee\n";
	std::cout << "2. Find Employee\n";
	std::cout << "3. Print All Employees\n";
	std::cout << "4. Exit\n";
	std::cout << '\n';
}

int Management::getOption() const {
	std::cout << "Pick an option: ";
	int option;
	std::cin >> option;
	std::cout << '\n';
	return option;
}

void Management::getEmployeeInfo() {
	std::cout << "What position do you want to add?(engineer, worker, staff) ";
	std::string position;
	std::cin >> position;

	std::cout << "Enter name: ";
	std::string name;
	std::cin.ignore();
	std::getline(std::cin, name);

	std::cout << "Enter age: ";
	int age;
	std::cin >> age;

	std::cout << "Enter sex(male, female, other): ";
	std::string sex;
	std::cin >> sex;
	Sex indSex;
	if (sex == "male") {
		indSex = Sex::MALE;
	}
	else if (sex == "female") {
		indSex = Sex::FEMALE;
	}
	else if (sex == "other") {
		indSex = Sex::OTHER;
	}

	std::cout << "Enter address: ";
	std::string address;
	std::cin.ignore();
	std::getline(std::cin, address);

	if (position == "worker") {
		std::cout << "State your level: ";
		int level;
		std::cin >> level;
		addNewWorker(name, age, indSex, address, level);
	}
	else if (position == "engineer") {
		std::cout << "State your major: ";
		std::string major;
		std::cin.ignore();
		std::getline(std::cin, major);
		addNewEngineer(name, age, indSex, address, major);
	}
	else if (position == "staff") {
		std::cout << "State yout job: ";
		std::string job;
		std::cin.ignore();
		std::getline(std::cin, job);
		addNewStaff(name, age, indSex, address, job);
	}

	std::cout << '\n' << '\n';
}

std::string Management::getNameToFind() const {
	std::cout << "Which name do you want to find? ";
	std::string name;
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << '\n';

	return name;
}

void Management::done() {
	isDone = true;
}
