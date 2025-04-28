/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   method_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 21:02:18 by arimanuk          #+#    #+#             */
/*   Updated: 2025/04/28 22:21:25 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(stack **a)
{
	int num;

	if (!a || !(*a) || (*a)->next == NULL)
		return ;
	num = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = num;
	printf("sa\n");
}
void sb(stack **b)
{
	int num;

	if (!b || !(*b) || (*b)->next == NULL)
		return ;
	num = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = num;
	printf("sb\n");
}

void pb(stack **a, stack **b)
{
	stack *tmp;

	if ((*a) != NULL)
	{
		tmp = *a;
		*a = (*a)->next;
		tmp->next = NULL;
		if (!(*b))
			*b = tmp;
		else
			{
				tmp->next = *b;
				*b = tmp;
			}
	}
	printf("pb\n");
}

void pa(stack **a, stack **b)
{
	stack *tmp;

	if ((*b) != NULL)
	{
		tmp = *b;
		*b = (*b)->next;
		tmp->next = NULL;
		if (!(*a))
			*a = tmp;
		else
		{
			tmp->next = *a;
			*a = tmp;
		}
	}
	printf("pa\n");
}

void ra(stack **a)
{
	stack* tmp;
	stack* idk;

	if ((*a)->next != NULL)
	{
		idk = *a;
		tmp = *a;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*a) = (*a)->next;
		idk->next = NULL;
		tmp->next = idk;
	}
	printf("ra\n");
}

void rb(stack **b)
{
	stack* tmp;
	stack* idk;

	if ((*b)->next != NULL)
	{
		idk = *b;
		tmp = *b;
		while (tmp->next != NULL)
			tmp = tmp->next;
		(*b) = (*b)->next;
		idk->next = NULL;
		tmp->next = idk;
	}
	printf("rb\n");
}

void rra(stack **a)
{
	stack* tmp;
	stack* idk;

	tmp = *a;
	idk = tmp;
	// printf("zzzzz%p\n",(*a)->next);
	if ((*a)->next != NULL)
	{
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		while (idk->next != NULL)
			idk = idk->next;
		tmp->next = NULL;
		idk->next = *a;
		*a = idk;
	}
	printf("rra\n");
}
void rrb(stack **b)
{
	stack* tmp;
	stack* idk;

	tmp = *b;
	idk = tmp;
	if ((*b)->next != NULL)
	{
		while (tmp->next->next != NULL)
			tmp = tmp->next;
		while (idk->next != NULL)
			idk = idk->next;
		tmp->next = NULL;
		idk->next = *b;
		*b = idk;
	}
	printf("rrb\n");
}

void sort_3(stack **a)
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

int size_list(stack *a)
{
	int		count;

	count = 0;
	while (a != NULL)
	{
		a = a->next;
		count++;
	}
	return (count);
}

int small_value(stack **a)
{
	stack *tmp;
	stack *start;

	start = *a;
	tmp = (*a)->next;
	while (start != NULL && tmp != NULL)
	{
		if (start->data < tmp->data)
			tmp = tmp->next;
		else
		{
			start = tmp;
			tmp = tmp->next;
		}
	}
	return (start->data);
}

void move_two_smallest_to_b(int data, int len, stack **a, stack **b)
{
	int count;
	stack *tmp;

	tmp = *a;
	count = 1;
	while (data != tmp->data)
	{
		tmp = tmp->next;
		count++;
	}
	// printf("node-i texy listum -> %d\n", number);
	if (len / 2 < count)
	{
		while (tmp->next != NULL)
			rra(a);
		rra(a);
		pb(a, b);
	}
	else
	{
		while (--count)
			ra(a);
		pb(a, b);
	}
}

void sort_5(stack **a, stack **b)
{
	int		len;
	int		data;
	int		count;

	printf("yhn\n");
	count = 0;
	while (count < 2)
	{
		data = small_value(a);
		len = size_list(*a);
		if (len == 3)//count == 1 && 
			count++;
		else
			move_two_smallest_to_b(data, len, a, b);
		count++;
	}
	sort_3(a);
	pa(a, b);
	pa(a, b);
}

void	indexing(stack **a)
{
	int count;
	stack *tmp;
	stack *current;

	current = *a;
	tmp = *a;
	count = 0;
	while (tmp)
	{
		tmp->index = 0;
		tmp = tmp->next;
	}
	tmp = (*a)->next;
	while (current)
	{
		while (tmp)
		{
			if (current->data > tmp->data)
			{
				current->index++;
				tmp = tmp->next;
			}
			else
				tmp = tmp->next;
		}
		tmp = *a;
		current = current->next;
	}
}

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
	return (root_n(size) + log_n(size));
}

void	move_b_to_a(stack **a, stack **b)//poxel logikan
{
	int count;
	stack *tmp;

	count = size_list(*b) - 1;
	while (count > 0)
	{
		tmp = *b;
		while (tmp)
		{
			if (count == tmp->index)
			{
				if (tmp->next == NULL)
					rrb(b);
				pa(a, b);
			}
			tmp = tmp->next;
		}
		count--;
	}
}

void	butterfly(stack **a, stack **b, int n)
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
	print_stack_b(*b);
	print_stack_a(*a);
	move_b_to_a(a, b);
}
