/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 18:00:32 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 20:01:45 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	number_counter(char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**splited_arg;

	i = 1;
	j = 0;
	count = 0;
	while (argv[i])
	{
		j = 0;
		splited_arg = ft_split(argv[i], ' ');
		if (splited_arg == NULL)
			return (0);
		while (splited_arg[j])
		{
			count++;
			free(splited_arg[j]);
			j++;
		}
		i++;
		free (splited_arg);
	}
	return (count);
}

void	free_stacks(t_stacks *stacks)
{
	free (stacks->stack_a);
	free (stacks->stack_b);
	free (stacks->stack_presort);
}
