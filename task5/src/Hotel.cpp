#include "Hotel.h"

Hotel::Hotel() {}

Hotel::~Hotel() {}

void Hotel::run() {
	int option;
	is_done_ = false;
	while (!is_done_) {
		printMenu();
		std::cout << "Pick an option: ";
		std::cin >> option;
		std::cout << '\n';
		if (option == 1) {
			addNewCustomer();
		}
		else if (option == 2) {
			deleteCustomer();
		}
		else if (option == 3) {
			calculateCost();
		}
		else if (option == 4) {
			exit();
		}
	}
}

void Hotel::printMenu() {
	std::cout << "1. Add a customer.\n";
	std::cout << "2. Delete customer.\n";
	std::cout << "3. Give receipt.\n";
	std::cout << "4. Exit.\n";
	std::cout << '\n';
}

void Hotel::addNewCustomer() {
	std::cout << "Please enter name: ";
	std::string name;
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << '\n';

	std::cout << "Please enter age: ";
	int age;
	std::cin >> age;
	std::cout << '\n';

	std::cout << "Please enter passport number: ";
	std::string passport_number;
	std::cin.ignore();
	std::getline(std::cin, passport_number);
	std::cout << '\n';

	std::cout << "Please enter the duration(in days): ";
	int days;
	std::cin >> days;
	std::cout << '\n';

	std::cout << "Please enter a type of room(A, B, C): ";
	char type;
	std::cin >> type;
	std::cout << '\n';

	if (type == 'A') {
		customers_[passport_number] = std::shared_ptr<Customer>(new Customer(name, age, passport_number, days, std::shared_ptr<RoomA>(new RoomA())));
	}
	else if (type == 'B') {
		customers_[passport_number] = std::shared_ptr<Customer>(new Customer(name, age, passport_number, days, std::shared_ptr<RoomB>(new RoomB())));
	}
	else if (type == 'C') {
		customers_[passport_number] = std::shared_ptr<Customer>(new Customer(name, age, passport_number, days, std::shared_ptr<RoomC>(new RoomC())));
	}

	std::cout << '\n';
}

void Hotel::deleteCustomer() {
	std::cout << "Please input passport number: ";
	std::string passport_number;
	std::cin.ignore();
	std::getline(std::cin, passport_number);
	std::cout << '\n';

	if (!customers_.count(passport_number)) {
		std::cout << "No such customer.\n";
		std::cout << '\n';
		return;
	}

	customers_.erase(passport_number);
}

void Hotel::calculateCost() {
	std::cout << "Please input passport number: ";
	std::string passport_number;
	std::cin.ignore();
	std::getline(std::cin, passport_number);
	std::cout << '\n';

	if (!customers_.count(passport_number)) {
		std::cout << "No such customer.\n";
		std::cout << '\n';
		return;
	}

	int cost = customers_[passport_number]->getRoom()->getCost();
	int days = customers_[passport_number]->getDays();

	std::cout << "Total ammount: " << cost * days << '\n';
	std::cout << '\n';
}

void Hotel::exit() {
	is_done_ = true;
}
