/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:24:11 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/05 21:26:52 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks	*stacks)
{
	int	buffer;

	if (stacks->stack_a_count > 1)
	{
		buffer = stacks->stack_a[0];
		stacks->stack_a[0] = stacks->stack_a[1];
		stacks->stack_a[1] = buffer;
		ft_putstr("sa\n");
	}

}

void	swap_b(t_stacks	*stacks)
{
	int	buffer;

	if (stacks->stack_b_count > 1)
	{
		buffer = stacks->stack_b[0];
		stacks->stack_b[0] = stacks->stack_b[1];
		stacks->stack_b[1] = buffer;
		ft_putstr("sa\n");
	}

}
