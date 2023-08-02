#pragma once

#include <iostream>
#include <string>

enum class Type {
	BOOK,
	JOURNAL,
	NEWSPAPER
};

class Material {
public:
	Material(const std::string& code, const std::string& publisher, int count, Type type);
	virtual ~Material();
	Material(const Material& other);
	Material& operator=(const Material& other);

	virtual void printDetailedInfo() const = 0;
	void printGeneralInfo() const;

	Type getType() const;

protected:
	std::string code_;
	std::string publisher_;
	int count_;
	Type type_;
};
