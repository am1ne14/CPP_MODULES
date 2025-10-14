#include "Contact.hpp"
#include <iomanip>

static std::string truncate(std::string str)
{
	if (str.length() > 10)
		return str.substr(0, 9) + ".";
	return str;
}

void	Contact::setContact()
{
	std::string	input;

	std::cout << "First name: ";
	std::getline(std::cin, firstName);
	std::cout << "Last name: ";
	std::getline(std::cin, lastName);
	std::cout << "Nick name: ";
	std::getline(std::cin, nickName);
	std::cout << "Phone number: ";
	std::getline(std::cin, phoneNumber);
	std::cout << "Darkest secret: ";
	std::getline(std::cin, darkestSecret);
}

bool	Contact::isEmpty() const
{
	return (firstName.empty() || lastName.empty() || nickName.empty()
			||  phoneNumber.empty() || darkestSecret.empty());
}
void	Contact::displayShort(int index) const
{
	std::cout << std::setw(10) << index << "|"
		<< std::setw(10) << truncate(firstName) << "|"
		<< std::setw(10) << truncate(lastName) << "|"
		<< std::setw(10) << truncate(nickName) << std::endl;
}

void	Contact::displayContact() const
{
	std::cout << "First name: " << firstName << std::endl;
	std::cout << "Last name: " << lastName << std::endl;
	std::cout << "nickName: " << nickName << std::endl;
	std::cout << "Phone number: " << phoneNumber << std::endl;
	std::cout << "Darkest secret: " << darkestSecret << std::endl;
}
