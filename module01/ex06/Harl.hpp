/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:58:24 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/25 20:29:22 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

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
