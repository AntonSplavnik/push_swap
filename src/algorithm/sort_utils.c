/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/29 00:01:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/29 00:35:58 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algorithm.h"

void	move_index_a_top(t_stacks *stacks, int index)
{
	if (index >= stacks->stack_a_len / 2)
	{
		while (index != stacks->stack_a_len - 1)
		{
			rotate_a(stacks, 1);
			index = (index + 1) % stacks->stack_a_len;
		}
	}
	else
	{
		while (index != stacks->stack_a_len - 1)
		{
			reverse_rotate_a(stacks, 1);
			index = (index - 1 + stacks->stack_a_len) \
				% stacks->stack_a_len;
		}
	}
}

void	move_index_b_top(t_stacks *stacks, int index)
{
	if (index >= stacks->stack_b_len / 2)
	{
		while (index != stacks->stack_b_len - 1)
		{
			rotate_b(stacks, 1);
			index = (index + 1) % stacks->stack_b_len;
		}
	}
	else
	{
		while (index != stacks->stack_b_len - 1)
		{
			reverse_rotate_b(stacks, 1);
			index = (index - 1 + stacks->stack_b_len) % stacks->stack_b_len;
		}
	}
}
