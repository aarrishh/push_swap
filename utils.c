#include "push_swap.h"

int str_contain_only_white_spaces(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return -1;
	}
	return 1;
}