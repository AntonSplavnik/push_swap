/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/24 20:38:31 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_to_array(int argc, char **str)
{
	int	i;
	int	*unsorted_numbers;
	int	flag_checker;

	i = 1;
	unsorted_numbers = ft_calloc(argc, sizeof(int));
	if (unsorted_numbers == NULL)
	{
		ft_putstr("Memory allocation error\n");
		exit (1);
	}
	ft_putstr("\nUnsorted numbers:\n");
	while (i <= argc)
	{
		flag_checker = string_restrictions_checker(str);
		if (flag_checker != 0)
		{
			free(unsorted_numbers);
			exit (1);
		}
		unsorted_numbers[i - 1] = ft_atoi(str[i]);
		printf("\t\t\t%d\n", unsorted_numbers [i - 1]);
		i++;
	}
	duplicate_check(unsorted_numbers, argc);
	free(unsorted_numbers);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("Wrong number of arguments.\n"
			"Should be more then two arguments.\n");
	}
	else
		input_to_array(argc - 1, argv);
	ft_putstr("\n");
	return (0);
}
