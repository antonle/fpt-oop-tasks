#pragma once

#include "Student.h"

class StudentB: public Student {
public:
	StudentB(int id, const std::string& name, const std::string& address, int priority);
	~StudentB();
	StudentB(const StudentB& other);
	StudentB& operator=(const StudentB& other);
};
