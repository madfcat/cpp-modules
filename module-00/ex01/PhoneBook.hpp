#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# define MAX_CONTACTS 8

# include <iostream>
# include <cstring>

class PhoneBook
{
	private:
		Contact contacts[MAX_CONTACTS];

	public:
		PhoneBook();
		~PhoneBook();

		void addContact(Contact contact);
		void printContactFirstName(int i);
};

#endif
