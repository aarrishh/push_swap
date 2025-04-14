#include "push_swap.h"

void *add_back(stack *node, stack **a)
{
	
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
	stack* a, b;
	stack* node;

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
	}
	else
		write(1, "Error\n", 6);
	return(0);
}
