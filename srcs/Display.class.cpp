/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:30:07 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 17:22:26 by snicolet         ###   ########.fr       */
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
		this->_win = src.getWin();
		this->_visible = src.isVisible();
	}
	return (*this);
}

WINDOW* Display::getWin(void) const
{
	return (this->_win);
}

void Display::init(void)
{
	this->_win = nullptr;
	this->_visible = false;
	this->_cols = 0;
	this->_rows = 0;
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
	{
		// opening of the display
		initscr();
		getmaxyx(stdscr, this->_rows, this->_cols);
		start_color();
		init_pair(1, COLOR_RED, COLOR_BLACK);
		init_pair(2, COLOR_GREEN, COLOR_BLACK);
		init_pair(3, COLOR_WHITE, COLOR_BLACK);
	}
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
	const unsigned int		width = static_cast<unsigned int>(this->getCols()) - 1;

	attron(COLOR_PAIR(1));
	// top
	for (unsigned int i = 1; i < width; i++)
		this->putstr("-", i, 0);

	// sides
	for (unsigned int i = 1 ; i < 7 ; i++)
	{
		this->putstr("|", 0, i);
		this->putstr("|", width, i);
	}

	// bottom
	for (unsigned int i = 1; i < width; i++)
		this->putstr("-", i, 6);

	// display of informations
	std::stringstream	infos;

	attron(COLOR_PAIR(2));
	infos << "enemies alive: " << 42 << " - other field: " << 4;
	this->putstr(infos.str(), 3, 2);

	// repositioning the cursor
	Position	pos(0, 10);

	attron(COLOR_PAIR(3));
	this->setCursorAt(pos);
}

void	Display::setCursorAt(Position const & pos)
{
	move(pos.getY(), pos.getX());
}

int		Display::getRows(void) const
{
	return (this->_rows);
}

int		Display::getCols(void) const
{
	return (this->_cols);
}

void	Display::debug(std::ostream &target) const
{
	target << "Display: " << this->_win << " [" << this->getCols() << "x" << this->getRows() << "]" << std::endl;
}
