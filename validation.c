#include "push_swap.h"

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
	(void)argv;
	int j = 0;
	int i = 1;
	long long res = 0;
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
			if (str_contain_only_white_spaces(argv[i]) == 1)
				print_error();
			str = ft_split(argv[i], ' ');
			while (str[j])
			{
				res = ft_atoi(str[j]);
				// check_max_min(res);
				if (res == -1)
					print_error();
				node = create_node(res);
				add_back(node, &a);
				j++;
			}
			j = 0;
			i++;
		}
		if (check_sorted(a) == 1)
		{
			// i = check_max_min(a);
			if (check_duplicates(a) == 0)
				print_error();
			if (size_list(a) == 1)
				return(0);
			else if (size_list(a) == 2)
				sa(&a);
			else if (size_list(a) == 3)
				sort_3(&a);
			else if (size_list(a) == 4 || size_list(a) == 5)
				sort_5(&a, &b);
			else
			{
				indexing(&a);
				butterfly(&a, &b, formula_n(size_list(a)));
			}
		}
		// print_stack_a(a);
		// printf("\n\n");
		// print_stack_b(b);
	}
	else
		print_error();
	return(0);
}

void print_stack_a(stack* tmp)
{
	while(tmp != NULL)
	{
		printf("a-i index-> %d\na-i data-> %d\n\n", tmp->index, tmp->data);
		tmp = tmp->next;
	}
}

void print_stack_b(stack* tmp)
{
	while(tmp != NULL)
	{
		printf("b-i index-> %d\nb-i data-> %d\n\n", tmp->index, tmp->data);
		tmp = tmp->next;
	}
}