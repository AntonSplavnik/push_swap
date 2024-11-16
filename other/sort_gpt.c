/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_gpt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:29:13 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/15 12:10:49 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int	find_min(t_stacks *stacks)
// {
// 	int	min;
// 	int	i;

// 	i = stacks->stack_b_len - 2;
// 	min = stacks->stack_b[stacks->stack_b_len - 1];
// 	while (i >= 0)
// 	{
// 		if (stacks->stack_b[i] < min)
// 			min = stacks->stack_b[i];
// 		i--;
// 	}
// 	return (min);
// }

// int	find_max(t_stacks *stack)
// {
// 	int	max;

// 	max = stack->arr[stack->size - 1];
// 	for (int i = stack->size - 2; i >= 0; i--)
// 	{
// 		if (stack->arr[i] > max)
// 			max = stack->arr[i];
// 	}
// 	return (max);
// }

int	find_correct_position(t_stack *stack_b, int num)
{
	int	i;

	if (stack_b->size == 0)
		return (0); // If STACK_B is empty, place at the top

	int	max = find_max(stack_b);
	int	min = find_min(stack_b);

	// If num is greater than max or less than min, it wraps around
	if (num > max || num < min)
	{
		for (i = stack_b->size - 1; i >= 0; i--)
		{
			if (stack_b->arr[i] == max)
				return (i + 1); // Place above the max
		}
	}

	// Otherwise, find the correct place between two elements
	for (i = stack_b->size - 1; i > 0; i--)
	{
		if (stack_b->arr[i] > num && stack_b->arr[i - 1] < num)
			return (i);
	}

	return (0); // Default: Place at the top
}

int	calculate_operations(t_stack *stack_a, t_stack *stack_b, int index)
{
	int	num = stack_a->arr[index];
	int	pos_b = find_correct_position(stack_b, num);

	// Rotate STACK_A to bring the number to the top
	while (index != stack_a->size - 1)
	{
		// Choose ra or rra based on the index
		if (index < stack_a->size / 2)
			rotate_a(stack_a); // Implement rotate_a
		else
			reverse_rotate_a(stack_a); // Implement reverse_rotate_a
	}

	// Rotate STACK_B to prepare for insertion
	while (pos_b != stack_b->size)
	{
		// Choose rb or rrb based on the position
		if (pos_b < stack_b->size / 2)
			rotate_b(stack_b); // Implement rotate_b
		else
			reverse_rotate_b(stack_b); // Implement reverse_rotate_b
	}
	// Push the number to STACK_B
	push_b(stack_a, stack_b); // Implement push_b
}

int	find_cheapest_number(t_stack *stack_a, t_stack *stack_b)
{
	int	min_operations = calculate_operations(stack_a, stack_b, stack_a->size - 1);
	int	cheapest_index = stack_a->size - 1;

	for (int i = stack_a->size - 2; i >= 0; i--)
	{
		int current_operations = calculate_operations(stack_a, stack_b, i);
		if (current_operations < min_operations)
		{
			min_operations = current_operations;
			cheapest_index = i;
		}
	}

	return (cheapest_index);
}


void	push_to_stack_b(t_stack *stack_a, t_stack *stack_b, int index)
{
	int num = stack_a->arr[index];
	int pos_b = find_correct_position(stack_b, num);

	// Rotate STACK_A to bring the number to the top
	while (index != stack_a->size - 1)
	{
		// Choose ra or rra based on the index
		if (index < stack_a->size / 2)
			rotate_a(stack_a); // Implement rotate_a
		else
			reverse_rotate_a(stack_a); // Implement reverse_rotate_a
	}

	// Rotate STACK_B to prepare for insertion
	while (pos_b != stack_b->size)
	{
		// Choose rb or rrb based on the position
		if (pos_b < stack_b->size / 2)
			rotate_b(stack_b); // Implement rotate_b
		else
			reverse_rotate_b(stack_b); // Implement reverse_rotate_b
	}

	// Push the number to STACK_B
	push_b(stack_a, stack_b); // Implement push_b
}


void	sort_stack(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->size > 3) // Leave 3 elements in STACK_A for sorting later
	{
		int cheapest_index = find_cheapest_number(stack_a, stack_b);
		push_to_stack_b(stack_a, stack_b, cheapest_index);
	}
	// Sort the remaining 3 elements in STACK_A (implement sort_3)
	sort_3(stack_a);
	// Push everything back to STACK_A from STACK_B
	while (stack_b->size > 0)
		push_b_to_a(stack_a, stack_b); // Implement push_b_to_a

	// Final adjustment: Bring the smallest element to the top
	rotate_to_smallest(stack_a); // Implement rotate_to_smallest
}



