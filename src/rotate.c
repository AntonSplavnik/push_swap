/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:25:16 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/05 22:01:37 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	int	buffer;

	if (stacks->stack_a_count > 1)
	{
		buffer = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[stacks->stack_a_count - 1];
		stacks->stack_a[stacks->stack_a_count - 1] = buffer;
		ft_putstr("ra\n");
	}

}

void	rotate_b(t_stacks *stacks)
{
	int	buffer;

	if (stacks->stack_b_count > 1)
	{
		buffer = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[stacks->stack_b_count - 1];
		stacks->stack_b[stacks->stack_b_count - 1] = buffer;
		ft_putstr("rb\n");
	}
}
