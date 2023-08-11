#include "Model.h"

// initializing static member

Model::sptrModel Model::model_ = nullptr;

// create single object of the class

Model::sptrModel Model::createModel() {
	if (model_ == nullptr) {
		model_ = Model::sptrModel(new Model());
	}

	return model_;
}

// con and des

Model::~Model() {}

// getter and setter

const std::vector<Playlist>& Model::getCollection() const {
	return collection_;
}

void Model::setCollection(const std::vector<Playlist>& collection) {
	collection_ = collection;
}

const Playlist& Model::getPlaylistByName(const std::string& name) const {
	for (int i = 0; i < collection_.size(); ++i) {
		if (collection_[i].getName() == name) {
			return collection_[i];
		}
	}
}

// add new playlist

void Model::addPlaylist(const Playlist& playlist) {
	collection_.push_back(playlist);
}

// delete playlist by name

void Model::deletePlaylist(const std::string& name) {
	int playlistIndex = getIndexPlaylist(name);

	collection_.erase(collection_.begin() + playlistIndex);
}

const std::string& Model::getCurrentPlaylist() const {
	return currentPlaylist_;
}

void Model::setCurrentPlaylist(const std::string& playlist) {
	currentPlaylist_ = playlist;
}

int Model::getSongIndex() const {
	return songIndex_;
}

void Model::setSongIndex(int index) {
	songIndex_ = index;
}

// add new song

void Model::addNewSong(const std::string& playlistName, const std::string& path) {
	int playlistIndex = getIndexPlaylist(playlistName);

	collection_[playlistIndex].addNewSong(path);
}

// delete song

void Model::deleteMusic(const std::string& playlistName, int index) {
	int playlistIndex = getIndexPlaylist(playlistName);

	collection_[playlistIndex].deleteMusic(index - 1);
}

// change media file

void Model::changeMediaFileName(const std::string& name, int index, const std::string& newName) {
	collection_[getIndexPlaylist(name)].getSong(index - 1).setName(newName);
}

void Model::changeMediaFileArtist(const std::string& name, int index, const std::string& newArtist) {
	collection_[getIndexPlaylist(name)].getSong(index - 1).setArtist(newArtist);
}

void Model::changeMediaFileGenre(const std::string& name, int index, const std::string& newGenre) {
	collection_[getIndexPlaylist(name)].getSong(index - 1).setGenre(newGenre);
}

void Model::changeMediaFileYear(const std::string& name, int index, int newYear) {
	collection_[getIndexPlaylist(name)].getSong(index - 1).setYear(newYear);
}

// checkers

bool Model::checkNamePresent(const std::string& name) {
	for (int i = 0; i < collection_.size(); ++i) {
		if (collection_[i].getName() == name) {
			return true;
		}
	}

	return false;
}

bool Model::checkMusicIndex(const std::string& playlistName, int index) {
	if (index >= 1 && index <= collection_[getIndexPlaylist(playlistName)].getSize()) {
		return false;
	}

	return true;
}

bool Model::isCurrentIndexAbleToPrevious() {
	return songIndex_ >= 2;
}

bool Model::isCurrentIndexAbleToNext() {
	return songIndex_ <= collection_[getIndexPlaylist(currentPlaylist_)].getSize() - 1;
}

// default constructor

Model::Model(): collection_({}),
				currentPlaylist_(""),
				songIndex_(-1)
{}

// get index of playlist in vector by name

int Model::getIndexPlaylist(const std::string& name) {
	for (int i = 0; i < collection_.size(); ++i) {
		if (collection_[i].getName() == name) {
			return i;
		}
	}
}
