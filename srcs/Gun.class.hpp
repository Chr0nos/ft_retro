/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gun.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:47:41 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 18:25:00 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GUN_CLASS_HPP
#define GUN_CLASS_HPP

#include <iostream>
#include "IBullet.class.hpp"
#include "Position.class.hpp"

class Gun : public Position, public IBullet
{

public:
	Gun(int x, int y, int dir);
	Gun(Gun & src);
	~Gun(void);

	Gun &	operator=(Gun const & rhs);

	void		move(void);
	void		makeDamage(Entity & victim);
	std::string	getC(void) const;
	void		setC(std::string c);
	int			getDir(void) const;
	void		setDir(int dir);

private:
	std::string	_c;
	int			_dir;

	Gun(void);

};

#endif
