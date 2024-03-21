#include "Contact.hpp"

Contact::Contact()
{
	this->firstName = "";
}

Contact::~Contact()
{
	std::cout << "Contact is being destroyed." << std::endl;
}

std::string	Contact::getFirstName()
{
	return (this->firstName);
}

// void Contact::setFirstName(std::string firstName, int count)
void Contact::setFirstName(std::string firstName)
{
	// this->firstName = new char[count + 1];
	// this->firstName[count] = '\0';
	// std::strcpy(firstName, this->firstName);
	this->firstName = firstName;
}