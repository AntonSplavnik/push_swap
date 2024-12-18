/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:56:21 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 19:16:50 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	push_a(t_stacks *stacks, int flag)
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
		stacks->stack_a[stacks->stack_a_len] \
		= stacks->stack_b[stacks->stack_b_len - 1];
		stacks->stack_a_len++;
		stacks->stack_b_len--;
	}
	if (flag == 1)
		ft_putstr("pa\n");
}

void	push_b(t_stacks *stacks, int flag)
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
		stacks->stack_b[stacks->stack_b_len] \
		= stacks->stack_a[stacks->stack_a_len - 1];
		stacks->stack_b_len++;
		stacks->stack_a_len--;
	}
	if (flag == 1)
		ft_putstr("pb\n");
}
