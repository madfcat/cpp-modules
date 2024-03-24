/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/23 22:43:05 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/24 20:31:39 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>

class Weapon
{
	private:
		std::string	type;

	public:
		std::string	getType() const;
		void		setType(std::string type);
		Weapon(std::string type);
		// Weapon() = default;
};
