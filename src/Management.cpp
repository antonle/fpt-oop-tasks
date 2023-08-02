#include "Management.h"

void Management::addNewBook(const std::string& code, const std::string& publisher, int count, const std::string& author, int paper_count) {
	map_[code] = std::shared_ptr<Material>(new Book(code, publisher, count, author, paper_count));
}

void Management::addNewJournal(const std::string& code, const std::string& publisher, int count, int month, int number) {
	map_[code] = std::shared_ptr<Material>(new Journal(code, publisher, count, month, number));
}

void Management::addNewNewspaper(const std::string& code, const std::string& publisher, int count, const std::string& date) {
	map_[code] = std::shared_ptr<Material>(new Newspaper(code, publisher, count, date));
}

void Management::printMenu() {
	std::cout << "1. Add new material.\n";
	std::cout << "2. Delete material.\n";
	std::cout << "3. Show indo.\n";
	std::cout << "4. Find by type.\n";
	std::cout << "5. Exit\n";
	std::cout << "\n";
}

void Management::getInfoforInsertion() {
	std::cout << "Which type would you like to add?(book, journal, newspaper) ";
	std::string type;
	std::cin >> type;

	std::cout << "What is the code for the material? ";
	std::string code;
	std::cin.ignore();
	std::getline(std::cin, code);

	std::cout << "Who is the publisher? ";
	std::string publisher;
	std::cin.ignore();
	std::getline(std::cin, publisher);

	std::cout << "How many copies were published? ";
	int count;
	std::cin >> count;

	if (type == "book") {
		std::cout << "Who is the author? ";
		std::string author;
		std::cin.ignore();
		std::getline(std::cin, author);

		std::cout << "How many papers are in the book? ";
		int paper_count;
		std::cin >> paper_count;
		addNewBook(code, publisher, count, author, paper_count);
	}
	else if (type == "journal") {
		std::cout << "What month was the journal published in? ";
		int month;
		std::cin >> month;

		std::cout << "What is the number of the journal? ";
		int number;
		std::cin >> number;

		addNewJournal(code, publisher, count, month, number);
	}
	else if (type == "newspaper") {
		std::cout << "What is the date of the publish? ";
		std::string date;
		std::cin.ignore();
		std::getline(std::cin, date);

		addNewNewspaper(code, publisher, count, date);
	}

	std::cout << '\n';
}

void Management::deleteMaterial() {
	std::cout << "What is the code of the material you want to delete? ";
	std::string code;
	std::cin.ignore();
	std::getline(std::cin, code);

	if (!map_.count(code)) {
		std::cout << "No such material\n";
		return;
	}

	map_.erase(code);
}

void Management::showInfoByCode() {
	std::cout << "What is the code of the material you want to get? ";
	std::string code;
	std::cin.ignore();
	std::getline(std::cin, code);

	if (!map_.count(code)) {
		std::cout << "No such material\n";
		return;
	}

	map_[code]->printDetailedInfo();
}

void Management::showByType() {
	std::cout << "What is the type of material you want to see?";
	std::string type;
	std::cin >> type;
	Type indType;
	if (type == "book") {
		indType = Type::BOOK;
	}
	else if (type == "journal") {
		indType = Type::JOURNAL;
	}
	else if (type == "newspaper") {
		indType = Type::NEWSPAPER;
	}

	for (auto [key, value]: map_) {
		if (value->getType() == indType) {
			value->printDetailedInfo();
		}
	}
}

void Management::exit() {
	is_done_ = true;
}

void Management::run() {
	int option;
	is_done_ = false;
	while (!is_done_) {
		printMenu();
		std::cout << "Please pick an option: ";
		std::cin >> option;
		std::cout << '\n';
		if (option == 1) {
			getInfoforInsertion();
		}
		else if (option == 2) {
			deleteMaterial();
		}
		else if (option == 3) {
			showInfoByCode();
		}
		else if (option == 4) {
			showByType();
		}
		else if (option == 5) {
			exit();
		}
	}
}
