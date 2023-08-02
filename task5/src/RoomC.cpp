#include "RoomC.h"

RoomC::RoomC(): Room(100, Type::C) {}

RoomC::~RoomC() {}

RoomC::RoomC(const RoomC& other): RoomC() {}

RoomC& RoomC::operator=(const RoomC& other) { return *this; }

