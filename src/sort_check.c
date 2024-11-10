/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:10:28 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/10 19:38:30 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_check(t_stacks *stacks)
{
	int	i;

	i = stacks->stack_a_len - 1;
	while (i > 0)
	{
		if (stacks->stack_a[i] > stacks->stack_a[i - 1])
		{
			printf ("Unsorted\n");
			return ;
		}
		i--;
	}
	printf("Sorted\n");
}
