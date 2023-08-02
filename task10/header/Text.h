#pragma once

#include <string>
#include <cctype>
#include <iostream>

class Text {
public:
	Text();
	Text(const std::string& text);
	~Text();
	Text(const Text& other);
	Text& operator=(const Text& other);

	std::string formatted() const;
	int countWords() const;
	int countA() const;

	void changeText(const std::string& text);

private:
	std::string text_;
};
