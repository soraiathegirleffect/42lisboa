#include <unistd.h>

void	rotone(char *str)
{
	int	i;
	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')
				str[i] = str[i] + 1;
		else if (str[i] == 'Z' || str[i] == 'z')
				str[i] = str[i] - 52;
		write (1, &str[i], 1);
		i++;
	}
}

int	main (int ac, char **av)
{
	if (ac == 2)
		rotone(av[1]);
	write(1, "\n", 1);
}
