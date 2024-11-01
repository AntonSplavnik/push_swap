/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/01 17:30:41 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_to_array(int argc, char **argv)
{
	int			i;
	t_int_array	int_array;

	//int array memory allocation
	int_array.unsorted_numbers_num = number_counter(argv);
	int_array.unsorted_numbers = ft_calloc (number_counter(argv), sizeof(int));
	if (int_array.unsorted_numbers == NULL)
		return (NULL);

	//Input restriction check and array fillig
	fill_array (argv, int_array);
	if (fill_array(argv, int_array) == NULL)
	{
		free (int_array.unsorted_numbers);
		exit (1);
	}

	//Duplicate check
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
