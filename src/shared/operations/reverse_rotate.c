/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 17:57:57 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 01:21:59 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

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

void	reverse_rotate_a(t_stacks *stacks, int flag)
{
	if (stacks->stack_a_len < 2)
		return ;
	reverse_rotate(stacks->stack_a, stacks->stack_a_len);
	if (flag == 1)
		ft_putstr("rra\n");
}

void	reverse_rotate_b(t_stacks *stacks, int flag)
{
	if (stacks->stack_b_len < 2)
		return ;
	reverse_rotate(stacks->stack_b, stacks->stack_b_len);
	if (flag == 1)
		ft_putstr("rrb\n");
}

void	reverse_rotate_a_b(t_stacks *stacks, int flag)
{
	if (stacks->stack_a_len < 2 || stacks->stack_b_len < 2)
		return ;
	reverse_rotate(stacks->stack_a, stacks->stack_a_len);
	reverse_rotate(stacks->stack_b, stacks->stack_b_len);
	if (flag == 1)
		ft_putstr("rrr\n");
}
