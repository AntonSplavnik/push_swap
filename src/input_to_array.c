/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:03:59 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/04 15:40:19 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_to_array(char **argv)
{
	t_int_array	int_array;

	// check for empty arguments
	empty_argument_checker(argv);
	//int array memory allocation
	int_array.unsorted_numbers_num = number_counter(argv);
	printf("Number of elements in the input array: %d\n\n", int_array.unsorted_numbers_num);
	int_array.unsorted_numbers = ft_calloc(int_array.unsorted_numbers_num \
		, sizeof(int));
	if (int_array.unsorted_numbers == NULL)
	{
		free (int_array.unsorted_numbers);
		exit (1);
	}
	//Input restriction check and array fillig
	fill_array (argv, int_array);
	for (int i = 0; i < int_array.unsorted_numbers_num; i++)
		printf("%d. Nuber in array: %d\n", i, int_array.unsorted_numbers[i]);
	//Duplicate check
	if (duplicate_check(int_array.unsorted_numbers \
		, int_array.unsorted_numbers_num) == 1)
	{
		free (int_array.unsorted_numbers);
		exit (1);
	}
	free (int_array.unsorted_numbers);
}
