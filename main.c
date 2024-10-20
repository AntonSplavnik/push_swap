/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/20 21:57:54 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

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
	int	output;

	i = 0;
	output = 0;

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

int	atoi(char *input_str)
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

int	more_then_one_argument_output(char **str)
{
	int	i;
	int	buffer;

	i = 1;
	printf("Unsorted numbers:\n");
	while (str[i])
	{
		buffer = atoi(str[i]);
		printf("\t\t%d\n", buffer);
		i++;
	}
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
		more_then_one_argument_output(argv);
	ft_putstr("\n");
	return (0);
}
