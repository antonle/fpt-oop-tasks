#pragma once

#include "Student.h"

class StudentC: public Student {
public:
	StudentC(int id, const std::string& name, const std::string& address, int priority);
	~StudentC();
	StudentC(const StudentC& other);
	StudentC& operator=(const StudentC& other);
};
