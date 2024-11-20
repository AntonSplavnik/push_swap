/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:21:26 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/20 23:54:29 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(int *stack, int len)
{
	int	buffer;
	int	i;

	if (len < 2)
		return ;

	buffer = stack[len - 1];

	i = len - 1;
	while (i > 0)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[0] = buffer;
}

void	rotate_a(t_stacks *stacks)
{
	if (stacks->stack_a_len < 2)
		return ;
	rotate(stacks->stack_a, stacks->stack_a_len);
	ft_putstr("ra\n");

	ft_putstr("after rotate_a\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);
	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}

void	rotate_b(t_stacks *stacks)
{
	if (stacks->stack_b_len < 2)
		return ;
	rotate(stacks->stack_b, stacks->stack_b_len);
	ft_putstr("rb\n");

	ft_putstr("after rotate_b\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);
	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}

void	rotate_a_b(t_stacks *stacks)
{
	if (stacks->stack_a_len < 2 || stacks->stack_b_len < 2)
		return ;
	rotate(stacks->stack_a, stacks->stack_a_len);
	rotate(stacks->stack_b, stacks->stack_b_len);
	ft_putstr("rr\n");

	ft_putstr("after rotate_a_b\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);
	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}
