/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/11 21:57:32 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execution(char **argv, t_stacks *stacks)
{
	init(argv, stacks);
	if (sort_check(stacks) == 0)
	{
		free (stacks->stack_a);
		free (stacks->stack_b);
		exit (0);
	}
	algorythm(stacks);
	if (sort_check(stacks) == 0)
	{
		free (stacks->stack_a);
		free (stacks->stack_b);
		exit (0);
	}
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
