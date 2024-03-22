#include "awesome_phonebook.h"

void printIntro(void)
{
	std::cout << YELLOW;
	std::cout << "=========================================================" << std::endl;
	std::cout << WHITE;
	std::cout << "     ___        _______ ____   ___  __  __ _____       " << std::endl;
	std::cout << "    / \\ \\      / / ____/ ___| / _ \\|  \\/  | ____|      " << std::endl;
	std::cout << "   / _ \\ \\ /\\ / /|  _| \\___ \\| | | | |\\/| |  _|        " << std::endl;
	std::cout << "  / ___ \\ V  V / | |___ ___) | |_| | |  | | |___       " << std::endl;
	std::cout << " /_/   \\_\\_/\\_/  |_____|____/ \\___/|_|  |_|_____|      " << std::endl;
	std::cout << "  ____  _   _  ___  _   _ _____ ____   ___   ___  _  __" << std::endl;
	std::cout << " |  _ \\| | | |/ _ \\| \\ | | ____| __ ) / _ \\ / _ \\| |/ /" << std::endl;
	std::cout << " | |_) | |_| | | | |  \\| |  _| |  _ \\| | | | | | | ' / " << std::endl;
	std::cout << " |  __/|  _  | |_| | |\\  | |___| |_) | |_| | |_| | . \\ " << std::endl;
	std::cout << " |_|   |_| |_|\\___/|_| \\_|_____|____/ \\___/ \\___/|_|\\_\\ " << std::endl;
	std::cout << "                                                       " << std::endl;
	std::cout << YELLOW;
	std::cout << "=========================================================" << std::endl;
	std::cout << WHITE;
/* std::cout << "    ___      _____ ___  ___  __  __ ___        " << std::endl;
std::cout << "   /_\\ \\    / / __/ __|/ _ \\|  \\/  | __|       " << std::endl;
std::cout << "  / _ \\ \\/\\/ /| _|\\__ \\ (_) | |\\/| | _|        " << std::endl;
std::cout << " /_/_\\_\\_/\\_/_|___|___/\\___/|_|__|_|___|  _  __" << std::endl;
std::cout << " | _ \\ || |/ _ \\| \\| | __| _ )/ _ \\ / _ \\| |/ /" << std::endl;
std::cout << " |  _/ __ | (_) | .` | _|| _ \\ (_) | (_) | ' < " << std::endl;
std::cout << " |_| |_||_|\\___/|_|\\_|___|___/\\___/ \\___/|_|\\_\\" << std::endl;
std::cout << "                                               " << std::endl; */
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
		std::cout << RED << "☹︎ Try again!" << std::endl << RESET;
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
			std::cout << RED << "☹︎ There is no data corresponing to this index!" << std::endl << RESET;
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
		{
			handleSearch(phoneBook);
		}
		else
		{
			std::cout << RED << "☹︎ No such command!" << std::endl << RESET;
		}
		std::cout << std::endl;
	}

	return (0);
}