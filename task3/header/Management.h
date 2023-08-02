#pragma once

#include <vector>
#include <memory>

#include "Student.h"
#include "StudentA.h"
#include "StudentB.h"
#include "StudentC.h"

class Management {
public:
	void run();

private:
	void printMenu();

	void addNewStudent();
	void showAllInfo();
	void findStudentById();
	void exit();

	std::vector<std::shared_ptr<Student>> students_;
	bool is_done_;
};
