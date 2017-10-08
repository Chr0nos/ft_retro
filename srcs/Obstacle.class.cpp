/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:25:21 by abossi            #+#    #+#             */
/*   Updated: 2017/10/08 14:23:03 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.class.hpp"

Obstacle::Obstacle(int x, int y) : Entity(x, y, "#", 3)
{
}

Obstacle::Obstacle(Obstacle & src) : Entity(src)
{
	*this = src;
}

Obstacle::~Obstacle(void)
{
}

Obstacle &	Obstacle::operator=(Obstacle const & rhs)
{
	if (this != &rhs)
	{
		this->Entity::operator=(rhs);
	}

	return *this;
}

void		Obstacle::setDamage(int dmg)
{
	dmg = 0;
	this->setHP(this->getHP() - 1);
	switch(this->getHP())
	{
		case 2:
			this->setC("*");
			break;
		case 1:
			this->setC(".");
			break;
	}
}

void		Obstacle::move(int deltaX, int deltaY)
{
	deltaY = 0;
	deltaX = 0;
}
