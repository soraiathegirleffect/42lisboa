#include <unistd.h>
void	ft_wn(int nr)
{
	char	s;
	char	p;
	if (nr > 9)
	{
		p = (nr / 10) + 48;
		write(1, &p, 1);
	}
		s = (nr % 10) + 48;
		write(1, &s, 1);
}

int	main(void)
{
	int	number;

	number = 1;
	while (number <= 100)
	{
		if (number % 15 == 0)
			write(1, "fizzbuzz", 1);
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
