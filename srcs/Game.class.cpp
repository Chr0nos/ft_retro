/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.class.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 17:31:07 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/08 17:19:54 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.class.hpp"
#include "Obstacle.class.hpp"
#include "Player.class.hpp"
#include "BulletHolder.class.hpp"
#include "EntityHolder.class.hpp"
#include "Enemy.class.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <ctime>

Game::Game(void)
{
	this->_screen.setVisible(true);
	this->_eh = nullptr;
	this->_bh = nullptr;
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

// spawn a new enemy randomly at the right of the screen
void	Game::spawnEnemy(void)
{
	Enemy	*enemy = new Enemy(this->_screen.getCols(), 6 + std::rand() % 25);
	IBullet	*shoot;
	if (!this->_eh->store(enemy))
		delete enemy;
	else
	{
		shoot = enemy->fire();
		shoot->setColor(1);
		if (!this->_bh->store(shoot))
			delete shoot;
	}
}

// spawm a new obstacle randomly at the right of the screen
void	Game::spawnObstacle(void)
{
	Obstacle	*truc;

	truc = new Obstacle(this->_screen.getCols(), 6 + std::rand() % 25);
	if (!(this->_eh->store(truc)))
		delete truc;
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
	int					score = 0;

	this->_bh = &bh;
	this->_eh = &eh;
	this->_screen.resetFrameCounter();
	t = 0;
	timeout(0);
	c = getch();
	while (1)
	{
		const int r = std::rand();
		t = std::clock();
		while (std::clock() < (t + 20000 - this->_screen.getFrame() * 2))
		{
			int tmp = getch();
			if (tmp != -1)
				c = tmp;
		}
		if ((c == static_cast<int>('q')) || (c == KEY_EXIT))
			return (false);
		t = (std::clock() - t);

		// Obstacles generation
		if (!(r % 10))
			this->spawnObstacle();
		// enemy generation
		else if (!(r % 15))
			this->spawnEnemy();
		keyString.str("");
		keyString << "t: " << t << " - pos: " <<
			p.getX() << "@" << p.getY() << " - active bullets: " <<
			bh.count() << " - entities alives: " << eh.count() <<
			" - score: " << score;


		this->events(c, p, bh);
		// moving all the bullets
		bh.move();
		score += eh.collisions(bh);

		// player bullet catch and die
		bh.colissions(p);
		if (!(this->_screen.getFrame() % 2))
		{
			eh.move();
			score += eh.collisions(bh);
		}
		if ((eh.haveColision(p)) || (p.isDead()))
			return (true);
		this->refresh(p, keyString);
	}
}

// this is the display part, no computing here
void	Game::refresh(Player & p, std::stringstream const & keyString)
{

	this->_screen.clearScreen();
	this->_screen.putstr(keyString.str(), 2, 5);
	this->_bh->show(this->_screen);
	this->_eh->show(this->_screen);
	attron(COLOR_PAIR(5));
	this->_screen.putstr(p.getC(), p);
	this->_screen.flush();
	this->_screen.setCursorAt(0, 0);
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

// every user event will be treated here
void	Game::events(int & c, Player & p, BulletHolder & bh)
{
	if (c == ' ')
	{
		IBullet		*bullet = p.fire();

		bullet->setColor(4);
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
