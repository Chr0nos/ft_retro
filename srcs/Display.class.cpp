/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:30:07 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 16:18:48 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Display.class.hpp"
#include <sstream>

Display::Display(void)
{
	this->init();
}

Display::Display(Display const & src)
{
	*this = src;
}

Display::~Display(void)
{
	this->setVisible(false);
}

Display& Display::operator=(Display const & src)
{
	if (&src != this)
	{
		this->_visible = src.isVisible();
	}
	return (*this);
}

void Display::init(void)
{
	this->_visible = false;
}

bool Display::isVisible(void) const
{
	return (this->_visible);
}

void	Display::setVisible(bool const state)
{
	if ((state) && (this->isVisible()))
		return ;
	else if (state)
		initscr();
	else
		endwin();
	this->_visible = state;
}

void	Display::show(std::string const & message)
{
	if (!this->isVisible())
		return ;
	printw(message.c_str());
}

void	Display::putstr(std::string const & str, unsigned int x, unsigned int y)
{
	move(static_cast<int>(y), static_cast<int>(x));
	printw(str.c_str());
}

void	Display::putstr(std::string const & str, Position const & pos)
{
	this->putstr(str, static_cast<unsigned int>(pos.getX()), static_cast<unsigned int>(pos.getY()));
}

// do the real draw into the screen
void	Display::flush(void)
{
	this->_drawMenu();
	refresh();
}


// this method display the top menu in the game
void	Display::_drawMenu(void)
{
	const unsigned int		width = 200;
	const unsigned int		offsetX = 55;

	// top
	for (unsigned int i = 1; i < width; i++)
		this->putstr("-", i + offsetX, 0);

	// sides
	for (unsigned int i = 1 ; i < 7 ; i++)
	{
		this->putstr("|", 0 + offsetX, i);
		this->putstr("|", width + offsetX, i);
	}

	// bottom
	for (unsigned int i = 1; i < width; i++)
		this->putstr("-", i + offsetX, 6);

	// display of informations
	std::stringstream	infos;

	infos << "enemies alive: " << 42 << " - other field: " << 4;
	this->putstr(infos.str(), 3 + offsetX, 2);

	// repositioning the cursor
	Position	pos(static_cast<int>(offsetX), 10);

	this->setCursorAt(pos);
}

void	Display::setCursorAt(Position const & pos)
{
	move(pos.getY(), pos.getX());
}
