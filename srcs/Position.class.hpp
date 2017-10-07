/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Position.class.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abossi <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 15:24:14 by abossi            #+#    #+#             */
/*   Updated: 2017/10/07 15:35:26 by abossi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POSITION_CLASS_HPP
#define POSITION_CLASS_HPP

class Position
{

public:
	Position(int x, int y);
	Position(Position & src);
	~Position(void);

	Position &	operator=(Position const & rhs);

	int			getX(void) const;
	void		setX(int x);
	int			getY(void) const;
	void		setY(int y);

private:
	int		_x;
	int		_y;

	Position(void);

};

#endif
