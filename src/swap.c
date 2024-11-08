/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:24:11 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/08 20:23:48 by asplavni         ###   ########.fr       */
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
		for (int i = 0; i < stacks->stack_a_count; i++)
			printf("%d. stack_A after: %d\n", i, stacks->stack_a[i]);
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
		for (int i = 0; i < stacks->stack_b_count; i++)
			printf("%d. stack_B after: %d\n", i, stacks->stack_b[i]);
		ft_putstr("sa\n");
	}

}
