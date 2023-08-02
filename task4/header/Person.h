#pragma once

#include <iostream>
#include <string>

class Person {
public:
	Person(const std::string& name, int age, const std::string& job, const std::string& passport_number);
	~Person();
	Person(const Person& other);
	Person& operator=(const Person& other);

	void printPersonInfo() const;

private:
	std::string name_;
	int age_;
	std::string job_;
	std::string passport_number_;
};
