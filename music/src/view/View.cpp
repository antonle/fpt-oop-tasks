#include "View.h"

// initializing static member

View::sptrView View::view_ = nullptr;

// create single object of the class

View::sptrView View::createView() {
	if (view_ == nullptr) {
		view_ = sptrView(new View());
	}

	return view_;
}

// con and des

View::~View() {}

// interaction with main menu

void View::printMainMenu() {
	std::cout << "1. Show music from folder." << std::endl;
	std::cout << "2. Create playlist." << std::endl;
	std::cout << "3. Delete playlist." << std::endl;
	std::cout << "4. Show playlist." << std::endl;
	std::cout << "5. Update playlist." << std::endl;
	std::cout << "6. Show media file." << std::endl;
	std::cout << "7. Play music." << std::endl;
	std::cout << "8. Change volume." << std::endl;
	std::cout << "9. Exit." << std::endl;
	std::cout << std::endl;
}

void View::printUpdatePlaylistMenu() {
	std::cout << "1. Insert music." << std::endl;
	std::cout << "2. Delete music." << std::endl;
	std::cout << "3. Update media file." << std::endl;
	std::cout << std::endl;
}

void View::printUpdateMediaFileMenu() {
	std::cout << "1. Change name." << std::endl;
	std::cout << "2. Change artist." << std::endl;
	std::cout << "3. Change genre." << std::endl;
	std::cout << "4. Change year." << std::endl;
	std::cout << std::endl;
}

void View::printPlayMusicMenu() {
	std::cout << "1. Play music." << std::endl;
	std::cout << "2. Pause current song." << std::endl;
	std::cout << "3. Resume paused song." << std::endl;
	std::cout << "4. Play next song from album." << std::endl;
	std::cout << "5. Play previous song from album." << std::endl;
	std::cout << "6. Play automatic." << std::endl;
	std::cout << "7. Stop automatic." << std::endl;
	std::cout << std::endl;
}

void View::printChangeVolumeMenu() {
	std::cout << "1. Increase volume." << std::endl;
	std::cout << "2. Decrease volume." << std::endl;
	std::cout << std::endl;
}

int View::getOptionMainMenu() {
	std::cout << "Please pick an option: ";
	int option = -1;
	std::cin >> option;
	std::cout << std::endl;

	return option;
}

int View::getOptionUpdatePlaylistMenu() {
	std::cout << "Please pick an option: ";
	int option = -1;
	std::cin >> option;
	std::cout << std::endl;

	return option;
}

int View::getOptionUpdateMediaFileMenu() {
	int option = -1;
	std::cout << "Please pick an option: ";
	std::cin >> option;
	std::cout << std::endl;

	return option;
}

int View::getOptionPlayMusicMenu() {
	int option = -1;
	std::cout << "Please pick an option: ";
	std::cin >> option;
	std::cout << std::endl;

	return option;
}

int View::getOptionChangeVolumeMenu() {
	int option = -1;
	std::cout << "Please pick an option: ";
	std::cin >> option;
	std::cout << std::endl;

	return option;
}

// helper functions for requests

void View::getPathToFolder(std::string& path) {
	std::cout << "Please enter path to folder with media files: " << std::endl;
	std::cin >> path;
	std::cout << std::endl;
}

void View::getPlaylistName(std::string& name) {
	std::cout << "Please enter name of the playlist: " << std::endl;
	std::cin >> name;
}

void View::getSongPath(std::string& path) {
	std::cout << "Please enter the song path: " << std::endl;
	std::cin >> path;
}

int View::getSongIndexInPlaylist() {
	std::cout << "Please enter the song index inside the playlist: ";
	int index = -1;
	std::cin >> index;
	std::cout << std::endl;

	return index;
}

void View::getNewNameForMediaFile(std::string& name) {
	std::cout << "Please enter a new title: " << std::endl;
	std::cin >> name;
}

void View::getNewArtistForMediaFile(std::string& artist) {
	std::cout << "Please enter a new artist: " << std::endl;
	std::cin >> artist;
}

void View::getNewGenreForMediaFile(std::string& genre) {
	std::cout << "Please enter a new genre: " << std::endl;
	std::cin >> genre;
}

int View::getNewYearForMediaFile() {
	int year;
	std::cout << "Please enter a new year: ";
	std::cin >> year;
	std::cout << std::endl;

	return year;
}

// printing

void View::printNameIsPresent(bool isPresent) {
	std::string helper = isPresent ? "" : "not ";

	std::cout << "Name of playlist is " << helper << "present." << std::endl;
}

void View::showPlaylist(const Playlist& playlist) {
	std::cout << "Name of playlist: " << playlist.getName() << std::endl;

	for (int i = 0; i < playlist.getSize(); ++i) {
		std::cout << i + 1 << ". " << playlist.getSong(i).getName() << std::endl;
	}
}

void View::printMediaFilesFromFolder() {
	std::ifstream myFile(musicFile);

	std::string song = "";

	while (std::getline(myFile, song)) {
		std::cout << song << std::endl;
	}

	std::cout << std::endl;

	myFile.close();
}

void View::showMediaFile(const MediaFile& song) {
	std::cout << "Title: " << song.getName() << std::endl;
	std::cout << "Artist: " << song.getArtist() << std::endl;
	std::cout << "Genre: " << song.getGenre() << std::endl;
	std::cout << "Year: " << song.getYear() << std::endl;
	std::cout << std::endl;
}

void View::printIndexOutOfRange() {
	std::cout << "Index is out of range." << std::endl;
}

void View::printNothingToNext() {
	std::cout << "Nothing was played. You can't next." << std::endl;
}

void View::printAlreadyLastSong() {
	std::cout << "You can't next the last song." << std::endl;
}

void View::printNothingToPrevious() {
	std::cout << "Nothing was played. You can't previous." << std::endl;
}

void View::printAlreadyFirstSong() {
	std::cout << "You can't previous the first song." << std::endl;
}

// SDL2 related messages

void View::printFailToInitSDL() {
	std::cout << "Can't initialize SDL audio." << std::endl;
}

// default constructor

View::View() {}
