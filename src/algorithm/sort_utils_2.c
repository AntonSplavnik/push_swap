/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:43:22 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/29 01:16:33 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

int	min_index(int *stack, int len)
{
	int	min_index;
	int	i;

	min_index = len - 1;
	i = len - 2;
	while (i >= 0)
	{
		if (stack[i] < stack[min_index])
			min_index = i;
		i--;
	}
	return (min_index);
}

int	max_index(int *stack, int len)
{
	int	max_index;
	int	i;

	max_index = len - 1;
	i = len - 2;
	while (i >= 0)
	{
		if (stack[i] > stack[max_index])
			max_index = i;
		i--;
	}
	return (max_index);
}

int	find_min(t_stacks *stacks)
{
	int	min;
	int	i;

	min = stacks->stack_a[stacks->stack_a_len - 1];
	i = stacks->stack_a_len - 2;
	while (i >= 0)
	{
		if (stacks->stack_a[i] < min)
			min = stacks->stack_a[i];
		i--;
	}
	return (min);
}

int	find_max(t_stacks *stacks)
{
	int	max;
	int	i;

	max = stacks->stack_a[stacks->stack_a_len - 1];
	i = stacks->stack_a_len - 2;
	while (i >= 0)
	{
		if (stacks->stack_a[i] > max)
			max = stacks->stack_a[i];
		i--;
	}
	return (max);
}
