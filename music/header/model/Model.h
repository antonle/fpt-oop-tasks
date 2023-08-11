#pragma once

#include <vector>
#include <memory>

#include "Playlist.h"

class Model {
public:
	using sptrModel = std::shared_ptr<Model>;

	// singleton pattern

	static sptrModel createModel();

	// Des and Constructors

	~Model();
	Model(const Model& other) = delete;
	Model& operator=(const Model& other) = delete;

	// setter and getter

	const std::vector<Playlist>& getCollection() const;
	void setCollection(const std::vector<Playlist>& collection);

	const Playlist& getPlaylistByName(const std::string& name) const;

	const std::string& getCurrentPlaylist() const;
	void setCurrentPlaylist(const std::string& playlist);

	int getSongIndex() const;
	void setSongIndex(int index);

	// add new playlist

	void addPlaylist(const Playlist& playlist);

	// delete playlist by name

	void deletePlaylist(const std::string& name);

	// add new song

	void addNewSong(const std::string& playlistName, const std::string& path);

	// delete song

	void deleteMusic(const std::string& playlistName, int index);

	// change media file

	void changeMediaFileName(const std::string& name, int index, const std::string& newName);
	void changeMediaFileArtist(const std::string& name, int index, const std::string& newArtist);
	void changeMediaFileGenre(const std::string& name, int index, const std::string& newGenre);
	void changeMediaFileYear(const std::string& name, int index, int year);

	// checkers

	bool checkNamePresent(const std::string& name);
	bool checkMusicIndex(const std::string& playlistName, int index);
	bool isCurrentIndexAbleToNext();
	bool isCurrentIndexAbleToPrevious();

private:
	// constructor

	Model();

	// get index of playlist in vector by name

	int getIndexPlaylist(const std::string& name);

	// members

	std::vector<Playlist> collection_; // list of all playlists
	static sptrModel model_; // only 1 instance of the class can be created
	std::string currentPlaylist_; // current playlist
	int songIndex_; // current song index
};
