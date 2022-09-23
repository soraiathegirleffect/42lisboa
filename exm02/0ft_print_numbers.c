#include <unistd.h>

void	ft_print_numbers(void)
{
	char	nr;

	nr = '0';
	while (nr <= '9')
	{
		write(1, &nr, 1);
		nr++;
	}
}
