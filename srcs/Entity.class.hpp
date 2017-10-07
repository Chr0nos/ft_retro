/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:42:58 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 16:23:09 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_CLASS_HPP
#define ENTITY_CLASS_HPP

#include <iostream>
#include "Position.class.hpp"

class Entity : public Position
{

public:
	Entity(int x, int y, std::string c, int hp);
	Entity(Entity & src);
	~Entity(void);

	Entity &	operator=(Entity const & rhs);

	int			getHP(void) const;
	void		getDamage(int dmg);
	std::string	getC(void) const;
	void		setC(std::string c);
	void		move(int deltaX, int deltaY);
	bool		isDead(void) const;

private:
	int			_HP;
	std::string	_c;

	Entity(void);

};

#endif
