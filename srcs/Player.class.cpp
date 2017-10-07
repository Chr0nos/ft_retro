/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:11:46 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 18:22:14 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.class.hpp"

Player::Player(int x, int y) : Entity(x, y, ">", 1), _weapon("gun")
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
