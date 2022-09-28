#include <unistd.h>

int     main(int argc, char **argv)
{
	int i;
	
	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] == 'z')
			{
				write(1, &argv[1][i], 1);
				write(1, "\n", 1);
				break;
			}
			while (argv[1][i] != 'z')
			{
				i++;
				if (argv[1][i] == '\0')
					write(1, "z\n", 2);
					break;
			}
		}
	}
	else
		write(1, "z\n", 2);
    return (0);
  }
