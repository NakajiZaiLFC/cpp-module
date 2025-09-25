#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iomanip>
#include <sstream>

#define SAY_HI "Hi! This is My Awesome PhoneBook!\n"
#define SELECT_PROMPT "Notice: You can use \"ADD\",\"SEARCH\",\"EXIT\"\n"
#define SAY_GOODBYE "Thank you for using My Awesome PhoneBook!\n"
#define PHONEBOOK_IS_EMPTY "Error: PhoneBook is Empty"
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

	void handleSearchCommand();
	void handleAddCommand();
private:
	Contact m_contacts[8];
	int m_index;
	int m_contactCount;
	//ADD
	bool handlePrompt(std::string prompt, std::string &tmp_variable, Contact &tmp_contact);
	void addContact(const Contact &new_contact);
	bool strValidate(std::string str, std::string prompt);
	bool strIsSpace(std::string str);
	bool phoneNumValidate(std::string str);
	void callSetter(std::string prompt, std::string &tmp_valiable, Contact &new_contact);

	//SEARCH
	bool displaySummaryList(void);
	void displayColumn(int i);
	void displayHeader(void);
	bool index_validation(int search_index);
	void displayIndexRecord(int m_index);
	std::string formatForDisplay(const std::string &str);
};

#endif