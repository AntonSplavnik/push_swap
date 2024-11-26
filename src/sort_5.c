/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:36:57 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/26 23:22:45 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int calc_smallest(int *stack, int len)
{
    int smallest = stack[len - 1];
    for (int i = len - 2; i >= 0; i--)
    {
        if (stack[i] < smallest)
            smallest = stack[i];
    }
    return smallest;
}

int calc_largest(int *stack, int len)
{
    int largest = stack[len - 1];
    for (int i = len - 2; i >= 0; i--)
    {
        if (stack[i] > largest)
            largest = stack[i];
    }
    return largest;
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

void sort_5(t_stacks *stacks)
{

	if (stacks->stack_a_len != 5 || sort_check(stacks->stack_a, stacks->stack_a_len) == 0)
	{
		return ;
	}

    // Step 1: Move largest number to the top of the stack
	while (stacks->stack_a_len > 3)
	{
		int	max_index_a = max_index(stacks->stack_a, stacks->stack_a_len);

		if (max_index_a >= stacks->stack_a_len / 2)
		{
			while (max_index_a != stacks->stack_a_len - 1)
			{
				rotate_a(stacks);
				max_index_a = (max_index_a + 1) % stacks->stack_a_len;
			}
		}
		else
		{
			while (max_index_a != stacks->stack_a_len - 1)
			{
				reverse_rotate_a(stacks);
				max_index_a = (max_index_a - 1 + stacks->stack_a_len) % stacks->stack_a_len;
			}
		}

		push_b(stacks);
	}

	// swap numbers in b if needed
	if (stacks->stack_b[stacks->stack_b_len - 1] < stacks->stack_b[stacks->stack_b_len - 2])
	{
		swap_b(stacks);
	}

	sort_3(stacks->stack_a, stacks->stack_a_len);

	// push back to A
	int	i = 0;
	while (i < 2)
	{
		int	target_pos = find_correct_pos_in_a(stacks);

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
		i++;
	}

//	bring smallest index to the top of A
	int	min_index_a = min_index(stacks->stack_a, stacks->stack_a_len);
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
