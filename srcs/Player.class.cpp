/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <abossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:11:46 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 19:39:12 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player(int x, int y, int maxX) : Entity(x, y, ">", 1), _weapon("gun"), _maxX(maxX - 1)
{
}

Player::Player(Player & src) : Entity(src)
{
	*this = src;
}

Player::~Player(void)
{
}

Player &	Player::operator=(Player const & rhs)
{
	if (this != &rhs)
	{
		this->Entity::operator=(rhs);
	}

	return *this;
}

void				Player::move(int deltaX, int deltaY)
{
	this->setX(this->getX() + deltaX);
	this->setY(this->getY() + deltaY);
	if (this->getY() < 7)
		this->setY(7);
	if (this->getY() > 29)
		this->setY(29);
	if (this->getX() < 0)
		this->setX(0);
	if (this->getX() > this->_maxX)
		this->setX(this->_maxX);

}

std::string const	Player::getWeapon(void) const
{
	return this->_weapon;
}

void				Player::setWeapon(std::string weapon)
{
	this->_weapon = weapon;
}

IBullet *			Player::fire(void)
{
	if (this->_weapon == "gun")
		return new Gun(this->getX() + 1, this->getY(), 1);
	return new Gun(this->getX() + 1, this->getY(), 1);
}
