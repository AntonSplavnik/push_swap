/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/22 20:35:09 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	atoi_errors(char *input_str)
{
	int	i;

	i = 0;
	if (input_str[i] == '-')
		i++;
	while (input_str[i])
	{
		if (input_str[i] == ' ')
		{
			ft_putstr("Input numeric values without spases\n");
			return (1);
		}
		else if (input_str[i] < '0' || input_str[i] > '9')
		{
			ft_putstr("Non numeric value found\n");
			return (1);
		}
		i++;
	}
	if (input_str[0] == '-' && i == 1)
	{
		ft_putstr("Invalid number format\n");
		return (1);
	}
	return (0);
}

int	ft_atoi(char *input_str)
{
	int		i;
	int		sign;
	long	result;
	int		checker_flag;

	i = 0;
	sign = 1;
	result = 0;
	checker_flag = atoi_errors(input_str);
	if (checker_flag != 0)
		return (1);
	if (input_str[i] == '-' && i == 0)
	{
		sign *= -1;
		i++;
	}
	while (input_str[i])
	{
		result = result * 10 + (input_str[i] - '0');
		i++;
	}
	if (result > INT_MAX || (-result) < INT_MIN)
	{
		ft_putstr("One of the numbers is over the INT limits\n");
		return (1);
	}
	return ((int)(result * sign));
}

int	duplicate_check(int *input, int size)
{
	int	i;
	int	j;
	int	buffer;

	j = 0;
	buffer = input[0];
	while (input[j] <= size)
	{
		buffer = input[j];
		i = j + 1;
		while (input[i] <= size)
		{
			if (input[i] == buffer)
				ft_putstr("Duplicate found!");
			i++;
		}
		j++;
	}
	return (0);
}

int	input_to_array(int argc, char **str)
{
	int	i;
	int	buffer;
	int	*unsorted_numbers;

	i = 1;
	unsorted_numbers = malloc(argc * sizeof(int));
	if (unsorted_numbers == NULL)
	{
		ft_putstr("Memory allocation error\n");
		return (1);
	}

	ft_putstr("\n");
	ft_putstr("Unsorted numbers:\n");
	while (i <= argc)
	{
		buffer = ft_atoi(str[i]);
		printf("\t\t\t%d\n", buffer);
		i++;
	}

	ft_putstr("\n");
	ft_putstr("Unsorted numbers in an array:\n");
	i = 1;
	while (i <= argc)
	{
		buffer = ft_atoi(str[i]);
		unsorted_numbers[i - 1] = buffer;
		printf("\t\t\t%d\n", unsorted_numbers [i - 1]);
		i++;
	}

	duplicate_check(unsorted_numbers, argc);

	free(unsorted_numbers);

	return (0);
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
