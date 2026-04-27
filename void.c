#include <stdio.h>
#include <stdlib.h>

char	*to_hex(size_t nb)
{
	static char	s[16];
	char	*hex;
        size_t             len;
        size_t             temp;

        hex = "0123456789abcdef";
        temp = nb;
        while (temp)
        {
                len++;
                temp /= 16;
        }
        s[len--] = '\0';
        while (nb)
        {
                s[len--] = hex[nb % 16];
                nb /= 16;
        }
	return (s);
}

int main()
{
	char *test = "asdf";
	size_t adresse = (size_t)&test;
	printf("0x%s\n", to_hex(adresse));
	printf("%p\n", &test);
}
