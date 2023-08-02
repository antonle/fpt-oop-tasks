#pragma once

#include <string>
#include <iostream>

class Student {
public:
	Student(const std::string& name, int age, const std::string& origin, const std::string& classroom);
	~Student();
	Student(const Student& other);
	Student& operator=(const Student& other);

	void printInfo() const;

	int getAge() const;
	std::string getOrigin() const;

private:
	std::string name_;
	int age_;
	std::string origin_;
	std::string classroom_;
};
