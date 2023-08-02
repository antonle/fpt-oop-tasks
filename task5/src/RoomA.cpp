#include "RoomA.h"

RoomA::RoomA(): Room(500, Type::A) {}

RoomA::~RoomA() {}

RoomA::RoomA(const RoomA& other): RoomA() {}

RoomA& RoomA::operator=(const RoomA& other) { return *this;}
