#pragma once

#include "Employee.h"

class Worker: public Employee {
public:
	Worker(const std::string& name, int age, Sex sex, const std::string& address, int level);

	~Worker();

	Worker(const Worker& other);

	Worker& operator=(const Worker& other);

	void printDetailedInfo() const override;


private:
	int level_;
};
