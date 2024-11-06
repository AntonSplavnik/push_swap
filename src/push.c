/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:56:21 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/06 22:34:32 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stacks)
{
	reverse_rotate_b(stacks);
	stacks->stack_b[0] = stacks->stack_a[0];
	stacks->stack_a[0] = stacks->stack_a[stacks->stack_b_count];
	rotate_a(stacks);
	for (int i = 0; i < stacks->stack_a_count; i++)
		printf("%d. stack_A after: %d\n", i, stacks->stack_a[i]);
	ft_putstr("\n");
	for (int i = 0; i < stacks->stack_b_count; i++)
		printf("%d. stack_B after: %d\n", i, stacks->stack_b[i]);
}

void	push_b(t_stacks *stacks)
{
	reverse_rotate_b(stacks);
	stacks->stack_a[0] = stacks->stack_b[0];
	stacks->stack_b[0] = stacks->stack_b[stacks->stack_a_count];
	rotate_a(stacks);
	for (int i = 0; i < stacks->stack_a_count; i++)
		printf("%d. stack_A after: %d\n", i, stacks->stack_a[i]);
	ft_putstr("\n");
	for (int i = 0; i < stacks->stack_b_count; i++)
		printf("%d. stack_B after: %d\n", i, stacks->stack_b[i]);
}
