/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:03:59 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/12 18:17:39 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_a_initialisation(t_stacks *stacks, char **argv)
{
	stacks->len = number_counter(argv);
	stacks->stack_a_len = stacks->len;

	printf("Number of elements in the input: %d\n\n", stacks->stack_a_len);

	stacks->stack_a = ft_calloc(stacks->stack_a_len \
		, sizeof(int));
	if (stacks->stack_a == NULL)
		exit (1);

	fill_array (argv, stacks);

	ft_putstr("stack_a init\n");
	for (int i = stacks->stack_a_len; i > 0; i--)
		printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	// if (duplicate_check(int_arrays->stack_a \
	// 	, int_arrays->stack_a_count) == 1)
	// {
	// 	free (int_arrays->stack_a);
	// 	exit (1);
	// }
}

void	stack_b_initialisation(t_stacks	*stacks)
{
	stacks->stack_b = malloc (stacks->len * sizeof(int));
	if (stacks->stack_b == NULL)
	{
		free (stacks->stack_a);
		exit (1);
	}

	stacks->stack_b_len = 0;

	ft_putstr("stack_b init\n");
	for (int i = stacks->stack_b_len; i > 0; i--)
		printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);
}
void	stack_presorted_init(t_stacks *stacks)
{
	int	i;

	stacks->stack_presort = malloc(stacks->len * sizeof(int));
	if (stacks->stack_presort == NULL)
	{
		free (stacks->stack_a);
		free (stacks->stack_b);
		exit (1);
	}

	stacks->stack_presort_len = stacks->len;

	i = 0;
	while (i < stacks->stack_presort_len)
	{
		stacks->stack_presort[i] = stacks->stack_a[i];
		i++;
	}

	ft_putstr("stack_presort init\n");
	for (int i = stacks->stack_presort_len; i > 0; i--)
		printf("%d. stack_presort: %d\n", i - 1, stacks->stack_presort[i - 1]);

}

void	init(char **argv, t_stacks *stacks)
{
	empty_argument_checker(argv);
	stack_a_initialisation(stacks, argv);
	ft_putstr("\n");
	stack_b_initialisation(stacks);
	ft_putstr("\n");
	stack_presorted_init(stacks);
	ft_putstr("\n");
}
