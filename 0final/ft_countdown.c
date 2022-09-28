#include <unistd.h>
int	main(void)
{
	char nr;

	nr = '9';
	while (nr >= '0')
	{
		write(1, &nr, 1);
		nr--;
	}
	write(1, "\n", 1);
	return (0);
}
