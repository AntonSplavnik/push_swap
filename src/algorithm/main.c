/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/27 21:56:19 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "algorithm.h"

void	execution(char **argv, t_stacks *stacks)
{
	init(argv, stacks);
	if (sort_check(stacks->stack_a, stacks->stack_a_len) == 0)
	{
		free_stacks(stacks);
		exit (0);
	}
	algorythm(stacks);
	sort_compare(stacks);
	free_stacks(stacks);
	exit (0);
	// if (sort_check(stacks->stack_a, stacks->stack_a_len) == 0)
	// {
	// 	free_stacks(stacks);
	// 	exit (0);
	// }
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		ft_putstr("Error: Wrong number of arguments.\n"
			"Should be more then two arguments.\n");
	else
		execution(argv, &stacks);
	ft_putstr("\n");
	return (0);
}
