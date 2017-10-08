/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plasma.class.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <abossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:47:40 by abossi            #+#    #+#             */
/*   Updated: 2017/10/08 18:19:16 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Plasma.class.hpp"

Plasma::Plasma(int x, int y, int dir, int maxX, int color) : Position(x, y), _c("}"), _dir(dir),
													   _del(false), _maxX(maxX),
													   _color(color), _startX(x)
{
}

Plasma::Plasma(Plasma & src) : Position(src)
{
	*this = src;
}

Plasma::~Plasma(void)
{
}

Plasma &		Plasma::operator=(Plasma const & rhs)
{
	if (this != &rhs)
	{
		this->Position::operator=(rhs);
		this->_c = rhs.getC();
		this->_dir = rhs.getDir();
	}

	return *this;
}

void		Plasma::move(void)
{
	this->setX(this->getX() + this->_dir);
	if ((this->getX() - this->_startX) % 4 < 2)
		this->setY(this->getY() - 1);
	else
		this->setY(this->getY() + 1);

	if (this->getX() > this->_maxX || this->getX() < 0)
		this->_del = true;
}

void		Plasma::makeDamage(Entity & victim)
{
	victim.setDamage(100);
}

std::string	Plasma::getC(void) const
{
	return this->_c;
}

void		Plasma::setC(std::string c)
{
	this->_c = c;
}

int			Plasma::getDir(void) const
{
	return this->_dir;
}

void		Plasma::setDir(int dir)
{
	this->_dir = dir;
}

int			Plasma::getX(void) const
{
	return (this->Position::getX());
}

int			Plasma::getY(void) const
{
	return (this->Position::getY());
}

int			Plasma::getColor(void)
{
	return this->_color;
}

void		Plasma::setColor(int color)
{
	this->_color = color;
}

bool		Plasma::toDelete(void) const
{
	return this->_del;
}
