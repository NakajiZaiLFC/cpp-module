#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook phone_book;
	std::string input_cmd;
	std::cout << SAY_HI << std::endl;
	while (std::getline(std::cin, input_cmd))
	{
		if (input_cmd == "EXIT")
		{
			std::cout << SAY_GOODBYE << std::endl;
			break;
		}
		else if (input_cmd == "ADD")
			phone_book.handleAddCommand();
		else if (input_cmd == "SEARCH")
			phone_book.handleSearchCommand();
		else
			std::cout << COMMAND_IS_INVALID << std::endl;
	}
	return (0);
}