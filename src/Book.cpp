#include "Book.h"

Book::Book(const std::string& code, const std::string& publisher, int count, const std::string& author, int page_count): Material(code, publisher, count, Type::BOOK),
																										  				 author_(author),
																										 				 page_count_(page_count)
{}

Book::~Book() {}

Book::Book(const Book& other): Book(other.code_, other.publisher_, other.count_, other.author_, other.page_count_) {}

Book& Book::operator=(const Book& other) {
	code_ = other.code_;
	publisher_ = other.publisher_;
	count_ = other.count_;
	author_ = other.author_;
	page_count_ = other.page_count_;

	return *this;
}

void Book::printDetailedInfo() const {
	printGeneralInfo();
	std::cout << "Type: Book" << '\n';
	std::cout << "Author: " << author_ << '\n';
	std::cout << "Number of pages: " << page_count_ << '\n';
	std::cout << '\n';
}
