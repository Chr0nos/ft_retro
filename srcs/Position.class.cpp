/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:24:17 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 15:40:43 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Position.class.hpp"

Position::Position(int x, int y) : _x(x), _y(y)
{
}

Position::Position(Position & src)
{
	*this = src;
}

Position::~Position(void)
{
}

Position &	Position::operator=(Position const & rhs)
{
	this->_x = rhs.getX();
	this->_y = rhs.getY();

	return *this;
}

int			Position::getX(void) const
{
	return this->_x;
}

void		Position::setX(int x)
{
	this->_x = x;
}

int			Position::getY(void) const
{
	return this->_y;
}

void		Position::setY(int y)
{
	this->_y = y;
}
