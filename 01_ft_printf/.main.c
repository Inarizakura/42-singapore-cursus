#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
// %c tests
	printf("%%c tests\n");
	char			c = 'D';
	printf("%d\n", printf("%%c results: %c.\n", c));
	ft_printf("%d\n", ft_printf("%%c results: %c.\n", c));

// %s tests
	printf("%%s tests\n");
	char			*s = "Hello 42!";
	printf("%d\n", printf("%%s results: %s.\n", s));
	ft_printf("%d\n", ft_printf("%%s results: %s.\n", s));

	char			*n =  NULL;
	printf("%d\n", printf("%%s results: %s.\n", n));
	ft_printf("%d\n", ft_printf("%%s results: %s.\n", n));

// %p tests
	printf("%%p tests\n");
	void			*ptr = &c;
	printf("%d\n", printf("%%p results: %p.\n", ptr));
	ft_printf("%d\n", ft_printf("%%p results: %p.\n", ptr));

	void			*ptr2 = &s;
	printf("%d\n", printf("%%p results: %p.\n", ptr2));
	ft_printf("%d\n", ft_printf("%%p results: %p.\n", ptr2));

	void			*ptr3 = 0;
	printf("%d\n", printf("%%p results: %p.\n", ptr3));
	ft_printf("%d\n", ft_printf("%%p results: %p.\n", ptr3));
	
// %d
	printf("%%d tests\n");
	int				d = -2147483648;
	printf("%d\n", printf("%%d results: %d.\n", d));
	ft_printf("%d\n", ft_printf("%%d results: %d.\n", d));

// %i
	printf("%%i tests\n");
	int				i = -2147483648;
	printf("%d\n", printf("%%i results: %i.\n", i));
	ft_printf("%d\n", ft_printf("%%i results: %i.\n", i));

// %u
	printf("%%u tests\n");
	unsigned int	u1 = -2147483648;
	printf("%d\n", printf("%%u results: %u.\n", u1));
	ft_printf("%d\n", ft_printf("%%u results: %u.\n", u1));

	unsigned int	u2 = 2147483648;
	printf("%d\n", printf("%%u results: %u.\n", u2));
	ft_printf("%d\n", ft_printf("%%u results: %u.\n", u2));

// %x
	printf("%%x tests\n");
	unsigned int	x1 = -2147483648;
	printf("%d\n", printf("%%x results: %x.\n", x1));
	ft_printf("%d\n", ft_printf("%%x results: %x.\n", x1));

	unsigned int	x2 = 2147483648;
	printf("%d\n", printf("%%x results: %x.\n", x2));
	ft_printf("%d\n", ft_printf("%%x results: %x.\n", x2));

// %X
	printf("%%X tests\n");
	unsigned int	X1 = -2147483648;
	printf("%d\n", printf("%%X results: %X.\n", X1));
	ft_printf("%d\n", ft_printf("%%X results: %X.\n", X1));

	unsigned int	X2 = 2147483648;
	printf("%d\n", printf("%%X results: %X.\n", X2));
	ft_printf("%d\n", ft_printf("%%X results: %X.\n", X2));

// %%
	printf("%%%% tests\n");
	printf("%d\n", printf("%%%% results: %%%%%%%%%%%%.\n"));
	ft_printf("%d\n", ft_printf("%%%% results: %%%%%%%%%%%%.\n"));

	return (0);
}
