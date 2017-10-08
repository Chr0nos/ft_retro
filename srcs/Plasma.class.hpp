/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plasma.class.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <abossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:47:41 by abossi            #+#    #+#             */
/*   Updated: 2017/10/08 18:15:13 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLASMA_CLASS_HPP
#define PLASMA_CLASS_HPP

#include <iostream>
#include "IBullet.class.hpp"
#include "Position.class.hpp"

class Plasma : public Position, public IBullet
{

public:
	Plasma(int x, int y, int dir, int maxX, int color);
	Plasma(Plasma & src);
	~Plasma(void);

	Plasma &	operator=(Plasma const & rhs);

	void		move(void);
	void		makeDamage(Entity & victim);
	std::string	getC(void) const;
	void		setC(std::string c);
	int			getDir(void) const;
	void		setDir(int dir);
	int			getX(void) const;
	int			getY(void) const;
	int			getColor(void);
	void		setColor(int color);
	bool		toDelete(void) const;

private:
	std::string	_c;
	int			_dir;
	bool		_del;
	int			_maxX;
	int			_color;
	int			_startX;

	Plasma(void);

};

#endif
