#include <stdio.h>
#include <stdlib.h>

int main()
{
	char	*hex;
	char	*s;
	int		len;
	int		temp;
	unsigned long int		nb;

	nb = -255;
	hex = "0123456789abcdef";
	temp = nb;
	while (temp)
	{
		len++;
		temp /= 16;
	}
	s = malloc(len);
	if (!s)
		return (0);
	s[len--] = '\0';
	while (nb)
	{
		s[len--] = hex[nb % 16];
		nb /= 16;
	}
	printf("%s\n", s);
	free(s);
}
