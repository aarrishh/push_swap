/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:50:01 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/01 16:55:12 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_3(t_stack **a)
{
	int a1;
	int a2;
	int a3;

	a1 = (*a)->data;
	a2 = (*a)->next->data;
	a3 = (*a)->next->next->data;
	if (a1 < a2 && a2 < a3)
		return ;
	else if (a1 > a2 && a2 > a3 && a3 < a1)
	{
		ra(a);
		sa(a);
	}
	else if (a1 < a2 && a2 > a3 && a3 > a1)
	{
		rra(a);
		sa(a);
	}
	else if (a1 > a2 && a2 < a3 && a3 > a1)
		sa(a);
	else if (a1 > a2 && a2 < a3 && a3 < a1)
		ra(a);
	else if (a1 < a2 && a2 > a3 && a3 < a1)
		rra(a);
}

void sort_5(t_stack **a, t_stack **b)
{
	int		len;
	int		data;
	int		count;

	count = 0;
	while (count < 2)
	{
		data = small_value(a);
		len = size_list(*a);
		if (len == 3)
			count++;
		else
			move_two_smallest_to_b(data, len, a, b);
		count++;
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}
