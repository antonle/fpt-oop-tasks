#pragma once

#include <memory>
#include <string>
#include <iostream>

#include "Text.h"

class Manager {
public:
	void run();

private:
	void printMenu();
	void addNewText();
	void changeText();
	void countWords();
	void countA();
	void format();
	void exit();

	std::shared_ptr<Text> text_;
	bool is_done_;
};
