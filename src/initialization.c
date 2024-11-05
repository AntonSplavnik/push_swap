/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:03:59 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/05 21:54:30 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a_initialisation(t_stacks *int_arrays, char **argv)
{
	//stack_a memory allocation
	int_arrays->stack_a_count = number_counter(argv);
	printf("Number of elements in the input array: %d\n\n", int_arrays->stack_a_count);
	int_arrays->stack_a = ft_calloc(int_arrays->stack_a_count \
		, sizeof(int));
	if (int_arrays->stack_a == NULL)
		exit (1);
	//Input restriction check and stack_a fillig
	fill_array (argv, int_arrays);
	for (int i = 0; i < int_arrays->stack_a_count; i++)
		printf("%d. stack_A: %d\n", i, int_arrays->stack_a[i]);
	if (duplicate_check(int_arrays->stack_a \
		, int_arrays->stack_a_count) == 1)
	{
		free (int_arrays->stack_a);
		exit (1);
	}
}

void	stack_b_initialisation(t_stacks	*int_arrays)
{
	int_arrays->stack_b = calloc (int_arrays->stack_a_count, sizeof(int));
	if (int_arrays->stack_b == NULL)
	{
		free (int_arrays->stack_a);
		exit (1);
	}
	int_arrays->stack_b[0] = 1;
	int_arrays->stack_b[1] = 2;
	int_arrays->stack_b_count = int_arrays->stack_a_count;
	for (int j = 0; j < int_arrays->stack_b_count; j++)
		printf("%d. stack_B: %d\n", j, int_arrays->stack_b[j]);
}

void	algorythm(t_stacks *stacks)
{
	rotate_a(stacks);
	for (int i = 0; i < stacks->stack_a_count; i++)
		printf("%d. stack_A: %d\n", i, stacks->stack_a[i]);

	rotate_b(stacks);
	for (int k = 0; k < stacks->stack_b_count; k++)
		printf("%d. stack_B: %d\n", k, stacks->stack_b[k]);
}

void	initialization(char **argv)
{
	t_stacks	int_arrays;

	empty_argument_checker(argv);
	stack_a_initialisation(&int_arrays, argv);
	stack_b_initialisation(&int_arrays);
	algorythm(&int_arrays);

	free (int_arrays.stack_a);
	free (int_arrays.stack_b);
}

