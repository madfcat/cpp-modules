#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	std::memset(this->contacts, 0, MAX_CONTACTS * sizeof(Contact));
}

PhoneBook::~PhoneBook()
{
	std::cout << "PhoneBook is being destroyed." << std::endl;
}

void PhoneBook::printContactFirstName(int i)
{
	std::cout << "First name is: " << contacts[i].getFirstName() << std::endl;
}

void PhoneBook::addContact(Contact contact)
{
	std::memmove(&this->contacts[1], &this->contacts[0], (MAX_CONTACTS - 1) * sizeof(Contact));
	// std::memcpy(&this->contacts[MAX_CONTACTS - 1], &contact, sizeof(Contact));
	this->contacts[0].setFirstName(contact.getFirstName());
}
