#include <iostream>

#include "Engineer.h"

Engineer::Engineer(const std::string& name, int age, Sex sex, const std::string& address, const std::string& major): Employee(name, age, sex, address, Indicator::ENGINEER),
																											 		 major_(major)
{}

Engineer::~Engineer() {}

Engineer::Engineer(const Engineer& other): Engineer(other.name_, other.age_, other.sex_, other.address_, other.major_) {}

Engineer& Engineer::operator=(const Engineer& other) {
	name_ = other.name_;
	age_ = other.age_;
	sex_ = other.sex_;
	address_ = other.address_;
	major_ = other.major_;

	return *this;
}

void Engineer::printDetailedInfo() const {
	printGeneralInfo();
	std::cout << "major: " << major_ << '\n';
	std::cout << '\n';
}
