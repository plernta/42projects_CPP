#include <iostream>

int main(int ac, char **av)
{
	int words = 1;
	
	if (ac == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	else
	{
		while (words < ac)
		{
			int j = 0;
			while (av[words][j])
			{
				if (av[words][j] >= 'a' && av[words][j] <= 'z')
					av[words][j] -= 32;
				std::cout << av[words][j];
				j++;
			}
			words++;
		}
		std::cout << std::endl;
	}
	return (0);
}