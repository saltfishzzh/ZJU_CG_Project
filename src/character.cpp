#include "character.h"

Character::Character():
	cordinate(0.0f),
	health_point(100),
	attack(1)
{

}

Character::~Character()
{

}

void Character::move_front()
{
	cordinate[0] += 0.1;
}

void Character::move_back()
{
	cordinate[0] -= 0.1;
}

void Character::move_left()
{
	cordinate[1] += 0.1;
}

void Character::move_right()
{
	cordinate[1] -= 0.1;
}