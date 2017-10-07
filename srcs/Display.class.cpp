/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:30:07 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 15:47:31 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
#include "Display.class.hpp"

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
	move(static_cast<int>(x), static_cast<int>(y));
	printw(str.c_str());
}

void	Display::putstr(std::string const & str, Position const & pos)
{
	this->putstr(str, static_cast<unsigned int>(pos.getX()), static_cast<unsigned int>(pos.getY()));
}

void	Display::flush(void)
{
	refresh();
}
