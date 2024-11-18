/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:26:33 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/18 21:26:02 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min(t_stacks *stacks)
{
	int	min;
	int	i;

	min = stacks->stack_b[stacks->stack_b_len - 1];
	i = stacks->stack_b_len - 2;
	// printf("%d. min before: %d. stack_b_len: %d\n", i, min, stacks->stack_b_len);
	while (i >= 0)
	{
		// printf("%d. min before: %d\n", i, min);
		if (stacks->stack_b[i] < min)
		{
			min = stacks->stack_b[i];
			// printf("%d. min after: %d\n", i, min);
		}
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
	// printf("max: %d\n", max);
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
	if (num < stacks->stack_b[0] && num > stacks->stack_b[stacks->stack_b_len - 1])
		return (stacks->stack_b_len - 1);
	return (0);
}

int	calculate_operations_b(t_stacks *stacks, int num)
{
	int	max;
	int	min;
	int	i;

	max = find_max(stacks);
	min = find_min(stacks);
	if (stacks->stack_b_len == 0 || num > max || num < min)
	{
		i = stacks->stack_b_len - 1;
		while (i >= 0)
		{
			if (stacks->stack_b[i] == max)
			{
				if (i == stacks->stack_b_len - 1)
					return (0);
				else
					return (i + 1);
			}
			i--;
		}
		return (stacks->stack_b_len - 1);
	}
	i = stacks->stack_b_len - 1;
	while (i > 0)
	{
		if (stacks->stack_b[i] > num && stacks->stack_b[i - 1] < num)
			return (i);
		i--;
	}
	if (num < stacks->stack_b[0] && num > stacks->stack_b[stacks->stack_b_len - 1])
		return (0);
	return (stacks->stack_b_len - 1);
}

int	calculate_stack_operations(int stack_size, int index)
{
	int	operations;

	operations = 0;
	if (index <= stack_size)
		operations = index;
	else
		operations = stack_size - index;
	return (operations);
}

int	compare_operations(t_stacks *stacks, int operations_a, int operations_b, int index_a, int pos_in_b)
{
	int	result;
	int	same_direction;

	result = 0;
	same_direction = 0;
	if ((index_a <= stacks->stack_a_len / 2 && pos_in_b <= stacks->stack_b_len / 2) \
			|| (index_a > stacks->stack_a_len / 2 && pos_in_b > stacks->stack_b_len / 2))
			same_direction = 1;
	if (same_direction == 1)
	{
		if (operations_a > operations_b)
			result = operations_a;
		else
			result = operations_b;
	}
	else
		result = operations_a + operations_b;
	return (result);
}

int	calculate_operations(t_stacks *stacks, int index_a)
{
	int	num_in_a;
	int	pos_in_b;
	int	operations_a;
	int	operations_b;
	int	total_opeartions;

	num_in_a = stacks->stack_a[index_a];
	pos_in_b = find_correct_position(stacks, num_in_a);
	operations_a = calculate_stack_operations(stacks->stack_a_len, index_a);
	operations_b = calculate_stack_operations(stacks->stack_b_len, pos_in_b);
	total_opeartions = compare_operations(stacks, operations_a, operations_b, index_a, pos_in_b);
	return (total_opeartions);
}

int	find_cheapest_number(t_stacks *stacks)
{
	int	cheapest_index;
	int	min_operation;
	int	current_operations;
	int	i;

	cheapest_index = stacks->stack_a_len - 1;
	min_operation = calculate_operations(stacks, stacks->stack_a_len - 1);
	i = stacks->stack_a_len - 2;

	printf("cheapest_index: %d\n", cheapest_index);
	printf("min_operations: %d\n", min_operation);
	ft_putstr("\n");
	while (i >= 0)
	{
		current_operations = calculate_operations(stacks, i);
		printf("cheapest_index: %d\n", cheapest_index);
		printf("current_operations: %d\n", current_operations);
		ft_putstr("\n");
		if (current_operations < min_operation)
		{
			min_operation = current_operations;
			cheapest_index = i;
		}
		i--;
		printf("cheapest_index: %d\n", cheapest_index);
		printf("current_operations: %d\n", current_operations);
		ft_putstr("\n");
	}
	return (cheapest_index);
}

// void push_cheapest(t_stacks *stacks, int index)
// {
//     int num = stacks->stack_a[index];
//     int pos_b = find_correct_position(stacks, num);

// 	printf("cheapest_index: %d\n", index);
// 	printf("num_a_chosen: %d pos_b: %d\n", num, pos_b);
//     // Move number to top of stack_a (length-1)
//     if (index <= stacks->stack_a_len / 2)
//     {
//         while (index < stacks->stack_a_len - 1)
//         {
//             rotate_a(stacks);
//             index++;
//         }
//     }
//     else
//     {
//         while (index > 0)
//         {
//             reverse_rotate_a(stacks);
//             index--;
//         }
//     }
//     // Handle stack_b positioning
//     if (stacks->stack_b_len == 0)
//     {
//         push_b(stacks);
//         return;
//     }
//     if (pos_b <= stacks->stack_b_len / 2)
//     {
//         while (pos_b < stacks->stack_b_len - 1)
//         {
//             rotate_b(stacks);
//             pos_b++;
//         }
//     }
//     else
//     {
//         while (pos_b > 0)
//         {
//             reverse_rotate_b(stacks);
//             pos_b--;
//         }
//     }
//     push_b(stacks);
// }

void	push_cheapest(t_stacks *stacks, int index)
{
	int	num = stacks->stack_a[index];
	int	pos_b = find_correct_position(stacks, num);

	printf("cheapest_index: %d\n", index);
	printf("num_a_chosen: %d pos_b: %d\n", num, pos_b);

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
	if (pos_b == stacks->stack_b_len -1)
	{
		push_b(stacks);
		return ;
	}
	else if (pos_b <= stacks->stack_b_len / 2)
	{
		while (pos_b > 0)
		{
			rotate_b(stacks);
			pos_b--;
		}
	}
	else
	{
		while (pos_b < stacks->stack_b_len - 1)
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

// 		printf("cheapest_index: %d\n", index);
// 	printf("num_a_chosen: %d pos_b: %d\n", num, pos_b);

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

	// cheapest_index = find_cheapest_number(stacks);
	// push_cheapest(stacks, cheapest_index);

	// cheapest_index = find_cheapest_number(stacks);
	// push_cheapest(stacks, cheapest_index);

	// cheapest_index = find_cheapest_number(stacks);
	// push_cheapest(stacks, cheapest_index);

	// reverse_rotate_b(stacks);
	// reverse_rotate_b(stacks);
	// if (stacks->stack_a_len > 5)
	// {
	// 	push_b(stacks);
	// 	push_b(stacks);
	// }
	// else
	// 	push_b(stacks);

	while (stacks->stack_a_len > 3)
	{
		cheapest_index = find_cheapest_number(stacks);
		push_cheapest(stacks, cheapest_index);

		ft_putstr("\nafter push_b\n");
		for (int i = stacks->stack_a_len; i > 0; i--)
			printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

		ft_putstr("\n");
		for (int i = stacks->stack_b_len; i > 0; i--)
			printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
	}

	// sort_3(stacks->stack_a, stacks->stack_a_len);

	// while (stacks->stack_b_len > 0)
	// 	push_a(stacks);
	// last_rotate(stacks);
}