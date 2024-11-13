/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:58:29 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/13 19:14:03 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(int *stack, int len)
{
	int	buffer;

	if (len < 2)
		return ;
	buffer = stack[len - 2];
	stack[len - 2] = stack[len - 1];
	stack[len - 1] = buffer;
}

void	swap_a(t_stacks *stacks)
{
	if (stacks->stack_a_len < 2)
		return ;
	swap(stacks->stack_a, stacks->stack_a_len);
	ft_putstr("sa\n");
}

void	swap_b(t_stacks *stacks)
{
	if (stacks->stack_b_len < 2)
		return ;
	swap(stacks->stack_b, stacks->stack_b_len);
	ft_putstr("sb\n");
}

void	swap_a_b(t_stacks *stacks)
{
	if (stacks->stack_a_len < 2 || stacks->stack_b_len < 2)
		return ;
	swap(stacks->stack_a, stacks->stack_a_len);
	swap(stacks->stack_b, stacks->stack_b_len);
	ft_putstr("ss\n");
}
