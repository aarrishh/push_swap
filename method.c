#include "push_swap.h"

void sa(stack **a)
{
	int num;

	if (!a || !(*a) || (*a)->next == NULL)
		return ;
	num = (*a)->data;
	(*a)->data = (*a)->next->data;
	(*a)->next->data = num;
}
void sb(stack **b)
{
	int num;

	if (!b || !(*b) || (*b)->next == NULL)
		return ;
	num = (*b)->data;
	(*b)->data = (*b)->next->data;
	(*b)->next->data = num;
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
}

void rra(stack **a)
{
	stack* tmp;
	stack* idk;

	tmp = *a;
	idk = tmp;
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
}