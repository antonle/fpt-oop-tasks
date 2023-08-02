#include "Town.h"

Town::Town() {}

Town::Town(const vsptrFamily& families): families_(families) {}

Town::~Town() {}

Town::Town(const Town& other): Town(other.families_) {}

Town& Town::operator=(const Town& other) {
	families_ = other.families_;

	return *this;
}

void Town::addFamily(const std::shared_ptr<Family>& family) {
	families_.push_back(family);
}

int Town::getSize() const {
	return families_.size();
}

std::shared_ptr<Family> Town::getFamily(int i) {
	return families_[i];
}
