/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antonsplavnik <antonsplavnik@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/10 19:43:43 by antonsplavn      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execution(char **argv, t_stacks *stacks)
{
	init(argv, stacks);
	sort_check(stacks);
	// algorythm(stacks);
	free (stacks->stack_a);
	free (stacks->stack_b);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
	{
		ft_putstr("Error: Wrong number of arguments.\n"
			"Should be more then two arguments.\n");
	}
	else
	{
		execution(argv, &stacks);
	}
	ft_putstr("\n");
	return (0);
}
