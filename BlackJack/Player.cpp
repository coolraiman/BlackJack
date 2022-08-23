#include "Player.h"

bool Player::substractMoney(int amount)
{
	if (amount > money)
		return false;

	money -= amount;
	totalGains -= amount;
	return true;
}