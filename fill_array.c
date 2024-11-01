/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:13:53 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/01 17:37:36 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clenup_on_error(int j, char *processed_argument)
{
	while (j > 0)
	{
		free(processed_argument[j - 1]);
		j--;
	}
	free(processed_argument);
	exit (1);
}

int	process_and_validate_argument(t_int_array int_array,
		char *processed_argument, int j)
{

	if (input_restrictions(processed_argument) == 1
		|| limits(ft_atoi(processed_argument)) == 1)
		return (1);

	int_array.unsorted_numbers[j] = atoi(processed_argument[j]);
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

void	fill_array(char **argv, t_int_array int_array)
{
	int		i;
	int		j;
	char	**processed_argument;

	i = 0;
	while (argv[i])
	{
		processed_argument = process_argument(argv[i]);
		if (processed_argument == NULL)
			exit (1);
		j = 0;
		while (processed_argument[j])
		{
			if (process_and_validate_argument(int_array, \
				processed_argument[j], j) == 1)
				clenup_on_error(j, processed_argument[j]);
			j++;
		}
		free_processed_argument(processed_argument);
		i++;
	}
}
