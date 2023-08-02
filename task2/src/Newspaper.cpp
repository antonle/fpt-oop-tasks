#include "Newspaper.h"

Newspaper::Newspaper(const std::string& code, const std::string& publisher, int count, const std::string& date): Material(code, publisher, count, Type::NEWSPAPER),
	                                                                                              				 date_(date)
{}

Newspaper::~Newspaper() {}

Newspaper::Newspaper(const Newspaper& other): Newspaper(other.code_, other.publisher_, other.count_, other.date_) {}

Newspaper& Newspaper::operator=(const Newspaper& other) {
	code_ = other.code_;
	publisher_ = other.publisher_;
	count_ = other.count_;
	date_ = other.date_;

	return *this;
}

void Newspaper::printDetailedInfo() const {
	printGeneralInfo();
	std::cout << "Type: newspaper\n";
	std::cout << "Date of release: " << date_ << '\n';
	std::cout << '\n';
}
