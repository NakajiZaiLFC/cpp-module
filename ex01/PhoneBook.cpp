#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
	m_index = 0;
	m_contactCount = 0;
}

PhoneBook::PhoneBook(const PhoneBook &other)
{
	*this = other;
}

PhoneBook &PhoneBook::operator=(const PhoneBook &other)
{
	if (this != &other)
	{
	}
	return *this;
}

PhoneBook::~PhoneBook()
{
}

/**
 * ADD cmd
 */

void PhoneBook::handleAddCommand(void)
{
	Contact tmp(m_contactCount);
	std::string tmp_first_name;
	std::string tmp_last_name;
	std::string tmp_nickname;
	std::string tmp_phone_num;
	std::string tmp_darkset_secret;

	if (!handlePrompt(FIRST_NAME, tmp_first_name, tmp))
		return;
	if (!handlePrompt(LAST_NAME, tmp_last_name, tmp))
		return;
	if (!handlePrompt(NICKNAME, tmp_nickname, tmp))
		return;
	if (!handlePrompt(PHONE_NUM, tmp_phone_num, tmp))
		return;
	if (!handlePrompt(DARKSET_SECRET, tmp_darkset_secret, tmp))
		return;
	std::cout << std::endl;
	addContact(tmp);
}

bool PhoneBook::handlePrompt(std::string prompt, std::string &tmp_variable, Contact &tmp_contact)
{
	while (1)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, tmp_variable))
		{
			std::cout << INPUT_CANCLELED << std::endl;
			return (false);
		}
		if (!strValidate(tmp_variable, prompt))
			std::cout << INVALID_INPUT << std::endl;
		else
			break;
	}
	callSetter(prompt, tmp_variable, tmp_contact);
	return (true);
}

bool PhoneBook::strValidate(std::string str, std::string prompt)
{
	if (str.empty())
		return (false);
	if (!strIsSpace(str))
		return (false);
	if (prompt == PHONE_NUM)
		return (phoneNumValidate(str));
	return (true);
}

bool PhoneBook::strIsSpace(std::string str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!std::isspace(str[i]))
			return (true);
	}
	return (false);
}

bool PhoneBook::phoneNumValidate(std::string str)
{
	for(size_t i = 0; i < str.length(); i++)
	{
		if (!std::isdigit(str[i]))
			return (false);
	}
	if (str.length() == 10 || str.length() == 11)
		return (true);
	return (false);
}

void PhoneBook::callSetter(std::string prompt, std::string &tmp_valiable, Contact &new_contact)
{
	if (prompt == FIRST_NAME)
		new_contact.setFirstName(tmp_valiable);
	else if (prompt == LAST_NAME)
		new_contact.setLastName(tmp_valiable);
	else if (prompt == NICKNAME)
		new_contact.setNickname(tmp_valiable);
	else if (prompt == PHONE_NUM)
		new_contact.setPhoneNum(tmp_valiable);
	else
		new_contact.setDarksetSecret(tmp_valiable);
}

void PhoneBook::addContact(const Contact &tmp)
{
	m_contacts[m_contactCount % 8] = tmp;
	m_contactCount++;
}

/**
 * SEARCH cmd
 */

void PhoneBook::handleSearchCommand(void)
{
	std::string input_index;
	int search_index;

	try
	{
		if (!displaySummaryList())
			return ;
		if (!std::getline(std::cin, input_index))
			return;
		std::stringstream ss(input_index);
		ss >> search_index;
		if (!index_validation(search_index))
		{
			std::cout << INVALID_INDEX << std::endl;
			return;
		}
		displayIndexRecord(search_index % 8);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

bool PhoneBook::displaySummaryList(void)
{
	if (m_contactCount < 1)
	{
		std::cout << PHONEBOOK_IS_EMPTY << std::endl;
		return (false);
	}
	else if (m_contactCount < 8)
	{
		PhoneBook::displayHeader();
		for (int i = 0; i < m_contactCount; i++)
			displayColumn(i);
	}
	else
	{
		PhoneBook::displayHeader();
		for (int i = 0; i < 8; i++)
			displayColumn((m_contactCount - 8 + i) % 8);
	}
	return (true);
}

void PhoneBook::displayHeader(void)
{
	std::cout << "==========================================="<< std::endl;
	std::cout << std::right << std::setw(10) << "index" << "|";
	std::cout << std::right << std::setw(10) << "first name" << "|";
	std::cout << std::right << std::setw(10) << "last name" << "|";
	std::cout << std::right << std::setw(10) << "nickname" << std::endl;
	std::cout << "==========================================="<< std::endl;
}

void PhoneBook::displayColumn(int i)
{
	std::cout << std::right << std::setw(10) << m_contacts[i].getId() << "|";
	std::cout << std::right << std::setw(10) << formatForDisplay(m_contacts[i].getFirstName()) << "|";
	std::cout << std::right << std::setw(10) << formatForDisplay(m_contacts[i].getLastName()) << "|";
	std::cout << std::right << std::setw(10) << formatForDisplay(m_contacts[i].getNickname()) << std::endl;
}

std::string PhoneBook::formatForDisplay(const std::string& str)
{
	std::string result;
	if (str.length() < 10)
		return (str);
	result = str.substr(0, 9) + ".";
	return (result);
}

bool PhoneBook::index_validation(int search_index)
{
	if (m_contactCount < 8)
	{
		if (m_contactCount > search_index && search_index >= 0)
			return (true);
	}
	else
	{
		if (m_contactCount > search_index && search_index > (m_contactCount - 7))
			return (true);
	}
	return (false);
}

void PhoneBook::displayIndexRecord(int m_index)
{
	std::cout << "==========================================="<< std::endl;
	std::cout << std::left << std::setw(20) << FIRST_NAME << m_contacts[m_index].getFirstName() << std::endl;
	std::cout << std::left << std::setw(20) << LAST_NAME << m_contacts[m_index].getLastName() << std::endl;
	std::cout << std::left << std::setw(20) << NICKNAME << m_contacts[m_index].getNickname() << std::endl;
	std::cout << std::left << std::setw(20) << PHONE_NUM << m_contacts[m_index].getPhoneNum() << std::endl;
	std::cout << std::left << std::setw(20) << DARKSET_SECRET << m_contacts[m_index].getDarksetSecret() << std::endl;
	std::cout << "==========================================="<< std::endl;
}

