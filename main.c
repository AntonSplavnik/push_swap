/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/03 20:54:34 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_to_array(char **argv)
{
	t_int_array	int_array;

	//int array memory allocation
	int_array.unsorted_numbers_num = number_counter(argv);
	printf("Number of elements in the input array: %d\n", int_array.unsorted_numbers_num);

	int_array.unsorted_numbers = ft_calloc (int_array.unsorted_numbers_num, sizeof(int));
	if (int_array.unsorted_numbers == NULL)
	{
		free (int_array.unsorted_numbers);
		exit (1);
	}

	//Input restriction check and array fillig
	fill_array (argv, int_array);
	// if (fill_array(argv, int_array) == NULL)
	// {
	// 	free (int_array.unsorted_numbers);
	// 	exit (1);
	// }
	for (int i = 0; i < int_array.unsorted_numbers_num; i++)
		printf("%d. Nuber in array: %d\n", i, int_array.unsorted_numbers[i]);

	//Duplicate check
	if (duplicate_check(int_array.unsorted_numbers, int_array.unsorted_numbers_num) == 1)
	{
		free (int_array.unsorted_numbers);
		exit (1);
	}

	free (int_array.unsorted_numbers);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("Error: Wrong number of arguments.\n"
			"Should be more then two arguments.\n");
	}
	else
		input_to_array(argv);
	ft_putstr("\n");
	// int i = 0;
	// char *str = " hello world";
	// char **output = ft_split(str, ' ');
	// while (output[i])
	// {
	// 	ft_putstr(output[i++]);
	// 	ft_putstr("\n");
	// }
	// ft_split_free_alloc(output, i -1);
	// free (output);
	return (0);
}
