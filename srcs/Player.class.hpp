/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:11:47 by abossi            #+#    #+#             */
/*   Updated: 2017/10/08 12:17:31 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_CLASS_HPP
#define PLAYER_CLASS_HPP

#include "Entity.class.hpp"
#include "IBullet.class.hpp"
#include "Gun.class.hpp"

class Player : public Entity
{

public:
	Player(int x, int yi, int maxX);
	Player(Player & src);
	~Player(void);

	Player &	operator=(Player const & rhs);

	void				move(int deltaX, int deltaY);
	std::string const	getWeapon(void) const;
	void				setWeapon(std::string weapon);
	IBullet *			fire(void);

private:
	std::string	_weapon;
	int			_maxX;

	Player(void);

};

#endif
