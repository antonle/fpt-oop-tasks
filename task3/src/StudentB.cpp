#include "StudentB.h"

StudentB::StudentB(int id, const std::string& name, const std::string& address, int priority): Student(id, name, address, priority, Type::B, {Subject::Maths, Subject::Chemistry, Subject::Biology}) {}

StudentB::~StudentB() {}

StudentB::StudentB(const StudentB& other): StudentB(other.id_, other.name_, other.address_, other.priority_) {}

StudentB& StudentB::operator=(const StudentB& other) {
	id_ = other.id_;
	name_ = other.name_;
	address_ = other.address_;
	priority_ = other.priority_;
	type_ = other.type_;
	subjects_ = other.subjects_;

	return *this;
}

