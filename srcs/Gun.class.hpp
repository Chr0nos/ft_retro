/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Gun.class.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <abossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:47:41 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 21:07:25 by abossi           ###   ########.fr       */
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
	Gun(int x, int y, int dir, int maxX);
	Gun(Gun & src);
	~Gun(void);

	Gun &	operator=(Gun const & rhs);

	void		move(void);
	void		makeDamage(Entity & victim);
	std::string	getC(void) const;
	void		setC(std::string c);
	int			getDir(void) const;
	void		setDir(int dir);
	int			getX(void) const;
	int			getY(void) const;
	bool		toDelete(void) const;

private:
	std::string	_c;
	int			_dir;
	bool		_del;
	int			_maxX;

	Gun(void);

};

#endif
