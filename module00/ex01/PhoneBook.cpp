/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:51:50 by vshchuki          #+#    #+#             */
/*   Updated: 2024/04/17 16:08:38 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

void PhoneBook::printIntro(void) const
{
	std::cout << YELLOW;
	std::cout << "=========================================================" << "\n";
	std::cout << WHITE;
	std::cout << "       ___ _      ______________  __  _______         " << "\n";
	std::cout << "      / _ | | /| / / __/ __/ __ \\/  |/  / __/         " << "\n";
	std::cout << "     / __ | |/ |/ / _/_\\ \\/ /_/ / /|_/ / _/           " << "\n";
	std::cout << "    /_/_|_|__/|__/___/___/\\____/_/_ /_/___/____  __ __" << "\n";
	std::cout << "      / _ \\/ // / __ \\/ |/ / __/ _ )/ __ \\/ __ \\/ //_/" << "\n";
	std::cout << "     / ___/ _  / /_/ /    / _// _  / /_/ / /_/ / ,<   " << "\n";
	std::cout << "    /_/  /_//_/\\____/_/|_/___/____/\\____/\\____/_/|_|  " << "\n" << "\n";
	std::cout << YELLOW;
	std::cout << "=========================================================" << "\n";
	std::cout << WHITE;
	std::cout << "You can use the Awesome Phonebook with the next commands:" << "\n";
	std::cout << "ADD, SEARCH and EXIT" << "\n";
	std::cout << "=========================================================" << "\n";
}

void PhoneBook::printErrorMessage(std::string message) const
{
	std::cout << RED << "☹︎ " <<  message << "\n" << RESET;
}

std::string	PhoneBook::truncateField(std::string fieldName) const
{
	size_t MAX_UNTRUNCATED_LENGTH = 10;

	if (fieldName.length() > MAX_UNTRUNCATED_LENGTH)
	{
		fieldName = fieldName.substr(0, MAX_UNTRUNCATED_LENGTH);
		fieldName.replace(9, 1, ".");
	}
	return (fieldName);
}

PhoneBook::PhoneBook()
{
	std::memset(this->contacts, 0, MAX_CONTACTS * sizeof(Contact));
	this->currentIndex = 0;
}

void	PhoneBook::addContact(Contact& contact, int index)
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

void	PhoneBook::incrementCurrentIndex(void)
{
	this->currentIndex++;
}

int	PhoneBook::getCurrentIndex() const
{
	return (this->currentIndex);
}

const Contact&	PhoneBook::getContact(int index) const
{
	return (this->contacts[index]);
}

int	PhoneBook::showAllContacts() const
{
	int i;
	for (i = 0; i < this->currentIndex; i++)
	{
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << this->truncateField(this->contacts[i].getFirstName()) << "|";
		std::cout << std::setw(10) << this->truncateField(this->contacts[i].getLastName()) << "|";
		std::cout << std::setw(10) << this->truncateField(this->contacts[i].getNickname());
		std::cout << "\n";
	}
	return (i);
}

void	PhoneBook::printContactInfo(int index) const
{
	const Contact contact = this->getContact(index);
	std::cout << contact.getFirstName() << "\n";
	std::cout << contact.getLastName() << "\n";
	std::cout << contact.getNickname() << "\n";
	std::cout << contact.getPhoneNumber() << "\n";
	std::cout << contact.getDarkestSecret() << "\n";
}

int	PhoneBook::addContactField(std::string msg, std::string& inputLine,  Contact& contact, MemberFunction func)
{
	std::cout << msg;
	std::getline(std::cin, inputLine);
	if (inputLine.length() == 0)
	{
		this->printErrorMessage( "Try again!");
		return (EXIT_FAILURE);
	}
	(contact.*func)(inputLine);
	inputLine = "";
	return (EXIT_SUCCESS);
}

void	PhoneBook::runAddCommand(void)
{
	std::string	inputLine = "";
	Contact		contact;

	while (this->addContactField("Enter the first name: ", inputLine, contact, &Contact::setFirstName) != EXIT_SUCCESS)
		;
	while (this->addContactField("Enter the last name: ", inputLine, contact, &Contact::setLastName) != EXIT_SUCCESS)
		;
	while (this->addContactField("Enter the nickname: ", inputLine, contact, &Contact::setNickname) != EXIT_SUCCESS)
		;
	while (this->addContactField("Enter the phone number: ", inputLine, contact, &Contact::setPhoneNumber) != EXIT_SUCCESS)
		;
	while (this->addContactField("Enter the darkest secret: ", inputLine, contact, &Contact::setDarkestSecret) != EXIT_SUCCESS)
		;
	this->addContact(contact, this->getCurrentIndex());
	if (this->getCurrentIndex() != MAX_CONTACTS)
		this->incrementCurrentIndex();
}

void	PhoneBook::runSearchCommand(void) const
{
	int i;

	if (!this->showAllContacts())
	{
		this->printErrorMessage("The phonebook is empty!");
		return ;
	}
	while (42)
	{
		std::cout << UNDERLINE << "Please, enter an index" << RESET " (-1 to exit): ";
		std::cin >> i;
		if(std::cin.fail()){
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			this->printErrorMessage("Wrong index format!");
			continue ;
		}
		else if(i < 0)
		{
			std::cin.ignore();
			break ;
		}
		else if(i >= this->getCurrentIndex() || i < 0){
			std::cin.ignore();
			this->printErrorMessage("There is no data corresponing to this index!");
			continue ;
		}
		this->printContactInfo(i);
		std::cin.ignore();
	}
}

void	PhoneBook::run(void)
{
	std::string	command;

	this->printIntro();
	
	while (42)
	{
		std::cout << UNDERLINE;
		std::cout << UNDERLINE << "Please, enter a command" << RESET << ": ";
		std::getline(std::cin, command);

		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			this->runAddCommand();
		}
		else if (command == "SEARCH")
			this->runSearchCommand();
		else
			this->printErrorMessage("No such command!");
		std::cout << "\n";
	}
}
