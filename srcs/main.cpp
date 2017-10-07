/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:32:33 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 17:26:49 by snicolet         ###   ########.fr       */
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
	if ((screen.getCols() < 87) || (screen.getRows() < 16))
	{
		screen.putstr("Please use a decent window size", 0, 0);
		getch();
		return (1);
	}
	screen.flush();
	// screen.debug(std::cout);
	getch();
	return (0);
}
