/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:57:36 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/24 19:08:04 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
