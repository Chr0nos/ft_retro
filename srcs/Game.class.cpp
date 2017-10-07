/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:31:07 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 19:18:18 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "Player.class.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

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
	std::clock_t		t;
	int					c;
	std::stringstream	keyString;
	Player				p(10, 10, this->_screen.getCols());

	timeout(100);
	while (1)
	{
		t = std::clock();
		c = getch();
		if (c == static_cast<int>('q'))
			return ;
		t = std::clock() - t;
		if (c != -1)
		{
			keyString.str("");
			keyString << "last input: " << c << " - t: " << t << " - pos: " << p.getX() << "@" << p.getY();
		}
		this->_screen.clearScreen();
		this->_screen.putstr(keyString.str(), 2, 5);
		//this->_screen.putstr(" ", p.getX(), p.getY());
		if (c == 'w')
			p.move(0, -1);
		else if (c == 's')
			p.move(0, 1);
		else if (c == 'd')
			p.move(2, 0);
		else if (c == 'a')
			p.move(-2, 0);
		else if (c == ' ')
		{
			IBullet		*bullet = p.fire();
			delete bullet;
		}
		// place the Display/events loop here
		this->_screen.putstr(p.getC(), p.getX(), p.getY());
		this->_screen.flush();
	}
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
