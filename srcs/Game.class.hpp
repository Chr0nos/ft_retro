/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:28:34 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 17:51:15 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_CLASS_HPP
# define GAME_CLASS_HPP
# include <iostream>
# include <string>
# include "Display.class.hpp"

class Game
{
	public:
					Game(void);
					Game(Game const & src);
					~Game(void);
		Game&		operator=(Game const & src);
		void		start(void);
		bool		isReady(void) const;
		int			sayErr(std::string msg);

	private:
		Display		_screen;

};

#endif
