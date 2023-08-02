#pragma once

#include <vector>
#include <string>
#include <memory>
#include <iostream>

#include "Person.h"

class Family {
public:
	using vsptrPerson = std::vector<std::shared_ptr<Person>>;

	Family();
	Family(const std::string& address, const vsptrPerson& members);
	~Family();
	Family(const Family& other);
	Family& operator=(const Family& other);

	void setAddress(const std::string& address);
	void addMember(const std::string& name, int age, const std::string& job, const std::string& passport_number);

	void printFamilyInfo() const;

private:
	std::string address_;
	vsptrPerson members_;
};
