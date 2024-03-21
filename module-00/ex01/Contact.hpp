#ifndef CONTACT_H
# define CONTACT_H
# include <iostream>
# include <cstring>

class Contact
{
	private:
		std::string	firstName;
		// char *lastName;
		// char *nickname;
		// char *phoneNumber;
		// char *darkestSecret;

	public:
		Contact();
		~Contact();

		// void setFirstName(std::string firstName, int count);
		void setFirstName(std::string firstName);
		std::string getFirstName();
};

#endif
