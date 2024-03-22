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
	std::cout << "    /_/  /_//_/\\____/_/|_/___/____/\\____/\\____/_/|_|  " << std::endl;
	std::cout << YELLOW;
	std::cout << "=========================================================" << std::endl;
	std::cout << WHITE;
	std::cout << "You can use the Awesome Phonebook with the next commands:" << std::endl;
	std::cout << "ADD, SEARCH and EXIT" << std::endl;
	std::cout << "=========================================================" << std::endl;
}

typedef void (Contact::*MemberFunction)(std::string);

int handleInput(std::string msg, std::string& inputLine,  Contact& contact, MemberFunction func)
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

void handleSearch(PhoneBook& phoneBook)
{
	int i;
	while (42)
	{
		std::cout << "Please, enter an index: ";
		std::cin >> i;
		if (i >= phoneBook.getCurrentIndex())
		{
			printErrorMessage("There is no data corresponing to this index!");
			continue ;	
		}
		std::cout << std::setw(10) << i << "|";
		std::cout << std::setw(10) << truncate(phoneBook.getContact(i).getFirstName()) << "|";
		std::cout << std::setw(10) << truncate(phoneBook.getContact(i).getLastName()) << "|";
		std::cout << std::setw(10) << truncate(phoneBook.getContact(i).getNickname());
		std::cout << std::endl;
		std::cin.ignore();
		break ;
	}
}


int main(void)
{
	std::string	command;
	std::string	inputLine = "";
	PhoneBook	phoneBook;
	Contact		contact;

// https://patorjk.com/software/taag/#p=display&f=Bulbhead&t=AWESOME%0APHONEBOOK
// Big, BulbHead, Dancing Font, Doom, Graceful, Ogre, Slant, Small, Small SLant
// Ivrit, JS Stick Letters

	printIntro();

	while (42)
	{
		std::cout << UNDERLINE;
		std::cout << UNDERLINE << "Please, enter a command" << RESET << ": ";
		std::getline(std::cin, command);
		// std::cin.get();

		if (command == "EXIT")
			break ;
		else if (command == "ADD")
		{
			while (handleInput("Enter the first name: ", inputLine, contact, &Contact::setFirstName) != EXIT_SUCCESS)
				;
			while (handleInput("Enter the last name: ", inputLine, contact, &Contact::setLastName) != EXIT_SUCCESS)
				;
			while (handleInput("Enter the nickname: ", inputLine, contact, &Contact::setNickname) != EXIT_SUCCESS)
				;
			while (handleInput("Enter the phone number: ", inputLine, contact, &Contact::setPhoneNumber) != EXIT_SUCCESS)
				;
			while (handleInput("Enter the darkest secret: ", inputLine, contact, &Contact::setDarkestSecret) != EXIT_SUCCESS)
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