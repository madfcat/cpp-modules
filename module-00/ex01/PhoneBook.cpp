/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:51:50 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/22 18:18:35 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iomanip>

std::string truncate(std::string string)
{
	size_t MAX_UNTRUNCATED_LENGTH = 10;

	if (string.length() > MAX_UNTRUNCATED_LENGTH)
	{
		string = string.substr(0, MAX_UNTRUNCATED_LENGTH);
		string.replace(9, 1, ".");
	}
	return (string);
}

PhoneBook::PhoneBook()
{
	std::memset(this->contacts, 0, MAX_CONTACTS * sizeof(Contact));
	this->currentIndex = 0;
}

// PhoneBook::~PhoneBook()
// {
// 	std::cout << "PhoneBook is being destroyed." << std::endl;
// }

void PhoneBook::addContact(Contact& contact, int index)
{
	if (index == MAX_CONTACTS)
	{
		std::memmove(&this->contacts[0], &this->contacts[1], (MAX_CONTACTS - 1) * sizeof(Contact));
		index--;
	}
	this->contacts[index].setFirstName(contact.getFirstName());
	this->contacts[index].setLastName(contact.getLastName());
	this->contacts[index].setNickname(contact.getNickname());
	this->contacts[index].setPhoneNumber(contact.getPhoneNumber());
	this->contacts[index].setDarkestSecret(contact.getDarkestSecret());
}

void PhoneBook::incrementCurrentIndex(void)
{
	this->currentIndex++;
}

Contact& PhoneBook::getContact(int index)
{
	return (this->contacts[index]);
}

int PhoneBook::getCurrentIndex() const
{
	return (this->currentIndex);
}

int PhoneBook::showAllContacts() const
{
	int i;
	for (i = 0; i < this->currentIndex; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << truncate(this->contacts[i].getNickname());
		std::cout << std::endl;
	}
	return (i);
}

void PhoneBook::printContactInfo(int index)
{
	Contact contact = this->getContact(index);
	std::cout << contact.getFirstName() << std::endl;
	std::cout << contact.getLastName() << std::endl;
	std::cout << contact.getNickname() << std::endl;
	std::cout << contact.getPhoneNumber() << std::endl;
	std::cout << contact.getDarkestSecret() << std::endl;
}

// Remove later

/*
void PhoneBook::printContactFirstName(int i)
{
	std::cout << "First name is: " << contacts[i].getFirstName() << std::endl;
}

 void PhoneBook::printContactLastName(int i)
{
	std::cout << "Last name is: " << contacts[i].getLastName() << std::endl;
}

void PhoneBook::printContactNickname(int i)
{
	std::cout << "Nickname is: " << contacts[i].getNickname() << std::endl;
}

void PhoneBook::printContactPhoneNumber(int i)
{
	std::cout << "Phone number is: " << contacts[i].getPhoneNumber() << std::endl;
}

void PhoneBook::printContactDarkestSecret(int i)
{
	std::cout << "Darkest secret is: " << contacts[i].getDarkestSecret() << std::endl;
} */