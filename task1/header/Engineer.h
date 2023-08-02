#pragma once

#include "Employee.h"

class Engineer: public Employee {
public:
	Engineer(const std::string& name, int age, Sex sex, const std::string& address, const std::string& major);

	~Engineer();

	Engineer(const Engineer& other);

	Engineer& operator=(const Engineer& other);

	void printDetailedInfo() const;

private:
	std::string major_;
};

