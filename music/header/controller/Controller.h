#pragma once

#include <thread>
#include <memory>
#include <string>
#include <mutex>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

#include "enums.h"
#include "Model.h"
#include "View.h"

class Controller {
public:
	using sptrModel = std::shared_ptr<Model>;
	using sptrView = std::shared_ptr<View>;

	// Des and constructors

	Controller();
	~Controller();
	Controller(const Controller& other) = default;
	Controller& operator=(const Controller& other) = default;

	// run

	void run();

private:
	// functions responsble for options from main menu

	void showMusicFromFolder(const std::string& path);
	void createPlaylist();
	void deletePlaylist();
	void showPlaylist();
	void updatePlaylist();
	void showMediaFile();
	void playOptions();
	void changeVolume();
	void exit();

	// functions responsible for options from update playlist menu

	void insertMusic(const std::string& name);
	void deleteMusic(const std::string& name);
	void updateMediaFile(const std::string& name);

	// functions responsible for options from update media file menu

	void changeMediaFileName(const std::string& name, int index);
	void changeMediaFileArtist(const std::string& name, int index);
	void changeMediaFileGenre(const std::string& name, int index);
	void changeMediaFileYear(const std::string& name, int index);

	// functions responsible for options from music menu

	void playNewSong();
	void pause();
	void resume();
	void next();
	void previous();
	void playAutomatic();
	void stopAutomatic();
	void playSong();

	// functions responsible for options from volume menu

	void increaseVolume();
	void decreaseVolume();

	// SDL2 related functions

	bool iniSDL();
	void quitSDL();
	bool isNothingOn();
	void playMusicSDL();

	// members

	sptrModel model_; // pointer to only object of class Model
	sptrView view_; // pointer to only object of class View
	bool isDone_; // loop flag
	bool isChanged_; // if there is a change in music
	bool isAutomatic_; // if true plays next when possible
	bool calledThread_; // true if thread is called
	std::mutex mutex_; // lock unlock
};

// SDL2 play music

void playMusicSDL(const Controller::sptrModel& model);
