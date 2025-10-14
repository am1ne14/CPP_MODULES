#ifndef CONTACT_H
# define CONTACT_H

# include <iostream>
# include <string>

class Contact
{
	private:
		std::string	firstName;
		std::string	lastName;
		std::string	nickName;
		std::string	phoneNumber;
		std::string	darkestSecret;

	public:
		void	setContact();
		void	displayContact() const;
		void	displayShort(int index) const;
		bool	isEmpty() const;
};


# endif
