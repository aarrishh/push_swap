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

int check_sorted(stack *a)
{
	if (a == NULL)
		return (0);
	while (a->next != NULL)
	{
		if (a->data < a->next->data)
			a = a->next;
		else
			return(1);
	}
	return(0);
}

int check_duplicates(stack *a)
{
	stack *tmp;

	while (a != NULL)
	{
		tmp = a->next;
		while (tmp != NULL)
		{
			if (a->data != tmp->data)
				tmp = tmp->next;
			else
				return(0);
		}
		a = a->next;
	}
	return(1);
}

int check_max_min(stack *a)
{
	while (a != NULL)
	{
		if (a->data > INT_MAX || a->data < INT_MIN)
			return(-1);
		a = a->next;
	}
	return(0); //doesn't work
}

void	print_error(void)
{
	write (1, "Error\n", 6);
	exit(1);
}