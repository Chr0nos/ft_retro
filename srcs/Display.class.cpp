/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:30:07 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 18:49:21 by snicolet         ###   ########.fr       */
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
	this->_frame = 0;
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
		raw();
	}
	else
		noraw();
		endwin();
	this->_visible = state;
}

void	Display::show(std::string const & message)
{
	if (!this->isVisible())
		return ;
	printw(message.c_str());
}

void	Display::putstr(std::string const & str, int x, int y)
{
	move(y, x);
	printw(str.c_str());
}

void	Display::putstr(std::string const & str, Position const & pos)
{
	this->putstr(str, pos.getX(), pos.getY());
}

// do the real draw into the screen
void	Display::flush(void)
{
	this->_drawMenu();
	this->_frame++;
	refresh();
}


// this method display the top menu in the game
void	Display::_drawMenu(void)
{
	const int		width = this->getCols() - 1;

	attron(COLOR_PAIR(1));
	// top
	for (int i = 1; i < width; i++)
		this->putstr("-", i, 0);

	// sides
	for (int i = 1 ; i < 7 ; i++)
	{
		this->putstr("|", 0, i);
		this->putstr("|", width, i);
	}

	// bottom
	for (int i = 1; i < width; i++)
		this->putstr("-", i, 6);

	// display of informations
	std::stringstream	infos;

	attron(COLOR_PAIR(2));
	infos << "enemies alive: " << 42 << " - other field: " << 4 << " - frame: " << this->_frame;
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
