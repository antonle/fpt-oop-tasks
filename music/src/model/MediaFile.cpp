#include "MediaFile.h"

// con and des

MediaFile::MediaFile(const std::string& path): path_(path), music_(TagLib::FileRef(path.c_str())) {}

MediaFile::~MediaFile() {}

MediaFile::MediaFile(const MediaFile& other): MediaFile(other.path_) {}

MediaFile& MediaFile::operator=(const MediaFile& other) {
	path_ = other.path_;

	return *this;
}

// getter and setter

const std::string& MediaFile::getPath() const {
	return path_;
}

void MediaFile::setPath(const std::string& path) {
	path_ = path;
}

TagLib::String MediaFile::getName() const {
	if (isValid()) {
		return music_.tag()->title();
	}

	return "Unknown";
}

TagLib::String MediaFile::getArtist() const {
	if (isValid()) {
		return music_.tag()->artist();
	}

	return "Unknown";
}

TagLib::String MediaFile::getGenre() const {
	if (isValid()) {
		return music_.tag()->genre();
	}

	return "Unknown";
}

int MediaFile::getYear() const {
	if (isValid()) {
		return music_.tag()->year();
	}

	return 9999;
}

void MediaFile::setName(const std::string& name) {
	if (isValid()) {
		music_.tag()->setTitle(name);
	}
}

void MediaFile::setArtist(const std::string& artist) {
	if (isValid()) {
		music_.tag()->setArtist(artist);
	}
}

void MediaFile::setGenre(const std::string& genre) {
	if (isValid()) {
		music_.tag()->setGenre(genre);
	}
}

void MediaFile::setYear(int year) {
	if (isValid()) {
		music_.tag()->setYear(year);
	}
}

// checker

bool MediaFile::isValid() const {
	return !music_.isNull() && music_.tag();
}
