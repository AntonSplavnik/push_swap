/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:48:59 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/24 19:48:23 by asplavni         ###   ########.fr       */
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

int	count_ints_in_an_array(int *numbers)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (numbers[i + 1])
	{

	}
}

int	*ft_realloc(int *input_array, int new_leangth)
{
	int	i;
	int	*realocatd_array;

	i = 0;
	realocatd_array = ft_calloc(new_leangth, sizeof(int));
	if (realocatd_array == NULL)
	{
		ft_putstr("Memory allocation error");
		return (NULL);
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
	if (result > INT_MAX || (-result) < INT_MIN)
	{
		ft_putstr("One of the numbers is over the INT limits\n");
		return (1);
	}
	return ((int)(result * sign));
}
