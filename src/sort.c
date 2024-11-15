/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:26:33 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/15 12:20:33 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stacks *stacks)
{
	int	min;
	int	i;


	min = stacks->stack_b[stacks->stack_b_len - 1];
	i = stacks->stack_b_len - 2;
	while (i >= 0)
	{
		if (stacks->stack_b[i] < min)
			min = stacks->stack_b[i];
		i--;
	}
	return (min);
}

int	find_max(t_stacks *stacks)
{
	int	max;
	int	i;

	max = stacks->stack_b[stacks->stack_b_len - 1];
	i = stacks->stack_b_len - 2;
	while (i >= 0)
	{
		if (stacks->stack_b[i] > max)
			max = stacks->stack_b[i];
		i--;
	}
	return (max);
}

int	find_correct_position(t_stacks *stack_b, int num)
{

}
int	calculate_operation(t_stacks *stacks, int index)
{

}

int	find_cheapest_number(t_stacks *stacks)
{
	int	min_operation;
	int	cheapest_index;
	int	current_operations;
	int	i;

	cheapest_index = stacks->stack_a_len - 1;
	min_operation = calculate_operation(stacks, stacks->stack_a_len - 1);
	i = stacks->stack_a_len - 2;
	while (i >= 0)
	{
		current_operations = calculate_operation(stacks, i);
		if (current_operations < min_operation)
		{
			min_operation = current_operations;
			cheapest_index = i;
		}
		i--;
	}
	return (cheapest_index);
}

void	sort_a(t_stacks *stacks)
{
	int	cheapest_index;

	while (stacks->stack_a_len > 3)
	{
		cheapest_index = find_cheapest_number();
		push_cheapest(stacks, cheapest_index);
	}
	sort_3(stacks->stack_a, stacks->stack_a_len);
	while (stacks->stack_b_len > 0)
		bush_sorted_to_a(stacks);
	last_rotate(stacks);
}
