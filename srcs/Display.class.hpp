/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:30:57 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/08 16:27:11 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP
# include <string>
# include <iostream>
# include <curses.h>
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
		void	putstr(std::string const & str, int x, int y);
		void	putstr(std::string const & src, Position const & pos);
		void	setCursorAt(Position const & pos);
		void	setCursorAt(int x, int y);
		WINDOW	*getWin(void) const;
		int		getRows(void) const;
		int		getCols(void) const;
		void	debug(std::ostream &target) const;
		void	clearScreen(void);
		unsigned int getFrame(void) const;
		void	resetFrameCounter(void);


	private:
		void				_drawMenu(void);
		void				init(void);
		bool				_visible;
		int					_rows;
		int					_cols;
		unsigned int		_frame;
		WINDOW	*_win;
};

#endif
