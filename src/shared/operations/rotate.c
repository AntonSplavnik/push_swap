/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 16:21:26 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 19:13:48 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

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

void	rotate_a(t_stacks *stacks, int flag)
{
	if (stacks->stack_a_len < 2)
		return ;
	rotate(stacks->stack_a, stacks->stack_a_len);
	if (flag == 1)
		ft_putstr("ra\n");
}

void	rotate_b(t_stacks *stacks, int flag)
{
	if (stacks->stack_b_len < 2)
		return ;
	rotate(stacks->stack_b, stacks->stack_b_len);
	if (flag == 1)
		ft_putstr("rb\n");
}

void	rotate_a_b(t_stacks *stacks, int flag)
{
	if (stacks->stack_a_len < 2 || stacks->stack_b_len < 2)
		return ;
	rotate(stacks->stack_a, stacks->stack_a_len);
	rotate(stacks->stack_b, stacks->stack_b_len);
	if (flag == 1)
		ft_putstr("rr\n");
}
