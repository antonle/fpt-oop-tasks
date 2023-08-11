#include "Playlist.h"

// con and des

Playlist::Playlist(): name_(""), playlist_({}) {}

Playlist::Playlist(const std::string& name, const std::vector<MediaFile>& playlist): name_(name),
																					 playlist_(playlist)
{}

Playlist::~Playlist() {}

Playlist::Playlist(const Playlist& other): Playlist(other.name_, other.playlist_) {}

Playlist& Playlist::operator=(const Playlist& other) {
	name_ = other.name_;
	playlist_ = other.playlist_;

	return *this;
}

// getter and  setter

const std::string& Playlist::getName() const {
	return name_;
}

void Playlist::setName(const std::string& name) {
	name_ = name;
}

const std::vector<MediaFile>& Playlist::getPlaylist() const {
	return playlist_;
}

void Playlist::setPlaylist(const std::vector<MediaFile>& playlist) {
	playlist_ = playlist;
}

const int Playlist::getSize() const {
	return playlist_.size();
}

MediaFile& Playlist::getSong(int i) {
	return playlist_[i];
}

const MediaFile& Playlist::getSong(int i) const {
	return playlist_[i];
}

// add new song

void Playlist::addNewSong(const std::string& path) {
	playlist_.push_back(MediaFile(path));
}

// delete song

void Playlist::deleteMusic(int index) {
	playlist_.erase(playlist_.begin() + index);
}
