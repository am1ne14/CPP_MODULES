#include "PhoneBook.hpp"
#include <iostream>
#include <limits>
#include <iomanip>

PhoneBook::PhoneBook() : count(0), oldest(0) {}

void	PhoneBook::addContact()
{
	Contact	newContact;
	newContact.setContact();
	if (newContact.isEmpty())
	{
		std::cout << "All fields must be filled!" << std::endl;
		return ;
	}
	if (count < 8)
		contacts[count++] = newContact;
	else
	{
		contacts[oldest] = newContact;
		oldest = (oldest + 1) % 8;
	}
	std::cout << "Contact added!" << std::endl;
}

void	PhoneBook::searchContact() const
{
	if (count == 0)
	{
		std::cout << "Phonebook is empty. \n";
		return ;
	}
	std::cout << std::setw(10) << "Index" << "|" << std::setw(10) << "First Name" << "|" << std::setw(10) << "Last Name" << "|" << std::setw(10) << "Nickname" << std::endl;
	for (int i = 0; i < count;i++)
		contacts[i].displayShort(i);
	std::cout << "Enter index to view details: ";
	std::string input;
	std::getline(std::cin, input);
	if (input.length() == 1 && std::isdigit(input[0]))
	{
		int	index = input[0] - '0';
		if (index >= 0 && index < count)
			contacts[index].displayContact();
		else
			std::cout << "Invalid index!" << std::endl;
	}
	else
		std::cout << "invalid input!" << std::endl;

}
