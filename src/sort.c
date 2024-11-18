/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:26:33 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/18 16:18:36 by asplavni         ###   ########.fr       */
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

int	calculate_operation(t_stacks *stacks, int index)
{
	int	num;
	int	pos_b;
	int	operations_a;
	int	operations_b;

	num = stacks->stack_a[index];
	pos_b = calculate_operations_b(stacks, num);
	printf("num_a: %d num_of_op_b: %d\n", num, pos_b);
	if (index <= stacks->stack_a_len / 2)
		operations_a = index;
	else
		operations_a = stacks->stack_a_len - index;
	if (pos_b <= stacks->stack_b_len / 2)
		operations_b = pos_b;
	else
		operations_b = stacks->stack_b_len - pos_b;

	if ((index <= stacks->stack_a_len / 2 && pos_b <= stacks->stack_b_len / 2) \
		|| (index > stacks->stack_a_len / 2 && pos_b > stacks->stack_b_len / 2))
	{
		if (operations_a > operations_b)
			return (operations_a);
		else
			return (operations_b);
	}
	return (operations_a + operations_b);
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
void push_cheapest(t_stacks *stacks, int index)
{
    int num = stacks->stack_a[index];
    int pos_b = find_correct_position(stacks, num);

    printf("cheapest_index: %d\n", index);
    printf("num_a_chosen: %d pos_b: %d\n", num, pos_b);

    // Step 1: Rotate STACK_A to bring the chosen number to the top
    if (index <= stacks->stack_a_len / 2)
    {
        // Rotate upwards if the element is in the first half
        while (index > 0)
        {
            rotate_a(stacks);
            index--;
        }
    }
    else
    {
        // Reverse rotate downwards if the element is in the second half
        while (index != stacks->stack_a_len - 1)
        {
            reverse_rotate_a(stacks);
            index++;
            if (index >= stacks->stack_a_len)  // Wrap around correction
                index = 0;
        }
    }

    // Step 2: Rotate STACK_B to prepare for insertion
    if (pos_b == stacks->stack_b_len - 1 || stacks->stack_b_len == 0)
    {
        // If pos_b is at the top or STACK_B is empty, push directly
        push_b(stacks);
    }
    else if (pos_b <= stacks->stack_b_len / 2)
    {
        // Rotate upwards if the position is in the first half
        while (pos_b > 0)
        {
            rotate_b(stacks);
            pos_b--;
        }
        push_b(stacks);
    }
    else
    {
        // Reverse rotate downwards if the position is in the second half
        while (pos_b != stacks->stack_b_len)
        {
            reverse_rotate_b(stacks);
            pos_b++;
            if (pos_b >= stacks->stack_b_len)  // Wrap around correction
                pos_b = 0;
        }
        push_b(stacks);
    }
}

// void	push_cheapest(t_stacks *stacks, int index)
// {
// 	int	num = stacks->stack_a[index];
// 	int	pos_b = find_correct_position(stacks, num);

// 	printf("cheapest_index: %d\n", index);
// 	printf("num_a_chosen: %d pos_b: %d\n", num, pos_b);

// 	if (index <= stacks->stack_a_len / 2)
// 	{
// 		while (index > 0)
// 		{
// 			rotate_a(stacks);
// 			index--;
// 		}
// 	}
// 	else
// 	{
// 		while (index < stacks->stack_a_len - 1)
// 		{
// 			reverse_rotate_a(stacks);
// 			index++;
// 		}

// 	}

// 	if (pos_b == stacks->stack_b_len -1)
// 		push_b(stacks);

// 	else if (pos_b <= stacks->stack_b_len / 2)
// 	{
// 		while (pos_b > 0)
// 		{

// 			rotate_b(stacks);
// 			pos_b--;
// 		}
// 		push_b(stacks);

// 	}
// 	else
// 	{
// 		while (pos_b < stacks->stack_b_len)
// 		{
// 			reverse_rotate_b(stacks);
// 			pos_b++;
// 		}
// 		push_b(stacks);

// 	}
// }

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
