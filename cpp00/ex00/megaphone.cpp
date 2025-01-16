#include <iostream>

int main(int ac, char **av)
{
    int i;
    int j;

    i = 1;
	if (ac < 2)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    while (i < ac)
	{
        j = 0;
        while (av[i][j] != '\0')
		{
            if (av[i][j] >= 'a' && av[i][j] <= 'z')
                std::cout << (char)(av[i][j] - 32);
            else
                std::cout << av[i][j];
            j++;
        }
        i++;
    }
	std::cout << std::endl;
    return 0;
}
