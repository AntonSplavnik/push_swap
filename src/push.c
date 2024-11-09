/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:56:21 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/09 21:26:13 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_stacks *stacks)
{
	if (stacks->stack_b_len == 0)
		return ;
	if (stacks->stack_a_len == 0)
	{
		stacks->stack_a[0] = stacks->stack_b[stacks->stack_b_len - 1];
		stacks->stack_a_len++;
		stacks->stack_b_len--;
	}
	else
	{
		stacks->stack_a[stacks->stack_a_len] = stacks->stack_b[stacks->stack_b_len - 1];
		stacks->stack_a_len++;
		stacks->stack_b_len--;
	}

	ft_putstr("\nafter push_a\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	ft_putstr("\n");
	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}

void	push_b(t_stacks *stacks)
{
	if (stacks->stack_a_len == 0)
		return ;
	if (stacks->stack_b_len == 0)
	{
		stacks->stack_b[0] = stacks->stack_a[stacks->stack_a_len - 1];
		stacks->stack_b_len++;
		stacks->stack_a_len--;
	}
	else
	{
		stacks->stack_b[stacks->stack_b_len] = stacks->stack_a[stacks->stack_a_len - 1];
		stacks->stack_b_len++;
		stacks->stack_a_len--;
	}

	ft_putstr("\nafter push_b\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);
	// printf("stack_a_len = %d\n",stacks->stack_a_len);

	ft_putstr("\n");
	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
	// printf("stack_b_len = %d\n",stacks->stack_b_len);
}
