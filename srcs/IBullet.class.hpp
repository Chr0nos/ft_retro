/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IBullet.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:37:54 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 18:40:51 by abossi           ###   ########.fr       */
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
	virtual int			getDir(void) const = 0;
	virtual void		setDir(int pos) = 0;

private:
};

std::ostream &	operator<<(std::ostream & o, IBullet const & bul);

#endif
