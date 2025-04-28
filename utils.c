/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:00:36 by arimanuk          #+#    #+#             */
/*   Updated: 2025/04/28 21:09:48 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// void	check_max_min(long long num)
// {
// 	if (num > INT_MAX || num < INT_MIN)
// 		print_error();
// }

void	print_error(void)
{
	write (1, "Error\n", 6);
	exit(1);
}