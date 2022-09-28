#include <stdlib.h>
char *ft_strdup(char *src)
{
	int i;
	int len;
	char *dest;

	i = 0;
	while (src[i])
		i++;
	len = i;
	dest = malloc(sizeof(char) * (len + 1));
	if (dest == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
