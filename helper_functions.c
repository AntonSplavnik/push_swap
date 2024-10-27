/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:48:59 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/27 19:28:00 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_memset(void *str, int c, size_t number)
{
	size_t	i;

	i = 0;
	while (i < number)
	{
		((char *)str)[i] = (char)c;
		i++;
	}
}

void	ft_bzero(void *str, size_t number)
{
	size_t	i;

	i = 0;
	while (i < number)
	{
		((char *)str)[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t num, size_t size)
{
	void	*new_allocation;

	new_allocation = malloc(num * size);
	if (new_allocation == NULL)
		return (NULL);
	ft_bzero(new_allocation, num * size);
	return (new_allocation);
}

int	*ft_realloc(int *input_array, int new_length, int old_length)
{
	int	i;
	int	*realocatd_array;

	i = 0;
	realocatd_array = ft_calloc(new_length, sizeof(int));
	if (realocatd_array == NULL)
	{
		ft_putstr("Memory allocation error");
		return (NULL);
	}
	while (i < old_length)
	{
		realocatd_array[i] = input_array[i];
		i++;
	}
	free(input_array);
	return (realocatd_array);
}

int	ft_atoi(char *input_str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
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
	return ((int)(result * sign));
}
int	element_counter(char **str)
{
	int	i;
	int	j;
	int	counter;

	i = 1;
	counter = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{

			while (str[i][j] == ' ')
				j++;
			if (str[i][j] == '-')
			{
				if (str[i][j + 1] < '0' || str[i][j + 1] > '9')
				{
					ft_putstr("Error: '-' not followed by a digit\n");
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

char **ft_split(char *input, char c)
{

}
