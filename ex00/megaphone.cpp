#include <iostream>
#define CASE_ARGC_1 1

int main(int argc, char **argv)
{
	char c;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (CASE_ARGC_1);
	}
	for (int i = 1; i < argc; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
			std::cout << std::toupper(argv[i][j]);
	}
	std::cout << std::endl;
	return (0);
}
