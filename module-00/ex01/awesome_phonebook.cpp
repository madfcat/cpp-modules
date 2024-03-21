#include "awesome_phonebook.h"

int main()
{
	const 		int MAX_CHARS = 6;
	char 		command[MAX_CHARS];
	std::string		inputLine;
	int			chars_count;
	PhoneBook	phoneBook;
	Contact		contact;

	std::cout << "You can use the Awesome Phonebook with the next commands:" << std::endl;
	std::cout << "ADD, SEARCH and EXIT" << std::endl;

	while(std::strncmp("EXIT", command, chars_count) != 0)
	{

	
		std::cout << "Please, enter a command: ";
		std::cin.getline(command, MAX_CHARS);
		// std::cout << std::endl;

		chars_count = std::cin.gcount();
		if (chars_count > MAX_CHARS)
		{
			std::cout << "The command is too long." << std::endl;
			return (1);
		}

		if (std::strncmp("ADD", command, chars_count) == 0)
		{

			std::cout << "Enter the first name: ";
			std::getline(std::cin, inputLine);
			contact.setFirstName(inputLine);
			// contact.setFirstName(inputLine, strlen(inputLine));
			// delete[] inputLine;
			phoneBook.addContact(contact);
		}
		else
		{
			std::cout << "No such command." << std::endl;
		}

		phoneBook.printContactFirstName(0);
		phoneBook.printContactFirstName(1);
		phoneBook.printContactFirstName(2);
		phoneBook.printContactFirstName(3);
		phoneBook.printContactFirstName(4);
		phoneBook.printContactFirstName(5);
		phoneBook.printContactFirstName(6);
		phoneBook.printContactFirstName(7);
		std::cout << command << std::endl;
	}
	return (0);
}