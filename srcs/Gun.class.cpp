/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gun.class.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:47:40 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 18:23:12 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Gun.class.hpp"

Gun::Gun(int x, int y, int dir) : Position(x, y), _c("-"), _dir(dir)
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
}

void		Gun::makeDamage(Entity & victim)
{
	victim.setDamage(100);
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
