#include "Student.h"

Student::Student(const std::string& name, int age, const std::string& origin, const std::string& classroom): name_(name),
																											 age_(age),
																											 origin_(origin),
																											 classroom_(classroom)
{}

Student::~Student() {}

Student::Student(const Student& other): Student(other.name_, other.age_, other.origin_, other.classroom_) {}

Student& Student::operator=(const Student& other) {
	name_ = other.name_;
	age_ = other.age_;
	origin_ = other.origin_;
	classroom_ = other.classroom_;

	return *this;
}

void Student::printInfo() const {
	std::cout << "Name: " << name_ << '\n';
	std::cout << "Age: " << age_ << '\n';
	std::cout << "Origin: " << origin_ << '\n';
	std::cout << "Classroom: " << classroom_ << '\n';
	std::cout << '\n';
}

int Student::getAge() const {
	return age_;
}

std::string Student::getOrigin() const {
	return origin_;
}
