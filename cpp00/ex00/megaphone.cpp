#include <iostream>

int main(int argc, char **argv)
{
	char c;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	for (int i = 1; argv[i] != '\0'; i++)
	{
		for (int j = 0; argv[i][j] != '\0'; j++)
		{
			c = std::toupper(argv[i][j]);
			std::cout << c;
		}
	}
	std::cout << std::endl;
	return (0);
}
