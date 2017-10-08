/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <abossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:25:21 by abossi            #+#    #+#             */
/*   Updated: 2017/10/08 15:00:45 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.class.hpp"

Obstacle::Obstacle(int x, int y) : Entity(x, y, "#", 20, 3)
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
	this->setHP(this->getHP() - 1);
	dmg = this->getHP();
	if (dmg < 5)
		this->setC(".");
	else if (dmg < 10)
		this->setC("*");
}

void		Obstacle::move(int deltaX, int deltaY)
{
	deltaY = 0;
	deltaX = 0;
}
