/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:31:07 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 17:51:32 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include <iostream>
#include <string>

Game::Game(void)
{
	this->_screen.setVisible(true);
}

Game::Game(Game const & src)
{
	*this = src;
}

Game::~Game(void)
{
	std::cout << "game over" << std::endl;
}

Game& Game::operator=(Game const & src)
{
	if (&src != this)
	{
	}
	return (*this);
}

void	Game::start(void)
{
	// place the Display/events loop here
	this->_screen.flush();


	// screen.debug(std::cout);
	getch();
}

bool	Game::isReady(void) const
{
	if ((this->_screen.getCols() < 87) || (this->_screen.getRows() < 16))
		return (false);
	return (true);
}

int		Game::sayErr(std::string msg)
{
	this->_screen.putstr(msg, 0, 0);
	getch();
	return (1);
}
