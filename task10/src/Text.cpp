#include "Text.h"

Text::Text(): text_("") {}

Text::Text(const std::string& text): text_(text) {}

Text::~Text() {}

Text::Text(const Text& other): Text(other.text_) {}

Text& Text::operator=(const Text& other) {
	text_ = other.text_;

	return *this;
}

std::string Text::formatted() const {
	int start = 0;
	while (start < text_.size() && text_[start] == ' ') {
		++start;
	}

	int end = text_.size() - 1;
	while (end > -1 && text_[end] == ' ') {
		--end;
	}

	std::string format_str = "";
	char cur = text_[start];
	char prev;
	for (int i = start; i < end; ++i) {
		if (cur != ' ' || prev != ' ') {
			format_str += cur;
		}
		prev = cur;
		cur = text_[i + 1];
	}
	return format_str;
}

int Text::countWords() const {
	std::string format_str = formatted();

	int count = 1;
	for (int i = 0; i < format_str.size(); ++i) {
		if (format_str[i] == ' ') {
			count += 1;
		}
	}

	return count;
}

int Text::countA() const {
	int count = 0;
	for (int i = 0; i < text_.size(); ++i) {
		if (text_[i] == 'A' || text_[i] == 'a') {
			++count;
		}
	}

	return count;
}

void Text::changeText(const std::string& text) {
	text_ = text;
}
