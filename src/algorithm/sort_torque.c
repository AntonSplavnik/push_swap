/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_torque.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 21:34:35 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/29 02:32:50 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "algorithm.h"

int	calculate_stack_operations(int stack_size, int index)
{
	int	operations;

	operations = 0;
	if (index >= stack_size / 2)
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

	num = stacks->stack_b[index];
	pos_a = find_correct_position_in_a(stacks, num);
	move_index_b_top(stacks, index);
	if (pos_a == stacks->stack_a_len - 1)
	{
		push_a(stacks, 1);
		return ;
	}
	move_index_a_top(stacks, pos_a);
	push_a(stacks, 1);
}
