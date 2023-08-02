#pragma once

#include <string>
#include <vector>
#include <iostream>

enum class Type {
	A,
	B,
	C
};

enum class Subject {
	Maths,
	Physics,
	Chemistry,
	Biology,
	Literature,
	History,
	Geography
};

class Student {
public:
	Student(int id, const std::string& name, const std::string& address, int priority, Type type, const std::vector<Subject>& subjects);
	~Student();
	Student(const Student& other);
	Student& operator=(const Student& other);

	void printInfo() const;
	void printType() const;
	void printSubjects() const;

	int getId() const;

protected:
	int id_;
	std::string name_;
	std::string address_;
	int priority_;

	Type type_;
	std::vector<Subject> subjects_;
};
