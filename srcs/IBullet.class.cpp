/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IBullet.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 18:03:23 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 18:41:15 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "IBullet.class.hpp"

IBullet::~IBullet(void)
{
}

std::ostream &	operator<<(std::ostream & o, IBullet const & bul)
{
	o << bul.getC();

	return o;
}
