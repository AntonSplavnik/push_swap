/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 19:40:20 by antonsplavn       #+#    #+#             */
/*   Updated: 2024/11/27 00:00:29 by asplavni         ###   ########.fr       */
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
	int	cheapest_index;

	quicksort(stacks->stack_presort, 0, stacks->stack_presort_len - 1);
	// sort(stacks);

	if (stacks->stack_a_len == 2)
	{
		if (stacks->stack_a[1] > stacks->stack_a[0])
		swap_a(stacks);
		return ;
	}

	if (stacks->stack_a_len == 3)
	{
		sort_3(stacks->stack_a, stacks->stack_a_len);
		return ;
	}
	// else if (stacks->stack_a_len == 4)
	// {
	// }
	// else if (stacks->stack_a_len == 5)
	// {
	// 	sort_5(stacks);
	// 	return ;
	// }

	while (stacks->stack_a_len > 3)
	{
		push_average_to_b(stacks);
	}

	sort_3(stacks->stack_a, stacks->stack_a_len);


	while (stacks->stack_b_len > 0)
	{
		cheapest_index = find_cheapest_in_b(stacks);
		push_cheapest_to_a(stacks, cheapest_index);
	}

	int	min_index_a = min_index(stacks->stack_a, stacks->stack_a_len);
	if (min_index_a != stacks->stack_a_len - 1)
	{
		if (min_index_a >= stacks->stack_a_len / 2)
		{
			while (min_index_a != stacks->stack_a_len - 1)
			{
				rotate_a(stacks);
				min_index_a = (min_index_a + 1) % stacks->stack_a_len;
			}
		}
		else
		{
			while (min_index_a != stacks->stack_a_len - 1)
			{
				reverse_rotate_a(stacks);
				min_index_a = (min_index_a - 1 + stacks->stack_a_len) % stacks->stack_a_len;
			}
		}
	}


	// ft_putstr("\nEND OF OPERATIONS\n");

	// for (int i = stacks->stack_a_len; i > 0; i--)
	// 	printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	// ft_putstr("\n");

	// for (int i = stacks->stack_b_len; i > 0; i--)
	// 	printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);

	// ft_putstr("\n");
	// for (int i = stacks->stack_presort_len; i > 0; i--)
	// 	printf("%d. stack_presort: %d\n", i - 1, stacks->stack_presort[i - 1]);
}
