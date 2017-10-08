/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Entity.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <abossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:42:58 by abossi            #+#    #+#             */
/*   Updated: 2017/10/08 14:55:32 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_CLASS_HPP
#define ENTITY_CLASS_HPP

#include <iostream>
#include "Position.class.hpp"

class Entity : public Position
{

public:
	Entity(int x, int y, std::string c, int hp, int color);
	Entity(Entity & src);
	virtual ~Entity(void);

	Entity &	operator=(Entity const & rhs);

	int				getHP(void) const;
	void			setHP(int hp);
	virtual void	setDamage(int dmg);
	std::string		getC(void) const;
	void			setC(std::string c);
	int				getColor(void) const;
	void			setColor(int color);
	void			move(int deltaX, int deltaY);
	bool			isDead(void) const;

private:
	int			_HP;
	std::string	_c;
	int			_color;

	Entity(void);

};

std::ostream &	operator<<(std::ostream & o, Entity const & rhs);

#endif
