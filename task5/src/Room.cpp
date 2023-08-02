#include "Room.h"

Room::Room(int cost, Type type): cost_(cost), type_(type) {}

Room::~Room() {}

Room::Room(const Room& other): Room(other.cost_, other.type_) {}

Room& Room::operator=(const Room& other) {
	cost_ = other.cost_;
	type_ = other.type_;

	return *this;
}

int Room::getCost() const {
	return cost_;
}

Type Room::getType() const {
	return type_;
}
