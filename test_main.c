#include <stdio.h>
#include "libft.h"

static void	check(char c, int expected)
{
	int	result;

	result = ft_isalpha(c);
	if (result != expected)
		printf("Test failed for ft_isalpha");
	else
		printf("Test passed for '%c'\n", c);
}

static void	test_ft_isalpha(void)
{
	printf("Testing ft_isalpha:\n");
	check('A', 1);
	check('z', 1);
	check('1', 0);
	check('!', 0);
	check(' ', 0);
}

int	main(void)
{
	test_ft_isalpha();
	return (0);
}