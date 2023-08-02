#pragma once

#include <vector>
#include <memory>

#include "Family.h"

class Town {
public:
	using vsptrFamily = std::vector<std::shared_ptr<Family>>;

	Town();
	Town(const vsptrFamily& families);
	~Town();
	Town(const Town& other);
	Town& operator=(const Town& other);

	void addFamily(const std::shared_ptr<Family>& family);
	int getSize() const;

	std::shared_ptr<Family> getFamily(int i);

private:
	vsptrFamily families_;
};
