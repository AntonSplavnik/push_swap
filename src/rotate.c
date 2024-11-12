/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 21:25:16 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/12 18:55:19 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_stacks *stacks)
{
	if (stacks->stack_a_len < 1)
		return ;
	int	buffer;
	buffer = stacks->stack_a[stacks->stack_a_len - 1];

	int	i;
	i = stacks->stack_a_len;
	while (i > 0)
	{
		stacks->stack_a[i - 1] = stacks->stack_a[i - 2];
		i--;
	}
	stacks->stack_a[0] = buffer;

	// ft_putstr("\nafter rotate_a\n");
	// for (int i = stacks->stack_a_len; i > 0; i--)
	// 	printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	// ft_putstr("\n");

	// for (int i = stacks->stack_b_len; i > 0; i--)
	// 	printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
	ft_putstr("ra\n");
}

void	rotate_b(t_stacks *stacks)
{
	if (stacks->stack_b_len < 1)
		return ;
	int	buffer;
	buffer = stacks->stack_b[stacks->stack_b_len - 1];

	int	i;
	i = stacks->stack_b_len;
	while (i > 0)
	{
		stacks->stack_b[i - 1] = stacks->stack_b[i - 2];
		i--;
	}
	stacks->stack_b[0] = buffer;

	// ft_putstr("\nafter rotate_a\n");
	// for (int i = stacks->stack_a_len; i > 0; i--)
	// 	printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	// ft_putstr("\n");

	// for (int i = stacks->stack_b_len; i > 0; i--)
	// 	printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
	ft_putstr("rb\n");
}

void	rotate_a_b(t_stacks *stacks)
{
	rotate_a(stacks);
	rotate_b(stacks);

	// ft_putstr("\nafter rotate_a_b\n");
	// for (int i = stacks->stack_a_len; i > 0; i--)
	// 	printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	// ft_putstr("\n");

	// for (int i = stacks->stack_b_len; i > 0; i--)
	// 	printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}
