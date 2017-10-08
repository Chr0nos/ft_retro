/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 14:23:21 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/08 14:44:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Enemy.class.hpp"
#include "Entity.class.hpp"
#include "Gun.class.hpp"

Enemy::Enemy(int x, int y) : Entity::Entity(x, y, "<", 50)
{
}

Enemy::Enemy(Enemy & src) : Entity::Entity(src)
{
}

Enemy::~Enemy(void)
{
	Entity::~Entity();
}

IBullet* Enemy::fire(void) const
{
	return (new Gun(this->getX() - 1, this->getY(), -1, this->getX() + 1));
}
