#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>

#define SAY_HI "Hi! This is My Awesome PhoneBook!\nNotice: You can use \"ADD\",\"SEARCH\",\"EXIT\"\n"
#define SAY_GOODBYE "Thank you for using My Awesome PhoneBook!\n"
#define PHONEBOOK_IS_EMPTY "Error: PhoneBook is Empty\n"
#define COMMAND_IS_INVALID "Error: Command is Invalid\nNotice: You can use \"ADD\",\"SEARCH\",\"EXIT\"\n"
#define INVALID_INDEX "Error: This index is Invalid\n"
#define INVALID_INPUT "Error: The input str is Invalid\nPlease try agein!\n"
#define INPUT_CANCLELED "Notice: Input Canceled\n"

#define FIRST_NAME "First Name: "
#define LAST_NAME "Last Name: "
#define NICKNAME "Nickname: "
#define PHONE_NUM "Phone Number: "
#define DARKSET_SECRET "Darkset Secret: "
#define ADD_DONE "New contact created!"

class PhoneBook
{
public:
	PhoneBook();
	PhoneBook(const PhoneBook &other);
	PhoneBook &operator=(const PhoneBook &other);
	~PhoneBook();
	void addContact(const Contact &new_contact);
	void displayIndexRecord(int m_index);
	void displaySummaryList(void);
	Contact m_contacts[8];
	int m_index;
	int m_contactCount;
	bool index_validation(int search_index);
	void handleSearchCommand();
	void handleAddCommand();
	bool strValidate(std::string str, std::string prompt);
	bool phoneNumValidate(std::string str);
	bool handlePrompt(std::string prompt, std::string &tmp_variable, Contact &tmp_contact);
	void callSetter(std::string prompt, std::string &tmp_valiable, Contact &new_contact);
	bool strIsSpace(std::string str);
	std::string formatForDisplay(const std::string &str);

private:
	void displayColumn(int i);
	void displayHeader(void);
};

#endif
