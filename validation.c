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

void add_back(stack *node, stack **a)
{
	stack *tmp;

	if (*a == NULL)
	{
		*a = node;
		return ;
	}
	tmp = *a;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = node;
}

stack *create_node(int res)
{
	stack *new_node;
	new_node = malloc(sizeof(stack));
	new_node->data = res;
	new_node->next = NULL;
	return(new_node);
}

int main(int argc, char** argv)
{
	int j = 0;
	int i = 1;
	int res = 0;
	char** str = NULL;
	stack* a;
	stack* b;
	stack* node;

	a = NULL;
	b = NULL;
	if (argc >= 2)
	{
		while(argv[i])
		{
			str = ft_split(argv[i], ' ');
			while (str[j])
			{
				res = ft_atoi(str[j]);
				node = create_node(res);
				add_back(node, &a);
				j++;
			}
			j = 0;
			i++;
		}
		pb(&a, &b);
		pb(&a, &b);
		pb(&a, &b);
		pb(&a, &b);
		pb(&a, &b);

	}
	else
		write(1, "Error\n", 6);
	while(a != NULL)
	{
		i = a->data;
		printf("a-i data-> %d\n", i);
		a = a->next;
	}
	write (1, "\n", 1);
	while(b != NULL)
	{
		i = b->data;
		printf("b-i data-> %d\n", i);
		b = b->next;
	}
	
	return(0);
}
