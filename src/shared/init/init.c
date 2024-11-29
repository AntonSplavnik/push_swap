/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:03:59 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 20:43:10 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	stacks_init(t_stacks *stacks)
{
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->stack_presort = NULL;
	stacks->len = 0;
	stacks->stack_a_len = 0;
	stacks->stack_b_len = 0;
	stacks->stack_presort_len = 0;
}

void	stack_a_initialisation(t_stacks *stacks, char **argv)
{
	stacks->len = number_counter(argv);
	stacks->stack_a_len = stacks->len;
	stacks->stack_a = ft_calloc(stacks->stack_a_len \
		, sizeof(int));
	if (stacks->stack_a == NULL)
		exit (1);
	fill_array (stacks, argv);
	if (duplicate_check(stacks->stack_a \
		, stacks->stack_a_len) == 1)
	{
		free_stacks(stacks);
		exit (1);
	}
}

void	stack_b_initialisation(t_stacks	*stacks)
{
	stacks->stack_b = malloc (stacks->len * sizeof(int));
	if (stacks->stack_b == NULL)
	{
		free_stacks(stacks);
		exit (1);
	}
}

void	stack_presorted_init(t_stacks *stacks)
{
	int	i;

	stacks->stack_presort = malloc(stacks->len * sizeof(int));
	if (stacks->stack_presort == NULL)
	{
		free_stacks(stacks);
		exit (1);
	}
	stacks->stack_presort_len = stacks->len;
	i = 0;
	while (i < stacks->stack_presort_len)
	{
		stacks->stack_presort[i] = stacks->stack_a[i];
		i++;
	}
}

void	init(t_stacks *stacks, char **argv)
{
	empty_argument_checker(argv);
	stacks_init(stacks);
	stack_a_initialisation(stacks, argv);
	stack_b_initialisation(stacks);
	stack_presorted_init(stacks);
}
