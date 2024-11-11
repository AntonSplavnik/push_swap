/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 22:08:10 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/11 20:36:16 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate_a(t_stacks *stacks)
{
	int	buffer;
	int	i;

	i = 0;
	buffer = stacks->stack_a[0];

	if (stacks->stack_a_len < 1)
		return ;

	while (i < stacks->stack_a_len - 1)
	{
		stacks->stack_a[i] = stacks->stack_a[i + 1];
		i++;
	}
	stacks->stack_a[stacks->stack_a_len - 1] = buffer;

	ft_putstr("\nafter reverse rotate_a\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	ft_putstr("\n");

	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}

void	reverse_rotate_b(t_stacks *stacks)
{
	int	buffer;
	int	i;

	i = 0;
	buffer = stacks->stack_b[0];

	if (stacks->stack_b_len < 1)
		return ;

	while (i < stacks->stack_b_len - 1)
	{
		stacks->stack_b[i] = stacks->stack_b[i + 1];
		i++;
	}
	stacks->stack_b[stacks->stack_b_len - 1] = buffer;

	ft_putstr("\nafter reverse rotate_a\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	ft_putstr("\n");

	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}
