/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_average.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:34:50 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 01:26:59 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "algorithm.h"

int ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

int	sum(int *stack, int len)
{
	int	sum;
	int	i;

	sum = 0;
	i = len - 1;
	while (i >= 0)
	{
		sum += stack[i];
		i--;
	}
	return (sum);
}

int	find_index(int	*stack, int len, int num)
{
	int	i;

	i = len - 1;
	while(i >= 0)
	{
		if (stack[i] == num)
			return (i);
		i--;
	}
	return (-1);
}

int	find_closes_num(int	*stack, int len, int average)
{
	int	closest_number = stack[len - 1];
	int	closest_diff = ft_abs(closest_number - average);

	int i = len - 2;
	while (i >= 0)
	{
		int	diff = ft_abs(stack[i] - average);
		if (diff < closest_diff)
			{
				closest_diff = diff;
				closest_number = stack[i];
			}
		i--;
	}
	return (closest_number);
}

int	find_index_to_push(int *stack, int len, int avrg)
{
	int	i = len - 1;
	while (i >= 0)
	{
		if (stack[i] > avrg)
			return i;
		i--;
	}
	return (-1);
}
void	push_average_to_b(t_stacks *stacks)
{
		int	average = sum(stacks->stack_a, stacks->stack_a_len) / stacks->stack_a_len;
		int	index_to_push = find_index_to_push(stacks->stack_a, stacks->stack_a_len, average);
		// int	closest_number = find_closes_num(stacks->stack_a, stacks->stack_a_len, average);
		// int	index_of_closesst = find_index(stacks->stack_a, stacks->stack_a_len, closest_number);
		// int	index_of_num_to_push = find_index(stacks->stack_a, stacks->stack_a_len, number_to_push);
		if (index_to_push == -1)
		{
			printf("error: index\n");
			free_stacks(stacks);
			exit (1);
		}

		if (index_to_push >= stacks->stack_a_len / 2)
		{
			while (index_to_push != stacks->stack_a_len - 1)
			{
				rotate_a(stacks, 1);
				index_to_push = (index_to_push + 1) % stacks->stack_a_len;
			}
		}
		else
		{
			while (index_to_push != stacks->stack_a_len - 1)
			{
				reverse_rotate_a(stacks, 1);
				index_to_push = (index_to_push - 1 + stacks->stack_a_len) % stacks->stack_a_len;
			}
		}
		push_b(stacks, 1);

}
