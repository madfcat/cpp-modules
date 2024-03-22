#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::memset(this->contacts, 0, MAX_CONTACTS * sizeof(Contact));
	this->currentIndex = 0;
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook is being destroyed." << std::endl;
}

void PhoneBook::printContactFirstName(int i)
{
	std::cout << "First name is: " << contacts[i].getFirstName() << std::endl;
}

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

// Remove later

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
}