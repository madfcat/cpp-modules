/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   awesome_phonebook.cpp                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshchuki <vshchuki@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 17:51:23 by vshchuki          #+#    #+#             */
/*   Updated: 2024/03/22 18:20:41 by vshchuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "awesome_phonebook.h"

void printErrorMessage(std::string message)
{
	std::cout << RED << "☹︎ " <<  message << std::endl << RESET;
}

void printIntro(void)
{
	std::cout << YELLOW;
	std::cout << "=========================================================" << std::endl;
	std::cout << WHITE;
	std::cout << "       ___ _      ______________  __  _______         " << std::endl;
	std::cout << "      / _ | | /| / / __/ __/ __ \\/  |/  / __/         " << std::endl;
	std::cout << "     / __ | |/ |/ / _/_\\ \\/ /_/ / /|_/ / _/           " << std::endl;
	std::cout << "    /_/_|_|__/|__/___/___/\\____/_/_ /_/___/____  __ __" << std::endl;
	std::cout << "      / _ \\/ // / __ \\/ |/ / __/ _ )/ __ \\/ __ \\/ //_/" << std::endl;
	std::cout << "     / ___/ _  / /_/ /    / _// _  / /_/ / /_/ / ,<   " << std::endl;
	std::cout << "    /_/  /_//_/\\____/_/|_/___/____/\\____/\\____/_/|_|  " << std::endl << std::endl;
	std::cout << YELLOW;
	std::cout << "=========================================================" << std::endl;
	std::cout << WHITE;
	std::cout << "You can use the Awesome Phonebook with the next commands:" << std::endl;
	std::cout << "ADD, SEARCH and EXIT" << std::endl;
	std::cout << "=========================================================" << std::endl;
}

int handleAdd(std::string msg, std::string& inputLine,  Contact& contact, MemberFunction func)
{
	std::cout << msg;
	std::getline(std::cin, inputLine);
	if (inputLine.length() == 0)
	{
		printErrorMessage( "Try again!");
		return (EXIT_FAILURE);
	}
	(contact.*func)(inputLine);
	inputLine = "";
	return (EXIT_SUCCESS);
}

void handleSearch(PhoneBook& phoneBook)
{
	int i;

	if (!phoneBook.showAllContacts())
	{
		printErrorMessage("The phonebook is empty!");
		return ;
	}
	while (42)
	{
		std::cout << "Please, enter an index: ";
		std::cin >> i;
		if(std::cin.fail() || i >= phoneBook.getCurrentIndex()){
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			printErrorMessage("There is no data corresponing to this index!");
			break ;
		}
		phoneBook.printContactInfo(i);
		std::cin.ignore();
		continue ;
	}
}


int main(void)
{
	std::string	command;
	std::string	inputLine = "";
	PhoneBook	phoneBook;
	Contact		contact;

	printIntro();
	
	while (42)
	{
		std::cout << UNDERLINE;
		std::cout << UNDERLINE << "Please, enter a command" << RESET << ": ";
		std::getline(std::cin, command);

		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			while (handleAdd("Enter the first name: ", inputLine, contact, &Contact::setFirstName) != EXIT_SUCCESS)
				;
			while (handleAdd("Enter the last name: ", inputLine, contact, &Contact::setLastName) != EXIT_SUCCESS)
				;
			while (handleAdd("Enter the nickname: ", inputLine, contact, &Contact::setNickname) != EXIT_SUCCESS)
				;
			while (handleAdd("Enter the phone number: ", inputLine, contact, &Contact::setPhoneNumber) != EXIT_SUCCESS)
				;
			while (handleAdd("Enter the darkest secret: ", inputLine, contact, &Contact::setDarkestSecret) != EXIT_SUCCESS)
				;
			phoneBook.addContact(contact, phoneBook.getCurrentIndex());
			if (phoneBook.getCurrentIndex() != MAX_CONTACTS)
				phoneBook.incrementCurrentIndex();
		}
		else if (command == "SEARCH")
			handleSearch(phoneBook);
		else
			printErrorMessage("No such command!");
		std::cout << std::endl;
	}

	return (0);
}
