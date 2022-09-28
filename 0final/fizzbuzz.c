#include <unistd.h>

void	ft_wn(int nr)
{
	char	c;

	if (nr > 9)
		ft_wn(nr / 10);
	c = nr % 10 + 48;
	write(1, &c, 1);
}

int	main(void)
{
	int	number;

	number = 1;
	while (number <= 100)
	{
		if (number % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (number % 3 == 0)
			write(1, "fizz", 4);
		else if (number % 5 == 0)
			write(1, "buzz", 4);
		else
			ft_wn(number);
		write(1, "\n", 1);
		number++;
	}
}
