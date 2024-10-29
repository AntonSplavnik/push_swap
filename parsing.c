/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:57:36 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/29 16:14:52 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	element_counter(char **str)
{
	int	i;
	int	j;
	int	counter;

	i = 1;
	counter = 0;
	while (str[i])
	{
		while (str[i][0] == '\0')
			i++;

		j = 0;
		while (str[i][j])
		{
			while (str[i][j] == ' ')
				j++;
			if (str[i][j] == '-')
			{
				if ((str[i][j + 1] < '0' || str[i][j + 1] > '9') ||
				(j > 0 && str[i][j] != ' '))
				{
					ft_putstr("Error: Invalid '-' placement" \
						"or '-' not followed by a digit\n");
					exit (1);
				}
				j++;
			}
			if (str[i][j] >= '0' && str[i][j] <= '9')
			{
				while (str[i][j] >= '0' && str[i][j] <= '9')
					j++;
				counter++;
			}
			else if (str[i][j] != ' ' && str[i][j] != '\0')
			{
				ft_putstr("Error: found non-numeric value\n");
				exit (1);
			}
		}
		i++;
	}
	return (counter);
}

int	string_restrictions(char *input_str)
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
