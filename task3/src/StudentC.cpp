#include "StudentC.h"

StudentC::StudentC(int id, const std::string& name, const std::string& address, int priority): Student(id, name, address, priority, Type::C, {Subject::Literature, Subject::History, Subject::Geography}) {}

StudentC::~StudentC() {}

StudentC::StudentC(const StudentC& other): StudentC(other.id_, other.name_, other.address_, other.priority_) {}

StudentC& StudentC::operator=(const StudentC& other) {
	id_ = other.id_;
	name_ = other.name_;
	address_ = other.address_;
	priority_ = other.priority_;
	type_ = other.type_;
	subjects_ = other.subjects_;

	return *this;
}

