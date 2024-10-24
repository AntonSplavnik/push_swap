/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/24 18:59:30 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_to_array(int argc, char **str)
{
	int	i;
	int	buffer;
	int	*unsorted_numbers;

	i = 1;
	unsorted_numbers = ft_calloc(argc, sizeof(int));
	if (unsorted_numbers == NULL)
	{
		ft_putstr("Memory allocation error\n");
		exit (1);
	}
	ft_putstr("\n");
	ft_putstr("Unsorted numbers:\n");
	i = 1;
	while (i <= argc)
	{
		buffer = ft_atoi(str[i]);
		if (buffer == -999999)
		{
			free(unsorted_numbers);
			exit (1);
		}
		unsorted_numbers[i - 1] = buffer;
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
