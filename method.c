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

	tmp = *b;
	*b = (*b)->next;
	tmp->next = NULL;
	if (!(*b))
		*b = tmp;
	else
		{
			tmp->next = *a;
			*a = tmp;
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

int size_list(stack **a)
{
	stack	*tmp;
	int		count;

	count = 0;
	tmp = *a;
	while (tmp != NULL)
	{
		tmp = tmp->next;
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
void sort_5(stack **a, stack **b)
{
	int		len;
	int		data;
	int		count;
	stack	*tmp;

	tmp = *a;
	count = 1;
	while (size_list(a) > 3)
	{
		data = small_value(a);
		len = size_list(a);
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
	print_stack(*a);
	printf("\n\n");
	print_stack(*b);
}