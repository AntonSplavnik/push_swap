/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 14:10:28 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/14 17:57:44 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_check(int *input, int len)
{
	int	i;

	i = len - 1;
	while (i > 0)
	{
		if (input[i] > input[i - 1])
		{
			printf ("Unsorted\n");
			return (1);
		}
		i--;
	}
	printf("Sorted\n");
	return (0);
}

// int	sort_check(t_stacks *stacks)
// {
// 	int	i;

// 	i = stacks->stack_a_len - 1;
// 	while (i > 0)
// 	{
// 		if (stacks->stack_a[i] > stacks->stack_a[i - 1])
// 		{
// 			printf ("Unsorted\n");
// 			return (1);
// 		}
// 		i--;
// 	}
// 	printf("Sorted\n");
// 	return (0);
// }