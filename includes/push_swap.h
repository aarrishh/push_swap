/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:46:12 by arimanuk          #+#    #+#             */
/*   Updated: 2025/05/01 22:18:31 by arimanuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>

typedef struct s_stack {
	int index;
	int index_b;
	int data;
	struct s_stack* next;
} t_stack;

char		**ft_split(char const *s, char c);
void		free_stack(t_stack **stack);
void		butterfly(t_stack **a, t_stack **b, int n);
void		sort_5(t_stack **a, t_stack **b);
void 		print_stack_a(t_stack* tmp);//kjnjes
void 		print_stack_b(t_stack* tmp);//kjnjes;
void 		pb(t_stack **a, t_stack **b);
void 		pa(t_stack **a, t_stack **b);
void		sa(t_stack **a);
void		sb(t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rra(t_stack **a);
void		free_split(char **str);
void		rrb(t_stack **b);
void		print_error(t_stack **stack);
void		sort_3(t_stack **a);
void		indexing(t_stack **a);
void		indexing_b(t_stack **b);
void		check_max_min(long long num, t_stack **a);
void		move_two_smallest_to_b(int data, int len, t_stack **a, t_stack **b);
int 		str_contain_only_white_spaces(char *str);
int			check_duplicates(t_stack *a);
int			small_value(t_stack **a);
int			check_sorted(t_stack *a);
int			size_list(t_stack *a);
int			formula_n(int size);
int			log_n(int size);
long long	ft_atoi(const char *str);

#endif