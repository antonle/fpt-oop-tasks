#include "Manager.h"

void Manager::run() {
	int option;
	is_done_ = false;
	while (!is_done_) {
		printMenu();
		std::cout << "Please pick an option: ";
		std::cin >> option;
		std::cout << '\n';
		if (option == 1) {
			addNewText();
		}
		else if (option == 2) {
			changeText();
		}
		else if (option == 3) {
			countWords();
		}
		else if (option == 4) {
			countA();
		}
		else if (option == 5) {
			format();
		}
		else if (option == 6) {
			exit();
		}
	}
}


void Manager::printMenu() {
	std::cout << "1. Add a new text.\n";
	std::cout << "2. Change text.\n";
	std::cout << "3. Count words.\n";
	std::cout << "4. Count A.\n";
	std::cout << "5. Format.\n";
	std::cout << "6. Exit.\n";

	std::cout << '\n';
}

void Manager::addNewText() {
	std::cout << "Please input a text: \n";
	std::string text;
	std::cin.ignore();
	std::getline(std::cin, text);
	std::cout << '\n';

	std::cout << "Your text: \n" << text << '\n';
	std::cout << '\n';

	text_ = std::shared_ptr<Text>(new Text(text));
}

void Manager::changeText() {
	std::cout << "Please input your new text: \n";
	std::string text;
	std::cin.ignore();
	std::getline(std::cin, text);
	std::cout << '\n';

	std::cout << "Your new text: \n" << text << '\n';
	std::cout << '\n';

	text_->changeText(text);
}

void Manager::countWords() {
	std::cout << "There are " << text_->countWords() << " words.\n";
	std::cout << '\n';
}

void Manager::countA() {
	std::cout << "There are " << text_->countA() << " A.\n";
	std::cout << '\n';
}

void Manager::format() {
	std::cout << "Formatted text: \n" << text_->formatted() << "\n";
	std::cout << '\n';
}

void Manager::exit() {
	is_done_ = true;
}
