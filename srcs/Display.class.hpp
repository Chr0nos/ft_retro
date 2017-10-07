/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:30:57 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 16:09:54 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP
# include <string>
# include <iostream>
# include "Position.class.hpp"

class Display
{
	public:
		Display(void);
		Display(Display const & src);
		~Display(void);
		void	setVisible(bool const state);
		bool	isVisible(void) const;
		Display& operator=(Display const & src);
		void	show(std::string const & message);
		void	flush(void);
		void	putstr(std::string const & str, unsigned int x, unsigned int y);
		void	putstr(std::string const & src, Position const & pos);
		void	setCursorAt(Position const & pos);


	private:
		void	_drawMenu(void);
		void	init(void);
		bool	_visible;

};

#endif
