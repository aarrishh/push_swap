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

int validation (stack **a)
{
	stack *tmp;

	tmp = *a;
	while (tmp->next != NULL)
	{
		if (tmp->data < tmp->next->data)
			tmp = tmp->next;
		else
			return(1);
	}
	return(0);
}

int check_duplicates(stack *a)
{
	stack *tmp;

	tmp = a->next;
	while (a != NULL)
	{
		while (tmp != NULL)
		{
			if (a->data != tmp->data)
				tmp = tmp->next;
			else
				return(0);
		}
		a = a->next;
		tmp = a->next;
	}
	return(1);
}

int check_max_min(stack *a)
{
	stack *tmp;

	tmp = a;
	while (a != NULL)
	{
		if (a->data == 2147483648 && )
		a = a->next;
		tmp = a->next;
	}
}