/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:31:07 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 22:06:59 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "Player.class.hpp"
#include "BulletHolder.class.hpp"
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
#include <time.h>
void	Game::start(void)
{
	std::clock_t		t;
	int					c;
	std::stringstream	keyString;
	Player				p(10, 10, this->_screen.getCols());
	BulletHolder		bh;

	t = 0;
	timeout(50);
	while (1)
	{
		t = std::clock();
		c = getch();
		if ((c == static_cast<int>('q')) || (c == KEY_EXIT))
			return ;
		t = std::clock() - t;
		if (t < 50)
			;

		if (c != -1)
		{
			keyString.str("");
			keyString << "last input: " << c << " - t: " << t << " - pos: " << p.getX() << "@" << p.getY();
		}
		this->_screen.clearScreen();
		this->_screen.putstr(keyString.str(), 2, 5);
		//this->_screen.putstr(" ", p.getX(), p.getY());
		if ((c == 'w') || (c == KEY_UP))
			p.move(0, -1);
		else if ((c == 's') || (c == KEY_DOWN))
			p.move(0, 1);
		else if ((c == 'd') || (c == KEY_RIGHT))
			p.move(2, 0);
		else if ((c == 'a') || (c == KEY_LEFT))
			p.move(-2, 0);
		else if (c == ' ')
		{
			IBullet		*bullet = p.fire();
			if (!bh.store(bullet))
				delete bullet;
		}
		bh.move();
		bh.show(this->_screen);
		this->_screen.putstr(p.getC(), p);
		this->_screen.flush();
		this->_screen.setCursorAt(0, 0);
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
