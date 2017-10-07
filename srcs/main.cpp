/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:32:33 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 15:56:43 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <ctime>
#include <ncurses.h>
#include "Display.class.hpp"

int		main(void)
{
	Display		screen;

	std::srand(static_cast<unsigned int>(std::time(NULL)));
	screen.setVisible(true);
	screen.flush();
	getch();
	return (0);
}
