/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/23 20:52:45 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

#define INT_MAX 2147483647
#define INT_MIN -2147483648

int	*ft_realloc(int *input_array, int new_leangth)
{
	int	*realocatd_array;

	realocatd_array = malloc(new_leangth * 4);
	if (realocatd_array == NULL)
		ft_putstr("Memory allocation error");
	new_leangth = *input_array;
	free(input_array);
}

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

int	string_restrictions_checker(char *input_str)
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
			return (-999999);
		}
		else if (input_str[i] < '0' || input_str[i] > '9')
		{
			ft_putstr("Non numeric value found\n");
			return (-999999);
		}
		i++;
	}
	if (input_str[0] == '-' && i == 1)
	{
		ft_putstr("Invalid number format\n");
		return (-999999);
	}
	return (0);
}

int	ft_atoi(char *input_str)
{
	int		i;
	int		sign;
	long	result;
	int		flag_checker;

	i = 0;
	sign = 1;
	result = 0;
	flag_checker = string_restrictions_checker(input_str);
	if (flag_checker != 0)
		return (-999999);
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
	while (j <= size)
	{
		buffer = input[j];
		i = j + 1;
		while (i <= size)
		{
			if (input[i] == buffer)
			{
				ft_putstr("Error duplicate found!");
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

void	input_to_array(int argc, char **str)
{
	int	i;
	int	buffer;
	int	*unsorted_numbers;

	i = 1;
	unsorted_numbers = malloc(argc * sizeof(int));
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
