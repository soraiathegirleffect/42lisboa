#include <unistd.h>

int main (void)
{
	char a;
	char b;

	a = 'z';
	b = 'Y';

	while (a >= 'b' && b >= 'A')
	{
		write (1, &a, 1);
		write (1, &b, 1);
		a = a - 2;
		b = b - 2;
	}
	write (1, "\n", 1);
}
