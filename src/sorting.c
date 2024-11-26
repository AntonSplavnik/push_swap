/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:40:20 by antonsplavn       #+#    #+#             */
/*   Updated: 2024/11/26 20:25:54 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sorter(t_stacks *stacks)
{
	if (stacks->stack_a_len == 3)
		sort_3(stacks->stack_a, stacks->stack_a_len);
	else
	quicksort(stacks->stack_presort, 0, stacks->stack_presort_len - 1);
	ft_putstr("quicksorted stack_presort\n");
	for (int i = stacks->stack_presort_len; i > 0; i--)
		printf("%d. stack_presort: %d\n", i - 1, stacks->stack_presort[i - 1]);
	move_to_correct_position(stacks);
}

void	algorythm(t_stacks *stacks)
{
	quicksort(stacks->stack_presort, 0, stacks->stack_presort_len - 1);
	sort(stacks);

	ft_putstr("\nEND OF OPERATIONS\n");

	// for (int i = stacks->stack_a_len; i > 0; i--)
	// 	printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	// ft_putstr("\n");

	// for (int i = stacks->stack_b_len; i > 0; i--)
	// 	printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);

	// ft_putstr("\n");
	// for (int i = stacks->stack_presort_len; i > 0; i--)
	// 	printf("%d. stack_presort: %d\n", i - 1, stacks->stack_presort[i - 1]);
}
