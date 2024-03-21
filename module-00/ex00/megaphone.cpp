#include <iostream>
#include <cctype>

void convertToUpperCase(char *str)
{
	int i = 0;

	while (str[i])
	{
		str[i] = toupper(str[i]);
		i++;
	}
}

int main(int argc, char *argv[])
{
	int i = 1;

	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	while (argv[i])
	{
		convertToUpperCase(argv[i]);
		std::cout << argv[i];
		i++;
	}
	std::cout << std::endl;

	return (0);
}
