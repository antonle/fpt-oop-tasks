#pragma once

#include "Room.h"

class RoomA: public Room {
public:
	RoomA();
	~RoomA();
	RoomA(const RoomA& other);
	RoomA& operator=(const RoomA& other);
};
