#pragma once

#include "Material.h"

class Newspaper: public Material {
public:
	Newspaper(const std::string& code, const std::string& publisher, int count, const std::string& date);
	~Newspaper();
	Newspaper(const Newspaper& other);
	Newspaper& operator=(const Newspaper& other);

	void printDetailedInfo() const override;

private:
	std::string date_;
};
