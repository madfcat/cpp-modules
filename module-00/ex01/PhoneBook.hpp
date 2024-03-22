#ifndef PHONEBOOK_H
# define PHONEBOOK_H

# include "Contact.hpp"
# define MAX_CONTACTS 8

# include <iostream>
# include <cstring>

class PhoneBook
{
	private:
		Contact	contacts[MAX_CONTACTS];
		int		currentIndex;

	public:
		PhoneBook();
		~PhoneBook();

		void 	addContact(Contact& contact, int index);
		void 	incrementCurrentIndex();

		void	printContactFirstName(int i);
		void	printContactLastName(int i);
		void	printContactNickname(int i);
		void	printContactPhoneNumber(int i);
		void	printContactDarkestSecret(int i);

		Contact&	getContact(int index);
		int		getCurrentIndex() const;
};

#endif
