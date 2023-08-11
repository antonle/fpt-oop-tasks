#pragma once

#include <memory>
#include <iostream>
#include <fstream>
#include <string>

#include "enums.h"
#include "View.h"
#include "Model.h"
#include "Playlist.h"

const std::string musicFile = "/home/anton/fpt_mock/music/musicFile.txt";

class View {
public:
	using sptrView = std::shared_ptr<View>;

	// singleton pattern

	static sptrView createView();

	// Destructor and constructors

	~View();
	View(const View& other) = delete;
	View& operator=(const View& other) = delete;

	// Menu

	void printMainMenu();
	void printUpdatePlaylistMenu();
	void printUpdateMediaFileMenu();
	void printPlayMusicMenu();
	void printChangeVolumeMenu();
	int getOptionMainMenu();
	int getOptionUpdatePlaylistMenu();
	int getOptionUpdateMediaFileMenu();
	int getOptionPlayMusicMenu();
	int getOptionChangeVolumeMenu();

	// Acquire data for controller functions

	void getPathToFolder(std::string& path);
	void getPlaylistName(std::string& name);
	void getSongPath(std::string& path);
	int getSongIndexInPlaylist();
	void getNewNameForMediaFile(std::string& name);
	void getNewArtistForMediaFile(std::string& artist);
	void getNewGenreForMediaFile(std::string& genre);
	int getNewYearForMediaFile();

	// printing

	void printNameIsPresent(bool isPresent);
	void showPlaylist(const Playlist& playlist);
	void printMediaFilesFromFolder();
	void showMediaFile(const MediaFile& song);
	void printIndexOutOfRange();
	void printNothingToNext();
	void printAlreadyLastSong();
	void printNothingToPrevious();
	void printAlreadyFirstSong();

	// SDL2 related messages

	void printFailToInitSDL();

private:
	// default constructor

	View();

	// memebers

	static sptrView view_; // only one instance of this class can be created
};
