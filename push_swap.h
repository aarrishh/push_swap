/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arimanuk <arimanuk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:46:12 by arimanuk          #+#    #+#             */
/*   Updated: 2025/04/18 22:17:05 by arimanuk         ###   ########.fr       */
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
int		ft_atoi(const char *str);
void 	pb(stack **a, stack **b);
void 	pa(stack **a, stack **b);
void	sa(stack **a);
void	sb(stack **b);
void	ra(stack **a);
void	rra(stack **a);

#endif