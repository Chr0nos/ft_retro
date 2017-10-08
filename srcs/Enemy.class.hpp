/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Enemy.class.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 11:57:38 by abossi            #+#    #+#             */
/*   Updated: 2017/10/08 12:10:06 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENEMY_CLASS_HPP
#define ENEMY_CLASS_HPP

class Enemy : public Player
{

public:
	Enemy(int x, int y);
	Enemy(Enemy & src);


private:
	Enemy(void);

}

#endif
