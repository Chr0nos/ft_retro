/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BulletHolder.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 21:01:40 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 21:46:37 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BULLETHOLDER_CLASS_HPP
# define BULLETHOLDER_CLASS_HPP
# include "IBullet.class.hpp"
# include "Display.class.hpp"

class BulletHolder
{
	public:
						BulletHolder(void);
						BulletHolder(BulletHolder const & src);
						~BulletHolder(void);
		BulletHolder&	operator=(BulletHolder const & src);
		IBullet			*getBullet(unsigned int index) const;
		bool			store(IBullet *bullet);
		void			clear(void);
		unsigned int	move(void);
		void			show(Display &screen) const;

	private:
		void				init(void);
		const static unsigned int	_bulletsCount = 255;
		IBullet				*_bullets[255];
};

#endif
