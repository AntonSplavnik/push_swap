/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/29 16:55:16 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fillarray_with_numbers(int *unsorted_numbers, char *number)
{
	int	i;

	i = 0;
	while (i <= number)
	{
		unsorted_numbers[i - 1] = ft_atoi(number[i]);
		printf("\t\t\t%d\n", unsorted_numbers [i - 1]);
		i++;
	}
}

char	**process_argument(char **argv)
{
	//deside if split is needed, do split if needed.
	int		i;
	int		j;
	int		k;
	char	**splited_numbers;

	i = 0;
	j = 0;
	k = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (argv[i][j] == ' ')
			{
				splited_numbers = split(argv[i]);
				while (splited_numbers[k])
					validation(splited_numbers[k]);
				fillarray_with_numbers(splited_numbers);
			}
			else
			{
				validation(argv[i]);
				fillarray_with_numbers(argv[i]);
			}
			j++;
		}
		i++;
	}
}

void	input_to_array(int argc, char **str)
{
	int		i;
	int		n;
	int		elements_count;
	int		*unsorted_numbers;
	char	**arrs;

	i = 1;
	elements_count = element_counter(str);

	process_argument(**str);

	// validation of a singular number: spaces, number, limits)
	while (i <= argc)
	{
		if (string_restrictions(str[i]) == 1)
			exit (1);
		else if (limits(ft_atoi(str[i])) == 1)
			exit (1);
		i++;
	}

	//allocation of int array
	i = 1;
	unsorted_numbers = ft_calloc(argc, sizeof(int));
	if (unsorted_numbers == NULL)
	{
		ft_putstr("Error: Memory allocation\n");
		exit (1);
	}

	//filling int array with singular number
	ft_putstr("\nUnsorted numbers:\n");
	while (i <= argc)
	{
		unsorted_numbers[i - 1] = ft_atoi(str[i]);
		printf("\t\t\t%d\n", unsorted_numbers [i - 1]);
		i++;
	}

	//duplicate check in an array
	if (duplicate_check(unsorted_numbers, argc) == 1)
	{
		ft_putstr("Error: Duplicate found\n");
		free(unsorted_numbers);
		exit (1);
	}
	free(unsorted_numbers);
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
