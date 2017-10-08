/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:28:34 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/08 17:16:26 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP
# include <iostream>
# include <string>
# include "Display.class.hpp"
# include "Player.class.hpp"
# include "BulletHolder.class.hpp"
# include "EntityHolder.class.hpp"

class Game
{
	public:
					Game(void);
					Game(Game const & src);
					~Game(void);
		Game&		operator=(Game const & src);
		bool		start(void);
		bool		isReady(void) const;
		int			sayErr(std::string msg);

	private:
		void			refresh(Player & p, std::stringstream const & keyString);
		void			spawnEnemy(void);
		void			spawnObstacle(void);
		void			events(int & c, Player & p, BulletHolder & bh);
		Display			_screen;
		BulletHolder*	_bh;
		EntityHolder*	_eh;

};

#endif
