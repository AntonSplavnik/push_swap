/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:13:53 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/03 16:31:46 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clenup_on_error(char **processed_argument, t_int_array int_array, int j)
{
	while (j >= 0)
	{
		free(processed_argument[j]);
		j--;
	}
	free(processed_argument);
	free (int_array.unsorted_numbers);
	exit (1);
}

int	process_and_validate_argument(t_int_array int_array,
		char *processed_argument, int k)
{
	if (input_restrictions(processed_argument) == 1
		|| limits(ft_atoi(processed_argument)) == 1)
		return (1);
	int_array.unsorted_numbers[k] = ft_atoi(processed_argument);
	printf("%d. Inserted number: %d\n", k, int_array.unsorted_numbers[k]);
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
	int		k;
	char	**processed_argument;

	i = 1;
	k = 0;
	while (argv[i])
	{
		processed_argument = process_argument(argv[i]);
		if (processed_argument == NULL)
			exit (1);
		j = 0;
		while (processed_argument[j])
		{
			if (process_and_validate_argument(int_array, \
				processed_argument[j], k) == 1)
				clenup_on_error(processed_argument, int_array, j);
			j++;
			k++;
		}
		free_processed_argument(processed_argument);
		i++;
	}
}
