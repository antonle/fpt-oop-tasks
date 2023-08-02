#include "Family.h"

Family::Family() {}

Family::Family(const std::string& address, const vsptrPerson& members): address_(address),
																		members_(members)
{}

Family::~Family() {}

Family::Family(const Family& other): Family(other.address_, other.members_) {}

Family& Family::operator=(const Family& other) {
	address_ = other.address_;
	members_ = other.members_;

	return *this;
}

void Family::setAddress(const std::string& address) {
	address_ = address;
}

void Family::addMember(const std::string& name, int age, const std::string& job, const std::string& passport_number) {
	members_.push_back(std::shared_ptr<Person>(new Person(name, age, job, passport_number)));
}

void Family::printFamilyInfo() const {
	std::cout << "House's address: " << address_ << '\n';
	std::cout << "Number of members: " << members_.size() << '\n';
	std::cout << '\n';

	for (int i = 0; i < members_.size(); ++i) {
		std::cout << "Info about member number " << i + 1 << '\n';
		members_[i]->printPersonInfo();
		std::cout << '\n';
	}
}
