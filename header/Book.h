#pragma once

#include "Material.h"

class Book: public Material {
public:
	Book(const std::string& code, const std::string& publisher, int count, const std::string& author, int page_count);
	~Book();
	Book(const Book& other);
	Book& operator=(const Book& other);

	void printDetailedInfo() const override;

private:
	std::string author_;
	int page_count_;
};
