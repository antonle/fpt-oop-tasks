#pragma once

#include "Material.h"

class Journal: public Material {
public:
	Journal(const std::string& code, const std::string& publisher, int count, int month, int number);
	~Journal();
	Journal(const Journal& other);
	Journal& operator=(const Journal& other);

	void printDetailedInfo() const override;

private:
	int month_;
	int number_;
};
