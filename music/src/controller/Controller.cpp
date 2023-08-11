#include "Controller.h"

// con and des

Controller::Controller(): model_(Model::createModel()),
						  view_(View::createView()),
						  isDone_(false),
						  isChanged_(false),
						  isAutomatic_(false)
{}

Controller::~Controller() {}

// run loop

void Controller::run() {
	int option = -1;

	std::string path = "";

	while (!isDone_) {
		view_->printMainMenu();
		option = view_->getOptionMainMenu();

		switch (option) {
			case SHOW_MUSIC_FROM_FOLDER:
				view_->getPathToFolder(path);
				showMusicFromFolder(path);

				break;

			case CREATE_PLAYLIST:
				createPlaylist();

				break;

			case DELETE_PLAYLIST:
				deletePlaylist();

				break;

			case SHOW_PLAYLIST:
				showPlaylist();

				break;

			case UPDATE_PLAYLIST:
				updatePlaylist();

				break;

			case SHOW_MEDIA_FILE:
				showMediaFile();

				break;

			case PLAY_OPTIONS:
				playOptions();

				break;

			case CHANGE_VOLUME:
				changeVolume();

				break;

			case OptionMainMenu::EXIT_MAIN_MENU:
				exit();
				break;
		}
	}
}

// functions responsible for options from main menu

void Controller::showMusicFromFolder(const std::string& path) {
	system(("find " + path + " -type f -name " + '"' + "*.mp3" + '"' + " > " + musicFile).c_str());

	view_->printMediaFilesFromFolder();
}

void Controller::createPlaylist() {
	std::string name = "";
	view_->getPlaylistName(name);

	if (model_->checkNamePresent(name)) {
		view_->printNameIsPresent(true);
		return;
	}

	model_->addPlaylist(Playlist(name, {}));
}

void Controller::deletePlaylist() {
	std::string name = "";
	view_->getPlaylistName(name);

	if (!model_->checkNamePresent(name)) {
		view_->printNameIsPresent(false);
	}

	model_->deletePlaylist(name);
}

void Controller::showPlaylist() {
	std::string name = "";
	view_->getPlaylistName(name);

	if (!model_->checkNamePresent(name)) {
		view_->printNameIsPresent(false);
	}

	view_->showPlaylist(model_->getPlaylistByName(name));
}

void Controller::updatePlaylist() {
	std::string name = "";
	view_->getPlaylistName(name);

	if (!model_->checkNamePresent(name)) {
		view_->printNameIsPresent(false);
	}

	view_->printUpdatePlaylistMenu();
	int option = view_->getOptionUpdatePlaylistMenu();

	switch(option) {
		case INSERT_MUSIC:
			insertMusic(name);

			break;

		case DELETE_MUSIC:
			deleteMusic(name);

			break;

		case UPDATE_MEDIA_FILE:
			updateMediaFile(name);

			break;
	}
}

void Controller::showMediaFile() {
	std::string playlistName = "";
	int indMusicInPlaylist = -1;

	view_->getPlaylistName(playlistName);

	if (!model_->checkNamePresent(playlistName)) {
		view_->printNameIsPresent(false);
	}

	indMusicInPlaylist = view_->getSongIndexInPlaylist();

	if (!model_->checkMusicIndex(playlistName, indMusicInPlaylist)) {
		view_->printIndexOutOfRange();
	}

	view_->showMediaFile(model_->getPlaylistByName(playlistName).getSong(indMusicInPlaylist));
}

void Controller::playOptions() {
	view_->printPlayMusicMenu();
	int option = view_->getOptionPlayMusicMenu();

	switch (option) {
		case PLAY:
			playNewSong();

			break;

		case PAUSE:
			pause();

			break;

		case RESUME:
			resume();

			break;

		case NEXT_MUSIC:
			next();

			break;

		case PREVIOUS_MUSIC:
			previous();

			break;

		case PLAY_AUTOMATIC:
			playAutomatic();

			break;

		case STOP_AUTOMATIC:
			stopAutomatic();

			break;
	}
}

void Controller::changeVolume() {
	view_->printChangeVolumeMenu();
	int option = view_->getOptionChangeVolumeMenu();

	switch (option) {
		case INCREASE_VOLUME:
			increaseVolume();

			break;

		case DECREASE_VOLUME:
			decreaseVolume();

			break;
	}
}

void Controller::exit() {
	isDone_ = true;
}

// functions responsible for options from update playlist menu

void Controller::insertMusic(const std::string& name) {
	std::string path = "";

	view_->getSongPath(path);

	model_->addNewSong(name, path);
}

void Controller::deleteMusic(const std::string& name) {
	int indMusicInPlaylist = -1;

	indMusicInPlaylist = view_->getSongIndexInPlaylist();

	if (!model_->checkMusicIndex(name, indMusicInPlaylist)) {
		view_->printIndexOutOfRange();
	}

	model_->deleteMusic(name, indMusicInPlaylist);
}

