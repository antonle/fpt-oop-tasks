#pragma once

#include <vector>

#include "Employee.h"

class Management {
public:
	Management();

	~Management();

	void run();

private:
	void addNewWorker(const std::string& name, int age, Sex sex, const std::string& address, int level);

	void addNewEngineer(const std::string& name, int age, Sex sex, const std::string& address, const std::string& major);

	void addNewStaff(const std::string& name, int age, Sex sex, const std::string& address, const std::string& job);

	void find(const std::string& name);

	void printAll() const;

	void printMenu() const;

	int getOption() const;

	void getEmployeeInfo();

	std::string getNameToFind() const;

	void done();

	std::vector<Employee*> list_;
	bool isDone;
};

