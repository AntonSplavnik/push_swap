/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/29 04:36:11 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "algorithm.h"

void	execution(t_stacks *stacks, char **argv)
{
	init(stacks, argv);
	quicksort(stacks->stack_presort, 0, stacks->stack_presort_len - 1);
	if (sort_check(stacks->stack_a, stacks->stack_a_len) == 0)
	{
		free_stacks(stacks);
		exit (0);
	}
	algorithm(stacks);
	sort_compare(stacks);
	free_stacks(stacks);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		return (0);
	else
		execution(&stacks, argv);
	return (0);
}
