#pragma once

#include "Room.h"

class RoomB: public Room {
public:
	RoomB();
	~RoomB();
	RoomB(const RoomB& other);
	RoomB& operator=(const RoomB& other);
};
