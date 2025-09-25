#include "Contact.hpp"

Contact::Contact()
{
	
}

Contact::Contact(int m_index)
{
	setId(m_index);
}

Contact::Contact(const Contact &other)
{
	*this = other;
}

Contact &Contact::operator=(const Contact &other)
{
	if (this != &other)
	{
		this->m_id = other.m_id;
		this->m_first_name = other.m_first_name;
		this->m_last_name = other.m_last_name;
		this->m_nickname = other.m_nickname;
		this->m_phone_num = other.m_phone_num;
		this->m_darkset_secret = other.m_darkset_secret;
	}
	return *this;
}

Contact::~Contact()
{
}

/**
 * ===== setter / getter =====
 */

// ===== index =====

void Contact::setId(int id)
{
	m_id = id;
}

int Contact::getId() const
{
	return (m_id);
}

// ===== first name =====

void Contact::setFirstName(const std::string& first_name)
{
	m_first_name = first_name;
}

std::string Contact::getFirstName() const
{
	return (m_first_name);
}

// ===== last name =====

void Contact::setLastName(const std::string& last_name)
{
	m_last_name = last_name;
}

std::string Contact::getLastName() const
{
	return (m_last_name);
}

// ===== nickname =====

void Contact::setNickname(const std::string& nickname)
{
	m_nickname = nickname;
}

std::string Contact::getNickname() const
{
	return (m_nickname);
}

// ===== phone number =====

void Contact::setPhoneNum(const std::string& phone_num)
{
	m_phone_num = phone_num;
}

std::string Contact::getPhoneNum() const
{
	return (m_phone_num);
}


// ===== darkset secret =====

void Contact::setDarksetSecret(const std::string& darkset_secret)
{
	m_darkset_secret = darkset_secret;
}

std::string Contact::getDarksetSecret() const
{
	return (m_darkset_secret);
}
