/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 19:24:11 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/09 22:02:05 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stacks *stacks)
{
	if (stacks->stack_a_len < 1)
		return ;
	int	buffer;

	buffer = stacks->stack_a[stacks->stack_a_len - 2];
	stacks->stack_a[stacks->stack_a_len - 2] = stacks->stack_a[stacks->stack_a_len - 1];
	stacks->stack_a[stacks->stack_a_len - 1] = buffer;

	ft_putstr("\nafter swap_a\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	ft_putstr("\n");

	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}

void	swap_b(t_stacks *stacks)
{
	if (stacks->stack_b_len < 1)
		return ;
	int	buffer;

	buffer = stacks->stack_b[stacks->stack_b_len - 2];
	stacks->stack_b[stacks->stack_b_len - 2] = stacks->stack_b[stacks->stack_b_len - 1];
	stacks->stack_b[stacks->stack_b_len - 1] = buffer;

	ft_putstr("\nafter swap_b\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	ft_putstr("\n");

	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}