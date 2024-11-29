/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:13:53 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 20:42:40 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

void	clenup_on_error(t_stacks *stacks, char **processed_argument)
{
	int	j;

	j = 0;
	while (processed_argument[j])
	{
		free(processed_argument[j]);
		j++;
	}
	free(processed_argument);
	free (stacks->stack_a);
	exit (1);
}

void	free_processed_argument(char **processed_argument)
{
	int	i;

	i = 0;
	while (processed_argument[i])
	{
		free (processed_argument[i]);
		i++;
	}
	free (processed_argument);
}

int	process_and_validate_argument(t_stacks *stacks,
		char *processed_argument, int k)
{
	if (input_restrictions(processed_argument) == 1
		|| limits(ft_atoi(processed_argument)) == 1)
		return (1);
	stacks->stack_a[k] = ft_atoi(processed_argument);
	return (0);
}

void	fill_array(t_stacks *stacks, char **argv)
{
	int		i;
	int		j;
	int		k;
	char	**processed_argument;

	i = 1;
	k = stacks->len - 1;
	while (argv[i])
	{
		processed_argument = ft_split(argv[i], ' ');
		if (processed_argument == NULL)
			exit (1);
		j = 0;
		while (processed_argument[j])
		{
			if (process_and_validate_argument(stacks, \
				processed_argument[j], k) == 1)
				clenup_on_error(stacks, processed_argument);
			j++;
			k--;
		}
		free_processed_argument(processed_argument);
		i++;
	}
}
