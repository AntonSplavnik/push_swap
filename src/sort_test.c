/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:26:33 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/23 20:51:11 by asplavni         ###   ########.fr       */
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
	// printf("max: %d\n", max);

	min = find_min(stacks);
	// printf("min: %d\n", min);

	i = stacks->stack_b_len - 1;
	if (num > max || num < min)
	{
		while (i >= 0)
		{
			if (stacks->stack_b[i] == max)
			{
				// printf("returning correct index: %d\n", i);
				return (i);
			}
			i--;
		}
		// printf("returning top: %d\n", (stacks->stack_b_len - 1));
		return (stacks->stack_b_len - 1);
	}

	if (num < stacks->stack_b[0] && num > stacks->stack_b[stacks->stack_b_len - 1])
		return (stacks->stack_b_len - 1); //0

	i = stacks->stack_b_len - 1;
	while (i > 0)
	{
		if (stacks->stack_b[i] > num && stacks->stack_b[i - 1] < num)
			return (i - 1);
		i--;
	}

	return (0);
}

// int	calculate_operations_b(t_stacks *stacks, int num)
// {
// 	int	max;
// 	int	min;
// 	int	i;

// 	max = find_max(stacks);
// 	min = find_min(stacks);

// 	if (stacks->stack_b_len == 0 || num > max || num < min)
// 	{
// 		i = stacks->stack_b_len - 1;
// 		while (i >= 0)
// 		{
// 			if (stacks->stack_b[i] == max)
// 			{
// 				if (i == stacks->stack_b_len - 1)
// 					return (0);
// 				else
// 					return (i + 1);
// 			}
// 			i--;
// 		}
// 		return (stacks->stack_b_len - 1);
// 	}

// 	if (num < stacks->stack_b[0] && num > stacks->stack_b[stacks->stack_b_len - 1])
// 	return (0); //1

// 	i = stacks->stack_b_len - 1;
// 	while (i > 0)
// 	{
// 		if (stacks->stack_b[i] > num && stacks->stack_b[i - 1] < num)
// 		{
// 			// printf("calc pos in B: %d\n", ((stacks->stack_b_len) - i));
// 			return (stacks->stack_b_len - i);
// 		}
// 		i--;
// 	}

// 	return (stacks->stack_b_len - 1);
// }

// int	calculate_operations_b(t_stacks *stacks, int num)
// {
// 	int	max;
// 	int	min;
// 	int	i;

// 	max = find_max(stacks);
// 	min = find_min(stacks);
// 	if (stacks->stack_b_len == 0 || num > max || num < min)
// 	{
// 		i = stacks->stack_b_len - 1;
// 		while (i >= 0)
// 		{
// 			if (stacks->stack_b[i] == max)
// 			{
// 				if (i == stacks->stack_b_len - 1)
// 					return (0);
// 				else
// 					return (i); //was i + 1
// 			}
// 			i--;
// 		}
// 		return (stacks->stack_b_len - 1);
// 	}
// 	i = stacks->stack_b_len - 1;
// 	while (i > 0)
// 	{
// 		// printf("im here! i = %d\n", i);
// 		if (stacks->stack_b[i] > num && stacks->stack_b[i - 1] < num)
// 		{
// 			printf("returning here : %d\n", (stacks->stack_b_len - i));
// 			return (stacks->stack_b_len - i);
// 		}
// 		i--;
// 		// printf("im here! i = %d\n", i);
// 	}

// 	if (num < stacks->stack_b[0] && num > stacks->stack_b[stacks->stack_b_len - 1])
// 		return (0);
// 	return (stacks->stack_b_len - 1);
// }


// int	calculate_stack_operations(int stack_size, int index)
// {
// 	int	operations;

// 	operations = 0;
// 	if (index <= stack_size)
// 		operations = index;
// 	else
// 		operations = stack_size - index;
// 	return (operations);
// }

// int	compare_operations(t_stacks *stacks, int operations_a, int operations_b, int index_a, int pos_in_b)
// {
// 	int	result;
// 	int	same_direction;

// 	result = 0;
// 	same_direction = 0;
// 	if ((index_a <= stacks->stack_a_len / 2 && pos_in_b <= stacks->stack_b_len / 2) \
// 			|| (index_a > stacks->stack_a_len / 2 && pos_in_b > stacks->stack_b_len / 2))
// 			same_direction = 1;
// 	if (same_direction == 1)
// 	{
// 		if (operations_a > operations_b)
// 			result = operations_a;
// 		else
// 			result = operations_b;
// 	}
// 	else
// 		result = operations_a + operations_b;
// 	return (result);
// }

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

