#include "Management.h"

Management::Management(): town_(sptrTown(new Town())) {}

void Management::run() {
	int option;
	is_done_ = false;
	while (!is_done_) {
		printMenu();
		std::cout << "Pick an option: ";
		std::cin >> option;
		std::cout << '\n';
		if (option == 1) {
			getFamilyInfo();
		}
		else if (option == 2) {
			showAllInfo();
		}
		else if (option == 3) {
			exit();
		}
	}
}

void Management::printMenu() {
	std::cout << "1. Add a family\n";
	std::cout << "2. Show info of town\n";
	std::cout << "3. Exit\n";
	std::cout << '\n';
}

void Management::getFamilyInfo() {
	std::cout << "How many members are in the family? ";
	int count;
	std::cin >> count;
	std::cout << '\n';

	std::cout << "What is the address? ";
	std::string address;
	std::cin.ignore();
	std::getline(std::cin, address);

	std::cout << '\n';

	addMembers(count, address);
}

void Management::exit() {
	is_done_ = true;
}

void Management::addMembers(int count, const std::string& address) {
	std::shared_ptr<Family> family(new Family());
	family->setAddress(address);

	for (int i = 0; i < count; ++i) {
		std::cout << "Getting info of the member number " << i + 1 << '\n';

		std::cout << "What is the name? ";
		std::string name;
		std::getline(std::cin, name);
		std::cout << '\n';

		std::cout << "How old is this member? ";
		int age;
		std::cin >> age;
		std::cout << '\n';

		std::cout << "What is his job? ";
		std::string job;
		std::cin.ignore();
		std::getline(std::cin, job);
		std::cout << '\n';

		std::cout << "What is his passport number? ";
		std::string passport_number;
		std::getline(std::cin, passport_number);
		std::cout << '\n';

		family->addMember(name, age, job, passport_number);

		std::cout << '\n';
	}

	town_->addFamily(family);
}


void Management::showAllInfo() {
	for (int i = 0; i < town_->getSize(); ++i) {
		std::cout << "Info about family number " << i + 1 << '\n';
		town_->getFamily(i)->printFamilyInfo();
		std::cout << '\n' << '\n';
	}
}
