/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:42:56 by abossi            #+#    #+#             */
/*   Updated: 2017/10/08 13:41:52 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Entity.class.hpp"

Entity::Entity(int x, int y, std::string c, int hp) : Position(x, y), _HP(hp), _c(c)
{
}

Entity::Entity(Entity & src) : Position(src)
{
	*this = src;
}

Entity::~Entity(void)
{
}

Entity &	Entity::operator=(Entity const & rhs)
{
	if (this != &rhs)
	{
		this->Position::operator=(rhs);
		this->_HP = rhs.getHP();
	}

	return *this;
}

int			Entity::getHP(void) const
{
	return this->_HP;
}

void		Entity::setHP(int hp)
{
	this->_HP = hp;
}

void		Entity::setDamage(int dmg)
{
	if (this->_HP > 0 && dmg > 0)
		this->_HP -= dmg;
}

std::string	Entity::getC(void) const
{
	return this->_c;
}

void		Entity::setC(std::string c)
{
	this->_c = c;
}

void		Entity::move(int deltaX, int deltaY)
{
	this->setX(this->getX() + deltaX);
	this->setY(this->getY() + deltaY);
}

bool		Entity::isDead(void) const
{
	if (this->_HP <= 0)
		return true;
	return false;
}

std::ostream &	operator<<(std::ostream & o, Entity const & rhs)
{
	o << rhs.getC();

	return o;
}
