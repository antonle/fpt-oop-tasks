#include "StudentA.h"

StudentA::StudentA(int id, const std::string& name, const std::string& address, int priority): Student(id, name, address, priority, Type::A, {Subject::Maths, Subject::Physics, Subject::Chemistry}) {}

StudentA::~StudentA() {}

StudentA::StudentA(const StudentA& other): StudentA(other.id_, other.name_, other.address_, other.priority_) {}

StudentA& StudentA::operator=(const StudentA& other) {
	id_ = other.id_;
	name_ = other.name_;
	address_ = other.address_;
	priority_ = other.priority_;
	type_ = other.type_;
	subjects_ = other.subjects_;

	return *this;
}
