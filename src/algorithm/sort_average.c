/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_average.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:34:50 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/29 00:35:19 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "algorithm.h"

int	sum(int *stack, int len)
{
	int	sum;
	int	i;

	sum = 0;
	i = len - 1;
	while (i >= 0)
	{
		sum += stack[i];
		i--;
	}
	return (sum);
}

int	find_index_to_push(int *stack, int len, int avrg)
{
	int	i;

	i = len - 1;
	while (i >= 0)
	{
		if (stack[i] > avrg)
			return (i);
		i--;
	}
	return (-1);
}

void	push_average_to_b(t_stacks *stacks)
{
	int	average;
	int	index_to_push;

	average = sum(stacks->stack_a, stacks->stack_a_len) / stacks->stack_a_len;
	index_to_push = \
		find_index_to_push(stacks->stack_a, stacks->stack_a_len, average);
	if (index_to_push == -1)
	{
		free_stacks(stacks);
		exit (1);
	}
	move_index_a_top(stacks, index_to_push);
	push_b(stacks, 1);
}
