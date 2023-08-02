#pragma once

#include <string>

enum class Indicator {
	WORKER,
	ENGINEER,
	STAFF
};

enum class Sex {
	MALE,
	FEMALE,
	OTHER
};

class Employee {
public:
	Employee(const std::string& name, int age, Sex sex, const std::string& address, Indicator indicator);

	virtual ~Employee();

	Employee(const Employee& other);

	Employee& operator=(const Employee& other);

	std::string getName();

	void printGeneralInfo() const;

	virtual void printDetailedInfo() const = 0;

protected:
	std::string name_;
	int age_;
	Sex sex_;
	std::string address_;
	Indicator indicator_;
};

