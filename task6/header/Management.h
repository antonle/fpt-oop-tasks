#pragma once

#include <vector>
#include <memory>
#include <string>
#include <iostream>

#include "Student.h"

class Management {
public:
	using vsptrStudent = std::vector<std::shared_ptr<Student>>;

	void run();

private:
	void printMenu();

	void addNewStudent();
	void showInfoStudentsByAge();
	void showInfoStudentsByAgeAndOrigin();
	void exit();

	vsptrStudent students_;
	bool is_done_;
};
