/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:26:33 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/17 00:47:20 by asplavni         ###   ########.fr       */
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
	printf("min: %d\n", min);
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
	printf("max: %d\n", max);
	return (max);
}

int	find_correct_position(t_stacks *stacks, int num)
{
	int	i;
	int	max;
	int	min;

	if (stacks->stack_b_len == 0)
		return (0);
	max = find_max(stacks);
	min = find_min(stacks);
	i = stacks->stack_b_len - 1;
	if (num > max || num < min)
	{
		while (i >= 0)
		{
			if (stacks->stack_b[i] == max)
				return (i);
			i--;
		}
		return (stacks->stack_b_len - 1);
	}
	i = stacks->stack_b_len - 1;
	while (i > 0)
	{
		if (stacks->stack_b[i] > num && stacks->stack_b[i - 1] < num)
			return (i);
		i --;
	}
	return (0);
}

int	calculate_operation(t_stacks *stacks, int index)
{
	int	num;
	int	pos_b;
	int	operations_a;
	int	operations_b;

	num = stacks->stack_a[index];
	pos_b = find_correct_position(stacks, num);
	operations_a = index;
	operations_b = stacks->stack_b_len - pos_b;

	if (operations_a > operations_b)
		return (operations_a);
	else
		return (operations_b);
}

int	find_cheapest_number(t_stacks *stacks)
{
	int	cheapest_index;
	int	min_operation;
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


void	push_cheapest(t_stacks *stacks, int index)
{
	int	num = stacks->stack_a[index];
	int	pos_b = find_correct_position(stacks, num);

	if (index <= stacks->stack_a_len / 2)
	{
		while (index > 0)
		{
			rotate_a(stacks);
			index--;
		}
	}
	else
	{
		while (index < stacks->stack_a_len - 1)
		{
			reverse_rotate_a(stacks);
			index++;
		}
	}

	if (pos_b <= stacks->stack_b_len / 2)
	{
		while (pos_b > 0)
		{
			rotate_b(stacks);
			pos_b--;
		}

	}
	else
	{
		while (pos_b < stacks->stack_b_len)
		{
			reverse_rotate_b(stacks);
			pos_b++;
		}
	}
	push_b(stacks);
}

// void	push_cheapest(t_stacks *stacks, int index)
// {
// 	int	num;
// 	int	pos_b;

// 	num = stacks->stack_a[index];
// 	pos_b = find_correct_position(stacks, num);

// 	while (index != stacks->stack_a_len)
// 	{
// 		if (index > stacks->stack_a_len / 2)
// 		{
// 			rotate_a(stacks);
// 			index++;
// 		}
// 		else
// 		{
// 			reverse_rotate_a(stacks);
// 			if (index == 0)
// 				index = stacks->stack_a_len;
// 			else
// 				index--;
// 		}
// 	}
// 	while (pos_b != stacks->stack_b_len)
// 	{
// 		if (pos_b > stacks->stack_b_len / 2)
// 		{
// 			rotate_b(stacks);
// 			pos_b++;
// 		}
// 		else
// 		{
// 			reverse_rotate_b(stacks);
// 			if (pos_b == 0)
// 				pos_b = stacks->stack_b_len;
// 			else
// 				pos_b--;
// 		}
// 	}
// 	push_b(stacks);
// }

void	sort_a(t_stacks *stacks)
{
	int	cheapest_index;

	push_b(stacks);
	push_b(stacks);

	while (stacks->stack_a_len > 3)
	{
		cheapest_index = find_cheapest_number(stacks);
		push_cheapest(stacks, cheapest_index);
	}

	sort_3(stacks->stack_a, stacks->stack_a_len);

	// while (stacks->stack_b_len > 0)
	// 	push_a(stacks);
	// last_rotate(stacks);
}
