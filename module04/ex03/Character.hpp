/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 13:55:29 by vshchuki          #+#    #+#             */
/*   Updated: 2024/05/19 17:54:30 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP
# include "ICharacter.hpp"
# include <iostream>
# include <string>

class Character: public ICharacter
{
	private:
		std::string name = "Unknown";
		static const int inventorySize = 4;
		AMateria *inventory[inventorySize] = {nullptr};

	public:
		Character();
		Character(const Character& other);
		Character& operator=(const Character& other);
		virtual ~Character() override;

		Character(std::string const & name);

		virtual std::string const & getName() const override;
		virtual void 				equip(AMateria* m) override;
		virtual void 				unequip(int idx) override;
		virtual void 				use(int idx, ICharacter& target) override;

		AMateria* getInventory(int idx) const;
};

#endif