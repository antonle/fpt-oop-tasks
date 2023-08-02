#include "Material.h"

Material::Material(const std::string& code, const std::string& publisher, int count, Type type): code_(code),
																			   					 publisher_(publisher),
																			   					 count_(count),
																			   				     type_(type)
{}

Material::~Material() {}

Material::Material(const Material& other): Material(other.code_, other.publisher_, other.count_, other.type_) {}

Material& Material::operator=(const Material& other) {
	code_ = other.code_;
	publisher_ = other.publisher_;
	count_ = other.count_;
	type_ = other.type_;

	return *this;
}

void Material::printGeneralInfo() const {
	std::cout << "Code of material: " << code_ << '\n';
	std::cout << "Publisher: " << publisher_ << '\n';
	std::cout << "Number of copies: " << count_ << '\n';
}

Type Material::getType() const {
	return type_;
}
