/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:13:53 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/09 18:10:47 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clenup_on_error(char **processed_argument, t_stacks *int_array)
{
	int	j;

	j = 0;
	while (processed_argument[j])
	{
		free(processed_argument[j]);
		j++;
	}
	free(processed_argument);
	free (int_array->stack_a);
	exit (1);
}

int	process_and_validate_argument(t_stacks *int_array,
		char *processed_argument, int k)
{
	if (input_restrictions(processed_argument) == 1
		|| limits(ft_atoi(processed_argument)) == 1)
		return (1);
	int_array->stack_a[k] = ft_atoi(processed_argument);
	return (0);
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

void	fill_array(char **argv, t_stacks *int_array)
{
	int		i;
	int		j;
	int		k;
	char	**processed_argument;

	i = 1;
	k = int_array->len - 1;
	while (argv[i])
	{
		processed_argument = ft_split(argv[i], ' ');
		if (processed_argument == NULL)
			exit (1);
		j = 0;
		while (processed_argument[j])
		{
			if (process_and_validate_argument(int_array, \
				processed_argument[j], k) == 1)
				clenup_on_error(processed_argument, int_array);
			j++;
			k--;
		}
		free_processed_argument(processed_argument);
		i++;
	}
}
