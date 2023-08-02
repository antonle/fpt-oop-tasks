#pragma once

#include <unordered_map>
#include <memory>

#include "Material.h"
#include "Book.h"
#include "Journal.h"
#include "Newspaper.h"

class Management {
public:
	void run();

private:
	void addNewBook(const std::string& code, const std::string& publisher, int count, const std::string& author, int paper_count);
	void addNewJournal(const std::string& code, const std::string& publisher, int count, int month, int number);
	void addNewNewspaper(const std::string& code, const std::string& publisher, int count, const std::string& date);
	void addNewMaterial();

	void printMenu();
	void getInfoforInsertion();
	void deleteMaterial();
	void showInfoByCode();
	void showByType();
	void exit();

	std::unordered_map<std::string, std::shared_ptr<Material>> map_;
	bool is_done_;
};
