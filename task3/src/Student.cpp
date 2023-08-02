#include "Student.h"

Student::Student(int id, const std::string& name, const std::string& address, int priority, Type type, const std::vector<Subject>& subjects): id_(id),
																																			  name_(name),
																																			  address_(address),
																																			  priority_(priority),
																																			  type_(type),
																																			  subjects_(subjects)
{}

Student::~Student() {}

Student::Student(const Student& other): Student(other.id_, other.name_, other.address_, other.priority_, other.type_, other.subjects_) {}

Student& Student::operator=(const Student& other) {
	id_ = other.id_;
	name_ = other.name_;
	address_ = other.address_;
	priority_ = other.priority_;

	return *this;
}

void Student::printInfo() const {
	std::cout << "ID: " << id_ << '\n';
	std::cout << "Name: " << name_ << '\n';
	std::cout << "Address: " << address_ << '\n';
	std::cout << "Priority: " << priority_ << '\n';
	printType();
	printSubjects();
	std::cout << '\n';
}

void Student::printType() const {
	std::cout << "Type: ";
	if (type_ == Type::A) {
		std::cout << "A";
	}
	else if (type_ == Type::B) {
		std::cout << "B";
	}
	else if (type_ == Type::C) {
		std::cout << "C";
	}
	std::cout << '\n';
}

void Student::printSubjects() const {
	std::cout << "Subjects taken: ";
	for (Subject s: subjects_) {
		if (s == Subject::Maths) {
			std::cout << "Maths ";
		}
		else if (s == Subject::Physics) {
			std::cout << "Physics ";
		}
		else if (s == Subject::Chemistry) {
			std::cout << "Chemistry ";
		}
		else if (s == Subject::Biology) {
			std::cout << "Biology ";
		}
		else if (s == Subject::Literature) {
			std::cout << "Literature ";
		}
		else if (s == Subject::History) {
			std::cout << "History ";
		}
		else if (s == Subject::Geography) {
			std::cout << "Geography ";
		}
	}
	std::cout << '\n';
}

int Student::getId() const {
	return id_;
}
