/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:08:10 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/05 22:13:07 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stacks *stacks)
{
	int	buffer;

	if (stacks->stack_a_count > 1)
	{
		buffer = stacks->stack_a[stacks->stack_a_count - 1];
		stacks->stack_a[stacks->stack_a_count - 1] = stacks->stack_a[0];
		stacks->stack_a[0] = buffer;
		ft_putstr("rra\n");
	}
}

void	reverse_rotate_b(t_stacks *stacks)
{
	int	buffer;

	if (stacks->stack_b_count > 1)
	{
		buffer = stacks->stack_b[stacks->stack_b_count - 1];
		stacks->stack_b[stacks->stack_b_count - 1] = stacks->stack_b[0];
		stacks->stack_b[0] = buffer;
		ft_putstr("rrb\n");
	}
}
