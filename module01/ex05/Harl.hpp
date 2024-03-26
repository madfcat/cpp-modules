/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 15:58:24 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/26 14:22:18 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARLP_HPP
# include <string>

class Harl
{
	private:
		typedef void	(Harl::*MemberFunction)(void);
		std::string		levels[4];
		MemberFunction	functions[4];

		void debug( void );
		void info( void );
		void warning( void );
		void error( void );
		void (Harl::*func)(void);
	
	public:
		Harl();
		void    complain( std::string level );
		MemberFunction getFunction(std::string level);
};

#endif