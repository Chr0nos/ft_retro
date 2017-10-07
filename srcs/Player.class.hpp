/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:11:47 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 18:19:41 by abossi           ###   ########.fr       */
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
	Player(int x, int y);
	Player(Player & src);
	~Player(void);

	Player &	operator=(Player const & rhs);

	std::string const	getWeapon(void) const;
	void				setWeapon(std::string weapon);
	IBullet *			fire(void);

private:
	std::string	_weapon;

	Player(void);

};

#endif
