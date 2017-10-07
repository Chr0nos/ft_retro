/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Display.class.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 13:30:57 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 14:24:18 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DISPLAY_HPP
# define DISPLAY_HPP
# include <string>
# include <iostream>

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

	private:
		void	init(void);
		bool	_visible;

};

#endif
