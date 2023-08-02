#include <iostream>

#include "Employee.h"

Employee::Employee(const std::string& name, int age, Sex sex, const std::string& address, Indicator indicator): name_(name),
																								 		  age_(age),
																								 		  sex_(sex),
																								 		  address_(address),
																								 		  indicator_(indicator)
{}

Employee::~Employee() {}

Employee::Employee(const Employee& other): name_(other.name_),
							   age_(other.age_),
							   sex_(other.sex_),
							   address_(other.address_),
							   indicator_(other.indicator_)
{}

Employee& Employee::operator=(const Employee& other) {
		name_ = other.name_;
		age_ = other.age_;
		sex_ = other.sex_;
		address_ = other.address_;
		indicator_ = other.indicator_;

		return *this;
}

std::string Employee::getName() {
	return name_;
}

void Employee::printGeneralInfo() const {
	std::cout << "name: " << name_ << '\n';
	std::cout << "age: " << age_ << '\n';
	std::cout << "address: " << address_ << '\n';
	if (indicator_ == Indicator::WORKER) {
		std::cout << "position: worker\n";
	}
	else if (indicator_ == Indicator::ENGINEER) {
		std::cout << "position: engineer\n";
	}
	else {
		std::cout << "position: staff\n";
	}
}
