/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IBullet.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <abossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:37:54 by abossi            #+#    #+#             */
/*   Updated: 2017/10/08 16:21:04 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IBULLET_CLASS_HPP
#define IBULLET_CLASS_HPP

#include <iostream>
#include "Entity.class.hpp"

class IBullet
{

public:
	virtual ~IBullet();
	virtual void		move(void) = 0;
	virtual void		makeDamage(Entity & victim) = 0;
	virtual std::string	getC(void) const = 0;
	virtual void		setC(std::string c) = 0;
	virtual int			getX(void) const = 0;
	virtual int			getY(void) const = 0;
	virtual int			getColor(void) = 0;
	virtual void		setColor(int color) = 0;
	virtual int			getDir(void) const = 0;
	virtual void		setDir(int pos) = 0;
	virtual bool		toDelete(void) const = 0;

private:
};

#endif
