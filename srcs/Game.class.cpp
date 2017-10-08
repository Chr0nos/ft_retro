/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:31:07 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/08 13:37:00 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "Obstacle.class.hpp"
#include "Player.class.hpp"
#include "BulletHolder.class.hpp"
#include "EntityHolder.class.hpp"
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

// return a boolean: true = need to restart a new game
// false means "hey we'r done here, dont restart"
bool	Game::start(void)
{
	std::clock_t		t;
	int					c;
	std::stringstream	keyString;
	Player				p(10, 10, this->_screen.getCols());
	BulletHolder		bh;
	EntityHolder		eh;

	t = 0;
	timeout(0);
	c = getch();
	while (1)
	{
		t = std::clock();
		while (std::clock() < (t + 15000))
		{
			int tmp = getch();
			if (tmp != -1)
				c = tmp;
		}
		if ((c == static_cast<int>('q')) || (c == KEY_EXIT))
			return (false);
		t = (std::clock() - t);

		// Obstacles generation
		if (!(std::rand() % 20))
		{
			Obstacle	*truc;

			truc = new Obstacle(this->_screen.getCols(), 6 + std::rand() % 25);
			eh.store(truc);
		}
		{
			keyString.str("");
			keyString << "t: " << t << " - pos: " <<
				p.getX() << "@" << p.getY() << " - active bullets: " <<
				bh.count() << " - entities alives: " << eh.count();
		}

		this->events(c, p, bh);
		bh.move();
		if (!(this->_screen.getFrame() % 4))
		{
			eh.move();
		}
		eh.collisions(bh);
		if ((eh.haveColision(p)) || (p.isDead()))
			return (true);
		// don't even dare to put something that display anything on the screen
		// before thoses comments... (clipping prevent)
		this->_screen.clearScreen();
		this->_screen.putstr(keyString.str(), 2, 5);
		bh.show(this->_screen);
		eh.show(this->_screen);
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

void	Game::events(int & c, Player & p, BulletHolder & bh)
{
	if (c == ' ')
	{
		IBullet		*bullet = p.fire();
		if (!bh.store(bullet))
			delete bullet;
	}
	if (!(this->_screen.getFrame() % 2))
		return ;
	if ((c == 'w') || (c == KEY_UP))
		p.move(0, -1);
	else if ((c == 's') || (c == KEY_DOWN))
		p.move(0, 1);
	else if ((c == 'd') || (c == KEY_RIGHT))
		p.move(2, 0);
	else if ((c == 'a') || (c == KEY_LEFT))
		p.move(-2, 0);
	else if (c == 'p')
	{
		timeout(-1);
		while ((c = getch()) != 'p');
		timeout(0);
	}
	c = getch();
}
