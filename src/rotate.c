/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:25:16 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/06 21:00:15 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	int	buffer;
	int	i;

	i = 0;
	if (stacks->stack_a_count > 1)
	{
		buffer = stacks->stack_a[0];
		while (i <= stacks->stack_a_count - 1)
		{
			stacks->stack_a[i] = stacks->stack_a[i + 1];
			i++;
		}
		stacks->stack_a[stacks->stack_a_count - 1] = buffer;
	}
	for (int i = 0; i < stacks->stack_a_count; i++)
		printf("%d. stack_A after: %d\n", i, stacks->stack_a[i]);
	ft_putstr("ra\n");
}

void	rotate_b(t_stacks *stacks)
{
	int	buffer;
	int	i;

	i = 0;
	if (stacks->stack_b_count > 1)
	{
		buffer = stacks->stack_b[0];
		while (i <= stacks->stack_b_count - 1)
		{
			stacks->stack_b[i] = stacks->stack_b[i + 1];
			i++;
		}
		stacks->stack_b[stacks->stack_b_count - 1] = buffer;
	}
	for (int i = 0; i < stacks->stack_b_count; i++)
		printf("%d. stack_B after: %d\n", i, stacks->stack_b[i]);
	ft_putstr("rb\n");
}