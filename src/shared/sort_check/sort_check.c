/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:10:28 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 19:09:11 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "algorithm.h"

int	sort_check(int *input, int len)
{
	int	i;

	i = len - 1;
	while (i > 0)
	{
		if (input[i] > input[i - 1])
		{
			return (1);
		}
		i--;
	}
	return (0);
}

int	sort_compare(t_stacks *stacks)
{
	int	i;

	i = stacks->stack_a_len - 1;
	while (i >= 0)
	{
		if (stacks->stack_a[i] != stacks->stack_presort[i])
		{
			return (1);
		}
		i--;
	}
	return (0);
}
