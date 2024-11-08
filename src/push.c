/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:56:21 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/08 20:45:21 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void	push_a(t_stacks *stacks)
// {
// 	reverse_rotate_b(stacks);
// 	stacks->stack_b[0] = stacks->stack_a[0];
// 	stacks->stack_a[0] = stacks->stack_a[stacks->stack_b_count];
// 	rotate_a(stacks);
// 	for (int i = 0; i < stacks->stack_a_count; i++)
// 		printf("%d. stack_A after: %d\n", i, stacks->stack_a[i]);
// 	ft_putstr("\n");
// 	for (int i = 0; i < stacks->stack_b_count; i++)
// 		printf("%d. stack_B after: %d\n", i, stacks->stack_b[i]);
// }

// void	push_b(t_stacks *stacks)
// {
// 	reverse_rotate_b(stacks);
// 	stacks->stack_a[0] = stacks->stack_b[0];
// 	stacks->stack_b[0] = stacks->stack_b[stacks->stack_a_count];
// 	rotate_a(stacks);
// 	for (int i = 0; i < stacks->stack_a_count; i++)
// 		printf("%d. stack_A after: %d\n", i, stacks->stack_a[i]);
// 	ft_putstr("\n");
// 	for (int i = 0; i < stacks->stack_b_count; i++)
// 		printf("%d. stack_B after: %d\n", i, stacks->stack_b[i]);
// }

void	push_a(t_stacks *stacks)
{
// Nothing to push if stack_b is empty
	if (stacks->stack_b_count == 0)
		return ;
// Shift stack_a up to make space for the new element at the top
	int	i;
	i = stacks->stack_a_count;
	while (i > 0)
	{
		stacks->stack_a[i] = stacks->stack_a[i - 1];
		i--;
	}
// Move the top element of stack_b to stack_a
	stacks->stack_a[0] = stacks->stack_b[0];
	stacks->stack_a_count++;
// Shift stack_b down to remove the element from the top
	int	j;
	j = 0;
	while (j < stacks->stack_b_count - 1)
	{
		stacks->stack_b[j] = stacks->stack_b[j + 1];
		j++;
	}
	stacks->stack_b_count--;

	printf("Stack A after push_a:\n");
	for (int i = 0; i < stacks->stack_a_count; i++)
		printf("%d. %d\n", i, stacks->stack_a[i]);

	printf("\nStack B after push_a:\n");
	for (int i = 0; i < stacks->stack_b_count; i++)
			printf("%d. %d\n", i, stacks->stack_b[i]);
	ft_putstr("pa\n");
}

void	push_b(t_stacks *stacks)
{
// Nothing to push if stack_a is empty
	if (stacks->stack_a_count == 0)
		return ;
// Shift stack_b up to make space for the new element at the top
	int	i;

	i = stacks->stack_b_count;
	while (i > 0)
	{
		stacks->stack_b[i] = stacks->stack_b[i - 1];
		i--;
	}
// Move the top element of stack_a to stack_b
	stacks->stack_b[0] = stacks->stack_a[0];
	stacks->stack_b_count++;
// Shift stack_a down to remove the element from the top
	int	j;
	j = 0;
	while (j < stacks->stack_a_count - 1)
	{
		stacks->stack_a[j] = stacks->stack_a[j + 1];
		j++;
	}
	stacks->stack_a_count--;

	printf("Stack A after push_b:\n");
	for (int i = 0; i < stacks->stack_a_count; i++)
		printf("%d. %d\n", i, stacks->stack_a[i]);

	printf("\nStack B after push_b:\n");
	for (int i = 0; i < stacks->stack_b_count; i++)
		printf("%d. %d\n", i, stacks->stack_b[i]);
	ft_putstr("pb\n");
}
