#include <unistd.h>

int	main(int ac, char **av)
{
	int i;
	int c;

	i = 0;
	c = 0;
	if (ac == 2)
	{
		while (av[1][i])
		{
			if (av[1][i] >= 'A' && av[1][i] <= 'Z')
			{
				c = av[1][i] - 65;
				while (c >= 0)
				{
					write(1, &av[1][i], 1);
					c--;
				}
			}
			else if (av[1][i] >= 'a' && av[1][i] <= 'z')
			{
				c = av[1][i] - 97;
				while (c >= 0)
				{
					write(1, &av[1][i], 1);
					c--;
				}
			}
			else
				write(1, &av[1][i], 1);
			i++;
		}
	}
	write(1, "\n", 1);
}
