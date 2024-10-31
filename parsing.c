/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:57:36 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/31 20:43:29 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	number_counter(char **argv)
{
	int		i;
	int		j;
	int		count;
	char	**splited_arg;

	i = 0;
	j = 0;
	count = 0;
	while (argv[i])
	{
		splited_arg = ft_split(argv[i], ' ');
		j++;
		while (splited_arg[j])
		{
			count++;
			free(splited_arg[j]);
			j++;
		}
		i++;
		free (splited_arg);
	}
	return (count);
}

int	input_restrictions(char *input_str)
{
	int	i;

	i = 0;
	if (input_str[i] == '-')
		i++;
	while (input_str[i])
	{
		if (input_str[i] == ' ')
		{
			ft_putstr("Error: Input numeric values without spaces\n");
			return (1);
		}
		else if (input_str[i] < '0' || input_str[i] > '9')
		{
			ft_putstr("Error: Non numeric value found\n");
			return (1);
		}
		else if (input_str[i] == '0' && \
			(input_str[i + 1] >= '0' && input_str[i + 1] <= '9'))
		{
			ft_putstr ("Error: 0 before a bumber");
			return (1);
		}
		i++;
	}
	if (input_str[0] == '-' && i == 1)
	{
		ft_putstr("Error:Invalid number format\n");
		return (1);
	}
	return (0);
}

int	limits(int number)
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
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
