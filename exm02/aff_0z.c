#include <unistd.h>

int	main(int ac, char **av)
{
	while (ac && **av)
	{
		write(1, "z\n", 2);
		return (0);
	}
}
