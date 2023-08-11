#pragma once

#include <vector>
#include <string>

#include "MediaFile.h"

class Playlist {
public:
	// Des and Constructors

	Playlist();
	Playlist(const std::string& name, const std::vector<MediaFile>& playlist);
	~Playlist();
	Playlist(const Playlist& other);
	Playlist& operator=(const Playlist& other);

	// setter and getter

	const std::string& getName() const;
	void setName(const std::string& name);

	const std::vector<MediaFile>& getPlaylist() const;
	void setPlaylist(const std::vector<MediaFile>& playlist);

	const int getSize() const;

	MediaFile& getSong(int i);
	const MediaFile& getSong(int i) const;

	// add new song

	void addNewSong(const std::string& path);

	// delete song
	void deleteMusic(int index);

private:
	// members

	std::vector<MediaFile> playlist_; // list of all songs in a playlist
	std::string name_; // name of the playlist
};
