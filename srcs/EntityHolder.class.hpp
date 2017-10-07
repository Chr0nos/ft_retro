/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntityHolder.class.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: snicolet <snicolet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/07 23:02:52 by snicolet          #+#    #+#             */
/*   Updated: 2017/10/07 23:33:28 by snicolet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITYHOLDER_CLASS_HPP
# define ENTITYHOLDER_CLASS_HPP
# include "Entity.class.hpp"
# include "Display.class.hpp"

class EntityHolder
{
	public:
						EntityHolder(void);
						EntityHolder(EntityHolder const & src);
						~EntityHolder(void);
		EntityHolder&	operator=(EntityHolder const & src);
		void			clear(void);
		Entity*			getItem(unsigned int const index) const;
		bool			store(Entity *entity);
		void			move(void);
		void			show(Display &screen);
		void			remove(unsigned int index);
		unsigned int	count(void) const;

	private:
		void			init(void);
		static const unsigned int _maxItems = 255;
		Entity	*_items[255];
};

#endif
