/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:32:33 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/08 13:08:05 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <ctime>
#include "Game.class.hpp"

int		main(void)
{
	Game		game;

	std::srand(static_cast<unsigned int>(std::time(NULL)));

	if (!game.isReady())
		return (game.sayErr("Please use a decent window size"));
	while (game.start());
	return (0);
}
