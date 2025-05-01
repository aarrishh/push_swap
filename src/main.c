/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 15:57:31 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/01 22:30:01 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_sorted(t_stack *a)
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

void add_back(t_stack *node, t_stack **a)
{
	t_stack *tmp;

	if (*a == NULL)
	{
		*a = node;
		return ;
	}
	tmp = *a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = node;
}

t_stack *create_node(int res)
{
	t_stack *new_node;
	new_node = malloc(sizeof(t_stack));
	new_node->data = res;
	new_node->next = NULL;
	return(new_node);
}

void	free_split(char **str)
{
	int i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
	str = NULL;
}

int main(int argc, char** argv)
{
	int j = 0;
	int i = 1;
	long long res = 0;
	char** str = NULL;
	t_stack *a;
	t_stack* b;
	t_stack* node;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (argc >= 2)
	{
		while(argv[i])
		{
			if (str_contain_only_white_spaces(argv[i]) == 1)//esi okeya
				print_error(&a, str);
			str = ft_split(argv[i], ' ');
			while (str[j])
			{
				res = ft_atoi(str[j]);
				check_max_min(res, &a, str);
				if (res == -1)
					print_error(&a, str);
				node = create_node(res);
				add_back(node, &a);
				j++;
			}
			free_split(str);
			str = NULL;
			j = 0;
			i++;
		}
		if (check_sorted(a) == 1)
		{
			if (check_duplicates(a) == 0)
				print_error(&a, str);
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
		free_stack(&a);
		free_stack(&b);
		
		// print_stack_b(b);
		// print_stack_a(a);
	}
	return(0);
}
