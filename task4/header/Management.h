#pragma once

#include "Town.h"

class Management {
public:
	using sptrTown = std::shared_ptr<Town>;

	Management();

	void run();

private:
	void printMenu();
	void getFamilyInfo();
	void exit();

	void addMembers(int count, const std::string& address);
	void showAllInfo();

	bool is_done_;
	sptrTown town_;
};
