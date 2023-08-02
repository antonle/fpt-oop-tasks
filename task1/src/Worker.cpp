#include <iostream>

#include "Worker.h"

Worker::Worker(const std::string& name, int age, Sex sex, const std::string& address, int level): Employee(name, age, sex, address, Indicator::WORKER),
																								      level_(level)
{}

Worker::~Worker() {}

Worker::Worker(const Worker& other): Worker(other.name_, other.age_, other.sex_, other.address_, other.level_) {}

Worker& Worker::operator=(const Worker& other) {
	name_ = other.name_;
	age_ = other.age_;
	sex_ = other.sex_;
	address_ = other.address_;
	level_ = other.level_;

	return *this;
}

void Worker::printDetailedInfo() const {
	printGeneralInfo();
	std::cout << "level: " << level_ << '\n';
	std::cout << '\n';
}
