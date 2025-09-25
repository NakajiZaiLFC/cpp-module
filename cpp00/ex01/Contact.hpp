#ifndef CONTACT_HPP
#define CONTACT_HPP
#include <iostream>

class Contact
{
	public:
		Contact();
		Contact(int m_index);
		Contact(const Contact &other);
		Contact &operator=(const Contact &other);
		~Contact();

		// ===== index =====
		void setId(int id);
		int getId() const;

		// ===== first name =====
		void setFirstName(const std::string& first_name);
		std::string getFirstName() const;

		// ===== last name =====
		void setLastName(const std::string& last_name);
		std::string getLastName() const;

		// ===== nickname =====
		void setNickname(const std::string& nickname);
		std::string getNickname() const;

		// ===== phone number =====
		void setPhoneNum(const std::string& phone_num);
		std::string getPhoneNum() const;

		// ===== darkset secret =====
		void setDarksetSecret(const std::string& darkset_secret);
		std::string getDarksetSecret() const;

	private:
		int m_id;
		std::string m_first_name;
		std::string m_last_name;
		std::string m_nickname;
		std::string m_phone_num;
		std::string m_darkset_secret;
};

#endif
