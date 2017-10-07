/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gun.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <abossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:47:40 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 21:08:39 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gun.class.hpp"

Gun::Gun(int x, int y, int dir, int maxX) : Position(x, y), _c("-"), _dir(dir),
											_del(false), _maxX(maxX)
{
}

Gun::Gun(Gun & src) : Position(src)
{
	*this = src;
}

Gun::~Gun(void)
{
}

Gun &		Gun::operator=(Gun const & rhs)
{
	if (this != &rhs)
	{
		this->Position::operator=(rhs);
		this->_c = rhs.getC();
		this->_dir = rhs.getDir();
	}

	return *this;
}

void		Gun::move(void)
{
	this->setX(this->getX() + this->_dir);
	if (this->getX() > this->_maxX)
		this->_del = true;
}

void		Gun::makeDamage(Entity & victim)
{
	victim.setDamage(100);
	this->_del = true;
}

std::string	Gun::getC(void) const
{
	return this->_c;
}

void		Gun::setC(std::string c)
{
	this->_c = c;
}

int			Gun::getDir(void) const
{
	return this->_dir;
}

void		Gun::setDir(int dir)
{
	this->_dir = dir;
}

int			Gun::getX(void) const
{
	return (this->Position::getX());
}

int			Gun::getY(void) const
{
	return (this->Position::getY());
}

bool		Gun::toDelete(void) const
{
	return this->_del;
}
