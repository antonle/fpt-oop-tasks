#pragma once

enum class Type {
	A,
	B,
	C
};

class Room {
public:
	Room(int cost, Type type);
	~Room();
	Room(const Room& other);
	Room& operator=(const Room& other);

	int getCost() const;
	Type getType() const;

protected:
	int cost_;
	Type type_;
};
