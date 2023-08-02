#pragma once

#include "Student.h"

class StudentA: public Student {
public:
	StudentA(int id, const std::string& name, const std::string& address, int priority);
	~StudentA();
	StudentA(const StudentA& other);
	StudentA& operator=(const StudentA& other);
};

