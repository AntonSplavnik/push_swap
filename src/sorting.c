/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:40:20 by antonsplavn       #+#    #+#             */
/*   Updated: 2024/11/12 18:51:36 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_largest(t_stacks *stacks)
{
	int	buffer;

	buffer = stacks->stack_a[stacks->stack_a_len - 1];
	if (buffer < stacks->stack_a[stacks->stack_a_len - 2])
		buffer = stacks->stack_a[stacks->stack_a_len - 2];
	else if (buffer < stacks->stack_a[stacks->stack_a_len - 3])
		buffer = stacks->stack_a[stacks->stack_a_len - 3];

	return (buffer);
}

void	sort_3(t_stacks *stacks)
{
	int	largest_num;

	largest_num = calc_largest(stacks);
	if (stacks->stack_a[stacks->stack_a_len - 1] == largest_num)
		rotate_a(stacks);
	else if (stacks->stack_a[stacks->stack_a_len - 2] == largest_num)
		reverse_rotate_a(stacks);
	if (stacks->stack_a[stacks->stack_a_len - 1] > \
	stacks->stack_a[stacks->stack_a_len - 2])
		swap_a(stacks);
}

// void	sorter(t_stacks *stacks)
// {

// }

void	algorythm(t_stacks *stacks)
{
	if (stacks->stack_a_len == 3)
		sort_3(stacks);
	else
	{
		quicksort(stacks->stack_presort, 0, stacks->stack_presort_len - 1);
	}
	// ft_putstr("quicksorted stack_presort\n");
	// for (int i = stacks->stack_presort_len; i > 0; i--)
	// 	printf("%d. stack_presort: %d\n", i - 1, stacks->stack_presort[i - 1]);

	int	i;
	i = 0;
	while (i < stacks->stack_presort_len)
	{
		if (stacks->stack_a[stacks->stack_a_len - 1] == stacks->stack_presort[i])
		{
			push_b(stacks);
			i++;
		}
		else
			rotate_a(stacks);
	}

	while (stacks->stack_b_len > 0)
		push_a(stacks);

	// ft_putstr("\nEND OF OPERATIONS\n");

	// for (int i = stacks->stack_a_len; i > 0; i--)
	// 	printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	// ft_putstr("\n");
	// for (int i = stacks->stack_b_len; i > 0; i--)
	// 	printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);

	// ft_putstr("\n");
	// for (int i = stacks->stack_presort_len; i > 0; i--)
	// 	printf("%d. stack_presort: %d\n", i - 1, stacks->stack_presort[i - 1]);

	// reverse_rotate_a(stacks);
	// rotate_a(stacks);
	// push_b(stacks);
	// push_b(stacks);
	// swap_a(stacks);
	// swap_b(stacks);
}
