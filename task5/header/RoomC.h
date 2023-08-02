#pragma once

#include "Room.h"

class RoomC: public Room {
public:
	RoomC();
	~RoomC();
	RoomC(const RoomC& other);
	RoomC& operator=(const RoomC& other);
};

