/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:46:12 by arimanuk          #+#    #+#             */
/*   Updated: 2025/04/21 22:27:12 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

typedef struct stack {
	int data;
	struct stack* next;
} stack;

char	**ft_split(char const *s, char c);
void 	print_stack(stack* tmp);//kjnjes
int 	str_contain_only_white_spaces(char *str);
int		ft_atoi(const char *str);
int		size_list(stack **a);
int		small_value(stack **a);
void 	pb(stack **a, stack **b);
void 	pa(stack **a, stack **b);
void	sa(stack **a);
void	sb(stack **b);
void	ra(stack **a);
void	rb(stack **b);
void	rra(stack **a);
void	rrb(stack **b);
void	sort_3(stack **a);
void	sort_5(stack **a, stack **b);
void	move_two_smallest_to_b(int data, int len, stack **a, stack **b);
int		validation (stack **a);
int		check_duplicates(stack *a);

#endif