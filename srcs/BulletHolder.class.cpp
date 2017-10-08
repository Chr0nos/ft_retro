/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletHolder.class.cpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 21:03:58 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/08 12:26:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BulletHolder.class.hpp"
#include <ncurses.h>

BulletHolder::BulletHolder(void)
{
	this->init();
}

BulletHolder::~BulletHolder(void)
{
	this->clear();
}

void	BulletHolder::clear(void)
{
	for (unsigned int i = 0; i < this->_bulletsCount; i++)
	{
		delete this->_bullets[i];
		this->_bullets[i] = nullptr;
	}
}

void	BulletHolder::init(void)
{
	for (unsigned i = 0; i < this->_bulletsCount; i++)
		this->_bullets[i] = nullptr;
}

IBullet*	BulletHolder::getBullet(unsigned int index) const
{
	if (index >= this->_bulletsCount)
		return (nullptr);
	return (this->_bullets[index]);
}

BulletHolder& BulletHolder::operator=(BulletHolder const & src)
{
	if (&src != this)
	{
		for (unsigned int i = 0; i < this->_bulletsCount; i++)
			this->_bullets[i] = src.getBullet(i);
	}
	return (*this);
}

bool	BulletHolder::store(IBullet *bullet)
{
	for (unsigned int i = 0; i < this->_bulletsCount; i++)
	{
		// free slot available !
		if (!this->_bullets[i])
		{
			this->_bullets[i] = bullet;
			return (true);
		}
	}
	// no more space to store that bullet, it will has to be deleted in the parent
	return (false);
}

unsigned int	BulletHolder::move(void)
{
	unsigned int count = 0;

	for (unsigned int i = 0; i < this->_bulletsCount; i++)
	{
		if (this->_bullets[i])
		{
			count++;
			this->_bullets[i]->move();
			if (this->_bullets[i]->toDelete())
				this->remove(i);
		}
	}
	return (count);
}

void	BulletHolder::show(Display &screen) const
{
	IBullet		*bullet;

	attron(COLOR_PAIR(4));
	for (unsigned int i = 0; i < this->_bulletsCount; i++)
	{
		bullet = this->_bullets[i];
		if (bullet)
			screen.putstr(bullet->getC(), bullet->getX(), bullet->getY());
	}
	attron(COLOR_PAIR(3));
}

unsigned int BulletHolder::getMaxBullets(void) const
{
	return (this->_bulletsCount);
}

void		BulletHolder::remove(unsigned int const index)
{
	if (index >= this->_bulletsCount)
		return ;
	if (this->_bullets[index])
	{
		delete this->_bullets[index];
		this->_bullets[index] = nullptr;
	}
}
