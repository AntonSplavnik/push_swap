/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:40:20 by antonsplavn       #+#    #+#             */
/*   Updated: 2024/11/29 00:34:14 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "algorithm.h"

void	move_samllest_to_top(t_stacks *stacks)
{
	int	min_index_a;

	min_index_a = min_index(stacks->stack_a, stacks->stack_a_len);
	if (min_index_a != stacks->stack_a_len - 1)
	{
		move_index_a_top(stacks, min_index_a);
	}
}

void	algorithm(t_stacks *stacks)
{
	int	cheapest_index;

	if (stacks->stack_a_len == 2)
	{
		if (stacks->stack_a[1] > stacks->stack_a[0])
			swap_a(stacks, 1);
		return ;
	}
	if (stacks->stack_a_len == 3)
	{
		sort_3(stacks->stack_a, stacks->stack_a_len);
		return ;
	}
	while (stacks->stack_a_len > 3)
	{
		push_average_to_b(stacks);
	}
	sort_3(stacks->stack_a, stacks->stack_a_len);
	while (stacks->stack_b_len > 0)
	{
		cheapest_index = find_cheapest_in_b(stacks);
		push_cheapest_to_a(stacks, cheapest_index);
	}
	move_samllest_to_top(stacks);
}
