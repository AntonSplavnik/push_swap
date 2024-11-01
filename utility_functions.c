/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 18:48:59 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/01 23:13:38 by asplavni         ###   ########.fr       */
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

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}