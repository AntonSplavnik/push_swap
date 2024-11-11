/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:40:20 by antonsplavn       #+#    #+#             */
/*   Updated: 2024/11/11 21:49:19 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_largest(t_stacks *stacks)
{
	int	buffer;

	buffer = stacks->stack_a[stacks->stack_a_len - 1];
	if (buffer < stacks->stack_a[stacks->stack_a_len - 2])
		buffer = stacks->stack_a[stacks->stack_a_len - 2];
	else if (buffer < stacks->stack_a[stacks->stack_a_len - 3])
		buffer = stacks->stack_a[stacks->stack_a_len - 3];

	return (buffer);
}

void	algorythm(t_stacks *stacks)
{
	int	largest_num;

	if (stacks->stack_a_len == 3)
	{
		largest_num = calc_largest(stacks);
		if (stacks->stack_a[stacks->stack_a_len - 1] == largest_num)
			rotate_a(stacks);
		else if (stacks->stack_a[stacks->stack_a_len - 2] == largest_num)
			reverse_rotate_a(stacks);
		if (stacks->stack_a[stacks->stack_a_len - 1] > \
		stacks->stack_a[stacks->stack_a_len - 2])
			swap_a(stacks);
	}
	// reverse_rotate_a(stacks);
	// rotate_a(stacks);
	// push_b(stacks);
	// push_b(stacks);
	// swap_a(stacks);
	// swap_b(stacks);
}
