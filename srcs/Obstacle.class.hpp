/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Obstacle.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 16:25:22 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 16:33:45 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBSTACLE_CLASS_HPP
#define OBSTACLE_CLASS_HPP

#include "Entity.class.hpp"

class Obstacle : public Entity
{

public:
	Obstacle(int x, int y);
	Obstacle(Obstacle & src);

	Obstacle &	operator=(Obstacle const & rhs);

	void		getDamage(int dmg);
	void		move(int deltaX, int deltaY);

private:
	Obstacle(void);

};

#endif
