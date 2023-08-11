#pragma once

#include <taglib/tag.h>
#include <taglib/fileref.h>

#include <string>

class MediaFile {
public:
	// Des and Constructors

	MediaFile(const std::string& path);
	~MediaFile();
	MediaFile(const MediaFile& other);
	MediaFile& operator=(const MediaFile& other);

	// setter and getter

	const std::string& getPath() const;
	void setPath(const std::string& path);

	const TagLib::FileRef& getMusic() const;
	void setMusic(const TagLib::FileRef& other);

	TagLib::String getName() const;
	TagLib::String getArtist() const;
	TagLib::String getGenre() const;
	int getYear() const;

	void setName(const std::string& name);
	void setArtist(const std::string& name);
	void setGenre(const std::string& genre);
	void setYear(int year);

private:
	// checker

	bool isValid() const;

	// members

	std::string path_; // path to music
	TagLib::FileRef music_; // taglib file for interactions
};
