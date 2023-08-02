#include "Journal.h"

Journal::Journal(const std::string& code, const std::string& publisher, int count, int month, int number): Material(code, publisher, count, Type::JOURNAL),
																										   month_(month),
																										   number_(number)
{}

Journal::~Journal() {}

Journal::Journal(const Journal& other): Journal(other.code_, other.publisher_, other.count_, other.month_, other.number_) {}

Journal& Journal::operator=(const Journal& other) {
	code_ = other.code_;
	publisher_ = other.publisher_;
	count_ = other.count_;
	month_ = other.month_;
	number_ = other.number_;

	return *this;
}

void Journal::printDetailedInfo() const {
	printGeneralInfo();
	std::cout << "Type:: journal\n";
	std::cout << "Month of release: " << month_ << '\n';
	std::cout << "Number of journal: " << number_ << '\n';
	std::cout << '\n';
}
