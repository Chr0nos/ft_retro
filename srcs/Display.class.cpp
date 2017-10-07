/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:30:07 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 14:17:04 by snicolet         ###   ########.fr       */
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

void	Display::flush(void)
{
	refresh();
}
