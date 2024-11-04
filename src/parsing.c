/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:57:36 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/04 15:31:12 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	empty_argument_checker(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (argv[i][0] == '\0')
		{
			printf("Error: found empty argument\n");
			exit (1);
		}
		i++;
	}
}

int	input_restrictions_helper(char *input_str, int i)
{
	if (input_str[i] == ' ')
	{
		ft_putstr("Error: Input numeric values without spaces\n");
		return (1);
	}
	else if (input_str[i] < '0' || input_str[i] > '9')
	{
		printf("ERROR --> %c\n", input_str[i]);
		ft_putstr("Error: Non numeric value found\n");
		return (1);
	}
	return (0);
}

int	input_restrictions(char *input_str)
{
	int	i;

	i = 0;
	if (input_str[i] == '-')
		i++;
	if (input_str[i] == '0' && \
		(input_str[i + 1] >= '0' && input_str[i + 1] <= '9'))
	{
		ft_putstr ("Error: 0 before a number");
		return (1);
	}
	while (input_str[i])
	{
		if (input_restrictions_helper(input_str, i) == 1)
			return (1);
		i++;
	}
	if (input_str[0] == '-' && i == 1)
	{
		ft_putstr("Error: Invalid number format\n");
		return (1);
	}
	return (0);
}

int	limits(long number)
{
	if (number > INT_MAX || number < INT_MIN)
	{
		ft_putstr("Error: One of the numbers is over the INT limits\n");
		return (1);
	}
	return (0);
}

int	duplicate_check(int *input, int size)
{
	int	i;
	int	j;
	int	buffer;

	j = 0;
	buffer = input[0];
	while (j < size)
	{
		buffer = input[j];
		i = j + 1;
		while (i < size)
		{
			if (input[i] == buffer)
			{
				printf("Error: Duplicate found! ->%d\n", input[i]);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
