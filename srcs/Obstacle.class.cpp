/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.class.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:25:21 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 16:35:00 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Obstacle.class.hpp"

Obstacle::Obstacle(int x, int y) : Entity(x, y, "#", 1)
{
}

Obstacle::Obstacle(Obstacle & src) : Entity(src)
{
	*this = src;
}

Obstacle &	Obstacle::operator=(Obstacle const & rhs)
{
	if (this != &rhs)
	{
		this->Entity::operator=(rhs);
	}

	return *this;
}

void		Obstacle::getDamage(int dmg)
{
	dmg = 0;
}

void		Obstacle::move(int deltaX, int deltaY)
{
	deltaY = 0;
	deltaX = 0;
}
