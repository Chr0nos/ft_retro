/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityHolder.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 23:04:51 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/08 12:07:22 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntityHolder.class.hpp"

EntityHolder::EntityHolder(void)
{
	this->init();
}

EntityHolder::~EntityHolder(void)
{
	this->clear();
}

void	EntityHolder::init(void)
{
	for (unsigned int i = 0; i < this->_maxItems; i++)
		this->_items[i] = nullptr;
}

void	EntityHolder::clear(void)
{
	for (unsigned int i = 0; i < this->_maxItems; i++)
	{
		if (this->_items[i])
		{
			delete this->_items[i];
			this->_items[i] = nullptr;
		}
	}
}

Entity* EntityHolder::getItem(unsigned int const index) const
{
	if (index >= this->_maxItems)
		return (nullptr);
	return (this->_items[index]);
}

EntityHolder& EntityHolder::operator=(EntityHolder const & src)
{
	if (&src != this)
	{
		for (unsigned int i = 0; i < this->_maxItems; i++)
		{
			this->_items[i] = src.getItem(i);
		}
	}
	return (*this);
}

bool EntityHolder::haveColision(Entity const & ref)
{
	for (unsigned int i = 0; i < this->_maxItems; i++)
	{
		if (this->_items[i] && *(this->_items[i]) == ref)
			return (true);
	}
	return (false);
}

bool EntityHolder::store(Entity* entity)
{
	for (unsigned int i = 0; i < this->_maxItems; i++)
	{
		if (!this->_items[i])
		{
			this->_items[i] = entity;
			return (true);
		}
	}
	return (false);
}

void	EntityHolder::move(void)
{
	Entity	*e;

	for (unsigned int i = 0; i < this->_maxItems; i++)
	{

		e = this->_items[i];
		if (e)
		{
			e->move(-1, 0);
			if (e->isDead())
				this->remove(i);
		}
	}
}

void	EntityHolder::remove(unsigned int index)
{
	if (index >= this->_maxItems)
		return ;
	if (this->_items[index])
	{
		delete this->_items[index];
		this->_items[index] = nullptr;
	}
}

void	EntityHolder::show(Display &screen)
{
	Entity	*e;

	for (unsigned int i = 0; i < this->_maxItems; i++)
	{
		e = this->_items[i];
		if (!e)
			;
		else if (e->getX() > 0)
			screen.putstr(e->getC(), *e);
		else
			this->remove(i);
	}
}

unsigned int EntityHolder::count(void) const
{
	unsigned int		count;

	count = 0;
	for (unsigned int i = 0; i < this->_maxItems; i++)
		if (this->_items[i])
			count++;
	return (count);
}


void		EntityHolder::collisions(BulletHolder & bullets)
{
	const unsigned int max = bullets.getMaxBullets();
	IBullet*			bullet;

	for (unsigned int i = 0; i < max; i++)
	{
		bullet = bullets.getBullet(i);
		for (unsigned int index = 0; index < this->_maxItems; index++)
		{
			Entity	*ent = this->_items[i];
			if ((!ent) || (!bullet));
			else if ((bullet->getX() == ent->getX()) && (bullet->getY() == ent->getY()))
			{
				bullet->makeDamage(*ent);
			}
		}
	}
}
