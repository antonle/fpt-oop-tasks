#include "RoomB.h"

RoomB::RoomB(): Room(300, Type::B) {}

RoomB::~RoomB() {}

RoomB::RoomB(const RoomB& other): RoomB() {}

RoomB& RoomB::operator=(const RoomB& other) { return *this;}
