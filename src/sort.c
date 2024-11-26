/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:26:33 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/26 20:33:57 by asplavni         ###   ########.fr       */
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

int	find_correct_position_in_b(t_stacks *stacks, int num)
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
// 					return (i + 1); // i
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
	pos_in_b = find_correct_position_in_b(stacks, num_in_a);

	operations_a = calculate_stack_operations(stacks->stack_a_len, index_a);
	// printf("index_a: %d operations_A: %d\n", index_a, operations_a);

	operations_b = calculate_stack_operations(stacks->stack_b_len, pos_in_b);
	// printf("index_a: %d operations_B: %d\n", index_a, operations_b);

	// operations_b = calculate_operations_b(stacks, num_in_a);
	// total_opeartions = compare_operations(stacks, operations_a, operations_b, index_a, pos_in_b);
	return (operations_a + operations_b);
}

int	find_cheapest_in_a(t_stacks *stacks)
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

void	push_cheapest_to_b(t_stacks *stacks, int index)
{
	int	num;
	int	pos_b;

	num  = stacks->stack_a[index];
	pos_b = find_correct_position_in_b(stacks, num);
	// printf("cheapest_index_a: %d num_a: %d\n", index, num);
	// printf("pos_b (index_in_b): %d\n", pos_b);

	if (index >= stacks->stack_a_len / 2)
	{
		while (index != stacks->stack_a_len - 1)
		{
			rotate_a(stacks);
			index = (index + 1) % stacks->stack_a_len;
		}
	}
	else
	{
		while (index != stacks->stack_a_len - 1)
		{
			reverse_rotate_a(stacks);
			index = (index - 1 + stacks->stack_a_len) % stacks->stack_a_len;
		}
	}

	// if (index <= stacks->stack_a_len / 2)
	// {
	// 	while (index >= 0)
	// 	{
	// 		reverse_rotate_a(stacks);
	// 		index--;
	// 	}
	// }
	// else
	// {
	// 	while (index < stacks->stack_a_len - 1)
	// 	{
	// 		rotate_a(stacks);
	// 		index++;
	// 	}
	// }

	// int	i = stacks->stack_b_len - 1;
	if (pos_b == stacks->stack_b_len -1)
	{
		push_b(stacks);
		return ;
	}
	else if (pos_b >= stacks->stack_b_len / 2)
	{
		while (pos_b != stacks->stack_b_len - 1) // i
		{
			rotate_b(stacks);
			pos_b = (pos_b + 1) % stacks->stack_b_len;
			// pos_b++;
			// i--;
		}
	}
	else
	{
		while (pos_b != stacks->stack_b_len - 1)
		{
			reverse_rotate_b(stacks);
			pos_b = (pos_b - 1 + stacks->stack_b_len) % stacks->stack_b_len;

			// if(pos_b == 0)
			// {
			// 	reverse_rotate_b(stacks);
			// 	pos_b = stacks->stack_b_len - 1;
			// }
			// else
			// {
			// 	reverse_rotate_b(stacks);
			// 	pos_b--;
			// }
		}
	}
	push_b(stacks);
}

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

int	find_correct_pos_in_a(t_stacks *stacks)
{
	int	num = stacks->stack_b[stacks->stack_b_len - 1];
	int	target_pos;
	int	next_pos;
	int	i;

	target_pos = -1;
	i = stacks->stack_a_len - 1;

	while (i >= 0)
	{
		next_pos = (i - 1 + stacks->stack_a_len) % stacks->stack_a_len;

		if(stacks->stack_a[i] < num && stacks->stack_a[next_pos] > num)
		{
			target_pos = next_pos;
			break ;
		}
		i--;
	}

	int min_index_a = min_index(stacks->stack_a, stacks->stack_a_len);
	if (num < stacks->stack_a[min_index_a])
		target_pos = min_index_a;
	// i = stacks->stack_a_len - 1;
	// if (target_pos == -1)
	// {
	// 	while (i >= 0)
	// 	{
	// 		if (stacks->stack_a[i] > num)
	// 		{
	// 			target_pos = i;
	// 			printf("target_pos top: %d\n", target_pos);
	// 			break ;
	// 		}
	// 		i--;
	// 	}
	// }

	if (target_pos == -1)
	{
		target_pos = stacks->stack_a_len - 1;
	}

	return (target_pos);
}

void	push_back_to_a(t_stacks *stacks)
{
	int	target_pos;

	while (stacks->stack_b_len > 0)
	{

		target_pos = find_correct_pos_in_a(stacks);

		if (target_pos >= stacks->stack_a_len / 2)
		{
			while (target_pos != stacks->stack_a_len - 1)
			{
				rotate_a(stacks);
				target_pos = (target_pos + 1) % stacks->stack_a_len;
			}
		}
		else
		{
			while (target_pos != stacks->stack_a_len - 1)
			{
				reverse_rotate_a(stacks);
				target_pos = (target_pos - 1 + stacks->stack_a_len) % stacks->stack_a_len;
			}
		}
		// printf("b_len: %d\n", stacks->stack_b_len);
		push_a(stacks);
	}
}


