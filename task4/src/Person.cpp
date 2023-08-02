#include "Person.h"

Person::Person(const std::string& name, int age, const std::string& job, const std::string& passport_number): name_(name),
																											  age_(age),
																											  job_(job),
																											  passport_number_(passport_number)
{}

Person::~Person() {}

Person::Person(const Person& other): Person(other.name_, other.age_, other.job_, other.passport_number_) {}

Person& Person::operator=(const Person& other) {
	name_ = other.name_;
	age_ = other.age_;
	job_ = other.job_;
	passport_number_ = other.passport_number_;

	return *this;
}

void Person::printPersonInfo() const {
	std::cout << "Name: " << name_ << '\n';
	std::cout << "Age: " << age_ << '\n';
	std::cout << "Job: " << job_ << '\n';
	std::cout << "Passport number: " << passport_number_ << '\n';
}
