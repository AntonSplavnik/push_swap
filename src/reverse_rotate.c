/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:57:57 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/20 23:55:07 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(int *stack, int len)
{
	int	buffer;
	int	i;

	i = 0;
	buffer = stack[0];
	if (len < 2)
		return ;
	while (i < len -1)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[len - 1] = buffer;
}

void	reverse_rotate_a(t_stacks *stacks)
{
	if (stacks->stack_a_len < 2)
		return ;
	reverse_rotate(stacks->stack_a, stacks->stack_a_len);
	ft_putstr("rra\n");

	ft_putstr("after reverse_rotate_a\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);
	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}

void	reverse_rotate_b(t_stacks *stacks)
{
	if (stacks->stack_b_len < 2)
		return ;
	reverse_rotate(stacks->stack_b, stacks->stack_b_len);
	ft_putstr("rrb\n");

	ft_putstr("after reverse_rotate_b\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);
	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}

void	reverse_rotate_a_b(t_stacks *stacks)
{
	if (stacks->stack_a_len < 2 || stacks->stack_b_len < 2)
		return ;
	reverse_rotate(stacks->stack_a, stacks->stack_a_len);
	reverse_rotate(stacks->stack_b, stacks->stack_b_len);
	ft_putstr("rrr\n");

	ft_putstr("after reverse_rotate_a_b\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);
	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}
