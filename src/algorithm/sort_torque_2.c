/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_torque_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 01:42:36 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/29 04:08:10 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "algorithm.h"

int	find_insert_position_for_bounds(t_stacks *stacks, int min)
{
	int	i;

	i = stacks->stack_a_len - 1;
	while (i >= 0)
	{
		if (stacks->stack_a[i] == min)
			return (i);
		i--;
	}
	return (stacks->stack_a_len - 1);
}

int	find_insert_position_between(t_stacks *stacks, int num)
{
	int	i;

	i = stacks->stack_a_len - 1;
	while (i > 0)
	{
		if (stacks->stack_a[i] < num && stacks->stack_a[i - 1] > num)
			return (i - 1);
		i--;
	}
	return (0);
}

int	find_correct_position_in_a(t_stacks *stacks, int num)
{
	int	max;
	int	min;

	if (stacks->stack_a_len == 0)
		return (0);
	max = find_max(stacks);
	min = find_min(stacks);
	if (num < min || num > max)
		return (find_insert_position_for_bounds(stacks, min));
	if (num > stacks->stack_a[0] && \
		num < stacks->stack_a[stacks->stack_a_len - 1])
	{
		return (stacks->stack_a_len - 1);
	}
	return (find_insert_position_between(stacks, num));
	return (0);
}
