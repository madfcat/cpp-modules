/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:58:24 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/28 18:40:35 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP
# include <string>
# include <iostream>

class Harl
{
	private:
		std::string		levels[4];

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
	
	public:
		Harl();
		void    complain( std::string level );
		int		getFunctionIndex(std::string level);
};

#endif