void Controller::updateMediaFile(const std::string& name) {
	int indMusicInPlaylist = view_->getSongIndexInPlaylist();

	if (!model_->checkMusicIndex(name, indMusicInPlaylist)) {
		view_->printIndexOutOfRange();
	}

	view_->printUpdateMediaFileMenu();
	int option = view_->getOptionUpdateMediaFileMenu();

	switch (option) {
		case CHANGE_NAME:
			changeMediaFileName(name, indMusicInPlaylist);

			break;

		case CHANGE_ARTIST:
			changeMediaFileArtist(name, indMusicInPlaylist);

			break;

		case CHANGE_GENRE:
			changeMediaFileGenre(name, indMusicInPlaylist);

			break;

		case CHANGE_YEAR:
			changeMediaFileYear(name, indMusicInPlaylist);

			break;
	}
}

// functions responsible for options from update media file menu

void Controller::changeMediaFileName(const std::string& name, int index) {
	std::string newName = "";
	view_->getNewNameForMediaFile(newName);

	model_->changeMediaFileName(name, index, newName);
}

void Controller::changeMediaFileArtist(const std::string& name, int index) {
	std::string newArtist = "";
	view_->getNewArtistForMediaFile(newArtist);

	model_->changeMediaFileArtist(name, index, newArtist);
}

void Controller::changeMediaFileGenre(const std::string& name, int index) {
	std::string newGenre = "";
	view_->getNewGenreForMediaFile(newGenre);

	model_->changeMediaFileGenre(name, index, newGenre);
}

void Controller::changeMediaFileYear(const std::string& name, int index) {
	int newYear = view_->getNewYearForMediaFile();

	model_->changeMediaFileYear(name, index, newYear);
}

// functions resposible for options from music menu

void Controller::playNewSong() {
	std::string playlistName = "";
	int songIndex = -1;

	view_->getPlaylistName(playlistName);

	if (!model_->checkNamePresent(playlistName)) {
		view_->printNameIsPresent(false);
		return;
	}

	songIndex = view_->getSongIndexInPlaylist();

	if (model_->checkMusicIndex(playlistName, songIndex)) {
		view_->printIndexOutOfRange();
		return;
	}

	model_->setCurrentPlaylist(playlistName);
	model_->setSongIndex(songIndex);

	{
		std::lock_guard<std::mutex> lg(mutex_);
		isChanged_ = true;
	}

	if (!calledThread_) {
		playSong();
	}
}

void Controller::pause() {
	if (Mix_PlayingMusic() == 1) {
		Mix_PauseMusic();
	}
}

void Controller::resume() {
	if (Mix_PausedMusic() == 1) {
		Mix_ResumeMusic();
	}
}

void Controller::next() {
	if (isNothingOn()) {
		view_->printNothingToNext();
		return;
	}

	if (!model_->isCurrentIndexAbleToNext()) {
		view_->printAlreadyLastSong();
		return;
	}

	{
		std::lock_guard<std::mutex> lg(mutex_);
		model_->setSongIndex(model_->getSongIndex() + 1);
		isChanged_ = true;
	}
}

void Controller::previous() {
	if (isNothingOn()) {
		view_->printNothingToPrevious();
		return;
	}

	if (!model_->isCurrentIndexAbleToPrevious()) {
		view_->printAlreadyFirstSong();
		return;
	}

	{
		std::lock_guard<std::mutex> lg(mutex_);
		model_->setSongIndex(model_->getSongIndex() - 1);
		isChanged_ = true;
	}
}

void Controller::playAutomatic() {
	isAutomatic_ = true;
}

void Controller::stopAutomatic() {
	isAutomatic_ = false;
	isChanged_ = false;
}

void Controller::playSong() {
	calledThread_ = true;

	std::thread musicThread(&Controller::playMusicSDL, this);

	musicThread.detach();
}

// SDL2 related functions

bool Controller::iniSDL() {
	if (SDL_Init(SDL_INIT_AUDIO)) {
		view_->printFailToInitSDL();
		return true;
	}

	Mix_OpenAudio(48000, AUDIO_F32SYS, 2, 2048);

	return false;
}

void Controller::quitSDL() {
	Mix_HaltMusic();
	SDL_Delay(250);

	Mix_CloseAudio();
	Mix_Quit();
	SDL_Quit();
}

bool Controller::isNothingOn() {
	return model_->getCurrentPlaylist() == "";
}

// SDL2 play music

void Controller::playMusicSDL() {
	iniSDL();

	Mix_Music* music = nullptr;

	while (!isDone_) {
		if (!isChanged_) {
			continue;
		}

		{
			std::lock_guard<std::mutex> lg(mutex_);
			isChanged_ = false;
		}

		music = Mix_LoadMUS(model_->getPlaylistByName(model_->getCurrentPlaylist()).getSong(model_->getSongIndex() - 1).getPath().c_str());
		Mix_PlayMusic(music, 1);

		while (Mix_PlayingMusic() && !isChanged_) {
			SDL_Delay(250);
		}

		if (isAutomatic_ && !Mix_PlayingMusic()) {
			std::lock_guard<std::mutex> lg(mutex_);
			if (model_->isCurrentIndexAbleToNext()) {
				model_->setSongIndex(model_->getSongIndex() + 1);
				isChanged_ = true;
			}
			else {
				isAutomatic_ = false;
				isChanged_ = false;
			}
		}

		Mix_HaltMusic();

		Mix_FreeMusic(music);
	}

	quitSDL();
}
