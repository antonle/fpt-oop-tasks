#pragma once

#include "Employee.h"

class Staff: public Employee {
public:
	Staff(const std::string& name, int age, Sex sex, const std::string& address, const std::string& job);

	~Staff();

	Staff(const Staff& other);

	Staff& operator=(const Staff& other);

	void printDetailedInfo() const override;

private:
	std::string job_;
};