int	calculate_operations(t_stacks *stacks, int index_a)
{
	int	num_in_a;
	int	pos_in_b;
	int	operations_a;
	int	operations_b;
	// int	total_opeartions;

	num_in_a = stacks->stack_a[index_a];
	pos_in_b = find_correct_position(stacks, num_in_a);

	operations_a = calculate_stack_operations(stacks->stack_a_len, index_a);
	// printf("index_a: %d operations_A: %d\n", index_a, operations_a);

	operations_b = calculate_stack_operations(stacks->stack_b_len, pos_in_b);
	// printf("index_a: %d operations_B: %d\n", index_a, operations_b);

	// operations_b = calculate_operations_b(stacks, num_in_a);
	// total_opeartions = compare_operations(stacks, operations_a, operations_b, index_a, pos_in_b);
	return (operations_a + operations_b);
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

	// printf("cheapest_index: %d\n", cheapest_index);
	// printf("min_operations: %d\n", min_operation);
	// ft_putstr("\n");

	while (i >= 0)
	{
		current_operations = calculate_operations(stacks, i);

		// printf("index: %d current_operations: %d \n",i , current_operations);
		// printf("cheapest_index: %d\n", cheapest_index);
		// ft_putstr("\n");

		if (current_operations < min_operation)
		{
			min_operation = current_operations;
			cheapest_index = i;
		}
		i--;
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

	// printf("cheapest_index_a: %d num_a: %d\n", index, num);
	// printf("pos_b (index_in_b): %d\n", pos_b);

	if (index <= stacks->stack_a_len / 2)
	{
		while (index >= 0)
		{
			reverse_rotate_a(stacks);
			index--;
		}
	}
	else
	{
		while (index < stacks->stack_a_len - 1)
		{
			rotate_a(stacks);
			index++;
		}
	}

	int	i = stacks->stack_b_len - 1;
	if (pos_b == stacks->stack_b_len -1)
	{
		// printf("here 0\n");
		push_b(stacks);
		return ;
	}
	else if (pos_b >= stacks->stack_b_len / 2)
	{
		while (pos_b != i)
		{
			// printf("rb: %d\n", i);
			rotate_b(stacks);
			// pos_b--;
			i--;
		}
	}
	else
	{
		while (pos_b != stacks->stack_b_len - 1)
		{
			if(pos_b == 0)
			{
				// printf("rrb %d\n", pos_b);
				reverse_rotate_b(stacks);
				pos_b = stacks->stack_b_len - 1;
			}
			else
			{
				// printf("rrb %d\n", pos_b);
				reverse_rotate_b(stacks);
				pos_b--;
			}
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

	if (stacks->stack_a_len == 4)
		push_b(stacks);
	else if (stacks->stack_a_len >= 5)
	{
		push_b(stacks);
		push_b(stacks);
	}
	while (stacks->stack_a_len > 0)
	{
		cheapest_index = find_cheapest_number(stacks);
		push_cheapest(stacks, cheapest_index);
	}

	// sort_3(stacks->stack_a, stacks->stack_a_len);
	// int	max_b = find_max(stacks);
	// int	i;

	// i = 0;
	// while (i <= stacks->stack_b_len - 1)
	// {
	// 	if (stacks->stack_b[i] == max_b)
	// 		break ;
	// 	i++;
	// }
	// if (i >= stacks->stack_b_len / 2)
	// {
	// 	while (max_b != stacks->stack_b[stacks->stack_b_len - 1])
	// 		rotate_b(stacks);
	// }
	// else
	// 	while (max_b != stacks->stack_b[stacks->stack_b_len - 1])
	// 		reverse_rotate_b(stacks);

	// 	int	max_b = find_max(stacks);
	// int	i;

	int	min = find_min(stacks);

	while (stacks->stack_b_len > 0)
		push_a(stacks);

	int i = 0;

	while (i <= stacks->stack_a_len - 1)
	{
		if (stacks->stack_a[i] == min)
			break ;
		i++;
	}
	if (i >= stacks->stack_a_len / 2)
	{
		while (min != stacks->stack_a[stacks->stack_a_len - 1])
			rotate_a(stacks);
	}
	else
		while (min != stacks->stack_a[stacks->stack_a_len - 1])
			reverse_rotate_a(stacks);

	// last_rotate(stacks);
}
