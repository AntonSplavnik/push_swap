/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/31 22:05:52 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**process_argument(char *argv)
{
	int		i;
	char	**splited_numbers;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
		{
			splited_numbers = split(argv[i], ' ');
			return (splited_numbers);
		}
		i++;
	}
	splited_numbers = ft_calloc(2, sizeof(char *));
	if (splited_numbers == NULL)
		return (NULL);
	splited_numbers[0] = argv;
	splited_numbers[1] = NULL;
	return (splited_numbers);
}

void	fill_array(char **argv, t_int_array int_array)
{
	int	i;

	i = 1;

}

void	input_to_array(int argc, char **argv)
{
	int			i;
	int			j;
	char		**processed_argument;
	t_int_array	int_array;

	i = 0;

	//int array allocation
	int_array.unsorted_numbers_num = number_counter(argv);
	int_array.unsorted_numbers = ft_calloc (number_counter(argv), sizeof(int));
	if (int_array.unsorted_numbers == NULL)
		return (NULL);

	//Input restriction check and array fillig
	while (argv[i])
	{
		processed_argument = process_argument(argv[i]);
		if (processed_argument == NULL)
			exit (1);

		j = 0;
		while (processed_argument[j])
		{
			if (input_restrictions(processed_argument[j]) == 1
				|| limits(ft_atoi(processed_argument[i]) == 1))
			{
				while (j > 0)
				{
					free(processed_argument[j - 1]);
					j--;
				}
				free(processed_argument);
				exit (1);
			}
			j++;
		}
		free(processed_argument);
		i++;
	}

	if (duplicate_check(int_array.unsorted_numbers, int_array.unsorted_numbers_num) == 1)
	{
		free (int_array.unsorted_numbers);
		exit (1);
	}

}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("Error: Wrong number of arguments.\n"
			"Should be more then two arguments.\n");
	}
	else
		input_to_array(argc - 1, argv);
	ft_putstr("\n");
	return (0);
}