void	sort(t_stacks *stacks)
{
	// int	cheapest_index;

	if (stacks->stack_a_len == 4)
		push_b(stacks);
	else if (stacks->stack_a_len >= 5)
	{
		push_b(stacks);
		push_b(stacks);
	}

	// while (stacks->stack_a_len > 5)
	// {
	// 	cheapest_index = find_cheapest_in_a(stacks);
	// 	push_cheapest_to_b(stacks, cheapest_index);
	// }

	// int	max_index_b = max_index(stacks->stack_b, stacks->stack_b_len);

	// if (max_index_b >= stacks->stack_b_len / 2)
	// {
	// 	while (max_index_b != stacks->stack_b_len - 1)
	// 	{
	// 		rotate_b(stacks);
	// 		max_index_b = (max_index_b + 1) % stacks->stack_b_len;
	// 	}
	// }
	// else
	// {
	// 	while (max_index_b != stacks->stack_b_len - 1)
	// 	{
	// 		reverse_rotate_b(stacks);
	// 		max_index_b = (max_index_b - 1 + stacks->stack_b_len) % stacks->stack_b_len;
	// 	}
	// }

	// sort_5(stacks, stacks->stack_a, stacks->stack_a_len);


	push_average_to_b(stacks);

	sort_3(stacks->stack_a, stacks->stack_a_len);

	push_back_to_a(stacks);

	int	min_index_a = min_index(stacks->stack_a, stacks->stack_a_len);
	if (min_index_a != stacks->stack_a_len - 1)
	{
		if (min_index_a >= stacks->stack_a_len / 2)
		{
			while (min_index_a != stacks->stack_a_len - 1)
			{
				rotate_a(stacks);
				min_index_a = (min_index_a + 1) % stacks->stack_a_len;
			}
		}
		else
		{
			while (min_index_a != stacks->stack_a_len - 1)
			{
				reverse_rotate_a(stacks);
				min_index_a = (min_index_a - 1 + stacks->stack_a_len) % stacks->stack_a_len;
			}
		}
	}

	// sort_3(stacks->stack_a, stacks->stack_a_len);

	// push_back_to_a(stacks);

	// int	min;

	// min = stacks->stack_a[stacks->stack_a_len - 1];
	// int	i = stacks->stack_a_len - 2;
	// // printf("%d. min before: %d. stack_b_len: %d\n", i, min, stacks->stack_b_len);
	// while (i >= 0)
	// {
	// 	// printf("%d. min before: %d\n", i, min);
	// 	if (stacks->stack_a[i] < min)
	// 	{
	// 		min = stacks->stack_a[i];
	// 		// printf("%d. min after: %d\n", i, min);
	// 	}
	// 	i--;
	// }

	// i = 0;

	// while (i <= stacks->stack_a_len - 1)
	// {
	// 	if (stacks->stack_a[i] == min)
	// 		break ;
	// 	i++;
	// }

	// if (i >= stacks->stack_a_len / 2)
	// {
	// 	while (min != stacks->stack_a[stacks->stack_a_len - 1])
	// 		rotate_a(stacks);
	// }

	// else
	// 	while (min != stacks->stack_a[stacks->stack_a_len - 1])
	// 		reverse_rotate_a(stacks);

}

// void	sort_a(t_stacks *stacks)
// {
// 	int	cheapest_index;

// 	if (stacks->stack_a_len == 4)
// 		push_b(stacks);
// 	else if (stacks->stack_a_len >= 5)
// 	{
// 		push_b(stacks);
// 		push_b(stacks);
// 	}

// 	while (stacks->stack_a_len > 3)
// 	{
// 		cheapest_index = find_cheapest_in_a(stacks);
// 		push_cheapest_to_b(stacks, cheapest_index);
// 	}

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

	// int	max_b = find_max(stacks);
	// int	i;

	// int	min = find_min(stacks);

	// while (stacks->stack_b_len > 0)
	// 	push_a(stacks);

	// int i = 0;

	// while (i <= stacks->stack_a_len - 1)
	// {
	// 	if (stacks->stack_a[i] == min)
	// 		break ;
	// 	i++;
	// }

	// if (i >= stacks->stack_a_len / 2)
	// {
	// 	while (min != stacks->stack_a[stacks->stack_a_len - 1])
	// 		rotate_a(stacks);
	// }

	// else
	// 	while (min != stacks->stack_a[stacks->stack_a_len - 1])
	// 		reverse_rotate_a(stacks);

// }
	// int	min;

	// min = stacks->stack_a[stacks->stack_a_len - 1];
	// int	i = stacks->stack_a_len - 2;
	// // printf("%d. min before: %d. stack_b_len: %d\n", i, min, stacks->stack_b_len);
	// while (i >= 0)
	// {
	// 	// printf("%d. min before: %d\n", i, min);
	// 	if (stacks->stack_a[i] < min)
	// 	{
	// 		min = stacks->stack_a[i];
	// 		// printf("%d. min after: %d\n", i, min);
	// 	}
	// 	i--;
	// }

	// i = 0;

	// while (i <= stacks->stack_a_len - 1)
	// {
	// 	if (stacks->stack_a[i] == min)
	// 		break ;
	// 	i++;
	// }

	// if (i >= stacks->stack_a_len / 2)
	// {
	// 	while (min != stacks->stack_a[stacks->stack_a_len - 1])	// int	min;

	// min = stacks->stack_a[stacks->stack_a_len - 1];
	// int	i = stacks->stack_a_len - 2;
	// // printf("%d. min before: %d. stack_b_len: %d\n", i, min, stacks->stack_b_len);
	// while (i >= 0)
	// {
	// 	// printf("%d. min before: %d\n", i, min);
	// 	if (stacks->stack_a[i] < min)
	// 	{
	// 		min = stacks->stack_a[i];
	// 		// printf("%d. min after: %d\n", i, min);
	// 	}
	// 	i--;
	// }

	// i = 0;

	// while (i <= stacks->stack_a_len - 1)
	// {
	// 	if (stacks->stack_a[i] == min)
	// 		break ;
	// 	i++;
	// }			printf("Unsorted --> stack_A: %d stack_pesort: %d", stacks->stack_a[i], stacks->stack_presort[i]);


	// 		rotate_a(stacks);
	// }

	// else
	// 	while (min != stacks->stack_a[stacks->stack_a_len - 1])
	// 		reverse_rotate_a(stacks);
