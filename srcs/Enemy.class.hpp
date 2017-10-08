/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <abossi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 11:57:38 by abossi            #+#    #+#             */
/*   Updated: 2017/10/08 16:18:11 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
#define ENEMY_CLASS_HPP
#include "Entity.class.hpp"
#include "IBullet.class.hpp"

class Enemy : public Entity
{
	public:
		Enemy(int x, int y);
		Enemy(Enemy & src);
		~Enemy(void);

		Enemy &		operator=(Enemy const & rhs);

		IBullet*	fire(void) const;

	private:
		Enemy(void);
};

#endif
