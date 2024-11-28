/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_torque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:34:35 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 01:26:45 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "algorithm.h"

int	min_index(int *stack, int len)
{
	int	min_index;
	int	i;

	min_index = len - 1;
	i = len - 2;
	while (i >= 0)
	{
		if(stack[i] < stack[min_index])
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
		if(stack[i] > stack[max_index])
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

int	find_correct_position_in_a(t_stacks *stacks, int num)
{
	int	i;
	int	max;
	int	min;

	if (stacks->stack_a_len == 0)
		return (0);

	max = find_max(stacks);
	min = find_min(stacks);

	i = stacks->stack_a_len - 1;

	if (num < min || num > max)
	{
		while (i >= 0)
		{
			if (stacks->stack_a[i] == min)
				return (i);
			i--;
		}
		return (stacks->stack_a_len - 1);
	}

	if (num > stacks->stack_a[0] && num < stacks->stack_a[stacks->stack_a_len - 1])
	{
		return (stacks->stack_a_len - 1);
	}

	i = stacks->stack_a_len - 1;
	while (i > 0)
	{
		if (stacks->stack_a[i] < num && stacks->stack_a[i - 1] > num)
			return (i - 1);
		i--;
	}

	return (0);
}

int	calculate_stack_operations(int stack_size, int index)
{
	int	operations;

	operations = 0;
	if(index >= stack_size / 2)
		operations = (stack_size - 1) - index;
	else
		operations = index + 1;
	return (operations);
}

int	calculate_operations(t_stacks *stacks, int index_b)
{
	int	num_in_b;
	int	pos_in_a;
	int	operations_a;
	int	operations_b;

	num_in_b = stacks->stack_b[index_b];
	pos_in_a = find_correct_position_in_a(stacks, num_in_b);
	operations_a = calculate_stack_operations(stacks->stack_a_len, pos_in_a);
	operations_b = calculate_stack_operations(stacks->stack_b_len, index_b);
	return (operations_a + operations_b);
}

int	find_cheapest_in_b(t_stacks *stacks)
{
	int	cheapest_index;
	int	min_operation;
	int	current_operations;
	int	i;

	cheapest_index = stacks->stack_b_len - 1;
	min_operation = calculate_operations(stacks, stacks->stack_b_len - 1);
	i = stacks->stack_b_len - 2;

	while (i >= 0)
	{
		current_operations = calculate_operations(stacks, i);

		if (current_operations < min_operation)
		{
			min_operation = current_operations;
			cheapest_index = i;
		}
		i--;
	}
	return (cheapest_index);
}

void	push_cheapest_to_a(t_stacks *stacks, int index)
{
	int	num;
	int	pos_a;

	num  = stacks->stack_b[index];
	pos_a = find_correct_position_in_a(stacks, num);

	if (index >= stacks->stack_b_len / 2)
	{
		while (index != stacks->stack_b_len - 1)
		{
			rotate_b(stacks, 1);
			index = (index + 1) % stacks->stack_b_len;
		}
	}
	else
	{
		while (index != stacks->stack_b_len - 1)
		{
			reverse_rotate_b(stacks, 1);
			index = (index - 1 + stacks->stack_b_len) % stacks->stack_b_len;
		}
	}

	if (pos_a == stacks->stack_a_len - 1)
	{
		push_a(stacks, 1);
		return ;
	}
	else if (pos_a >= stacks->stack_a_len / 2)
	{
		while (pos_a != stacks->stack_a_len - 1)
		{
			rotate_a(stacks, 1);
			pos_a = (pos_a + 1) % stacks->stack_a_len;
		}
	}
	else
	{
		while (pos_a != stacks->stack_a_len - 1)
		{
			reverse_rotate_a(stacks, 1);
			pos_a = (pos_a - 1 + stacks->stack_a_len) % stacks->stack_a_len;
		}
	}
	push_a(stacks, 1);
}