/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/30 21:07:27 by asplavni         ###   ########.fr       */
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
	t_int_array	int_array;

	while (i < argc)
		if (check_restrictions(argv) == 1)
			exit (1);

	//int array allocation
	int_array.unsorted_numbers_num = arg_counter(argv);
	int_array.unsorted_numbers = ft_calloc (arg_counter(argv), sizeof(int));
	if (int_array.unsorted_numbers == NULL)
		return (NULL);

	fill_array(**argv, int_array);
}

void	input_to_array(int argc, char **argv)
{
	int		i;
	int		n;
	int		number_count_input_str;
	int		*unsorted_numbers;
	char	**arrs;

	i = 1;
	number_count_input_str = element_counter(argv);

	process_argument(**argv);

	// validation of a singular number: spaces, number, limits)
	while (i <= argc)
	{
		if (input_restrictions(argv[i]) == 1)
			exit (1);
		else if (limits(ft_atoi(argv[i])) == 1)
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
		unsorted_numbers[i - 1] = ft_atoi(argv[i]);
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
