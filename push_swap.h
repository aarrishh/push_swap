/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:46:12 by arimanuk          #+#    #+#             */
/*   Updated: 2025/04/26 21:41:17 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct stack {
	int index;
	int data;
	struct stack* next;
} stack;

char		**ft_split(char const *s, char c);
void		butterfly(stack **a, stack **b, int n);
void		sort_5(stack **a, stack **b);
void 		print_stack_a(stack* tmp);//kjnjes
void 		print_stack_b(stack* tmp);//kjnjes;
void 		pb(stack **a, stack **b);
void 		pa(stack **a, stack **b);
void		sa(stack **a);
void		sb(stack **b);
void		ra(stack **a);
void		rb(stack **b);
void		rra(stack **a);
void		rrb(stack **b);
void		print_error(void);
void		sort_3(stack **a);
void		indexing(stack **a);
void		move_two_smallest_to_b(int data, int len, stack **a, stack **b);
int 		str_contain_only_white_spaces(char *str);
int			check_duplicates(stack *a);
int			check_max_min(stack *a);
int			small_value(stack **a);
int			check_sorted(stack *a);
int			size_list(stack *a);
int			formula_n(int size);
int			log_n(int size);
long long	ft_atoi(const char *str);

#endif