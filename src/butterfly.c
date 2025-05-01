/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   butterfly.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:54:39 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/01 20:24:43 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int root_n(int size)
{
	int i;

	i = 0;
	if (i < size / 2)
	{
		while (i * i <= size)
		{
			if (i * i == size)
				return (i);
			else
				i++;
		}
	}
	return (0);
}

int log_n(int size)
{
	int count;

	count = 0;
	while (size > 1)
	{
		size = size / 2;
		count++;
	}
	return (count);
}

int formula_n(int size)
{
	return ((root_n(size) * 3) / 2 + log_n(size) - 1);
}

void find_position(t_stack **b, t_stack **a, t_stack **tmp)
{
	int value;
	int size;
	t_stack *current;

	current = *b;
	size = size_list(*b);
	value = (*tmp)->data;
	if ((*tmp)->index_b > size / 2)
	{
		while ((*b)->data != value)
			rrb(b);
	}
	else if ((*tmp)->index_b < size / 2)
	{
		while ((*b)->data != value)
			rb(b);
	}
	pa(a, b);
}

void	move_b_to_a(t_stack **a, t_stack **b)//poxel logikan
{
	int count;
	t_stack *tmp;

	indexing_b(b);
	// print_stack_b(*b);
	count = size_list(*b);
	while (count > 0)
	{
		tmp = *b;
		while (tmp)
		{
			if (count == tmp->index)
				find_position(b, a, &tmp);
			tmp = tmp->next;
		}
		count--;
	}
}

void	indexing_b(t_stack **b)
{
	int count;
	t_stack *tmp;

	tmp = *b;
	count = 0;
	while (tmp)
	{
		tmp->index_b = 0;
		tmp = tmp->next;
	}
	tmp = (*b);
	while (tmp)
	{
		tmp->index_b = count;
		count++;
		tmp = tmp->next;
	}
}

void	butterfly(t_stack **a, t_stack **b, int n)
{
	int count;

	count = 0;
	while (*a != NULL)
	{
		if ((*a)->index <= count)
		{
			pb(a, b);
			rb(b);
			count++;
		}
		else if ((*a)->index <= count + n)
		{
			pb(a, b);
			count++;
		}
		else
			ra(a);
	}
	// print_stack_b(*b);
	while (*b)
	{
		move_b_to_a(a, b);
		pa(a, b);
	}
	// print_stack_a(*a);
}
