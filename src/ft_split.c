/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/03 14:53:23 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/03 15:41:06 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_split_token_counter(char *input, char c)
{
	int		token_counter;
	int		i;

	i = 0;
	token_counter = 0;
	while (input[i])
	{
		while (input[i] == c)
			i++;
		if (input[i])
		{
			token_counter++;
			while (input[i] && input[i] != c)
				i++;
		}
	}
	return (token_counter);
}

void	ft_split_free_alloc(char **return_str, int j)
{
	while (j >= 0)
	{
		free(return_str[j]);
		j--;
	}
}

char	*ft_split_calloc_call(char **return_str, int i, int j, int start)
{
	return_str[j] = ft_calloc((i - start + 1), sizeof(char));
	if (return_str[j] == NULL)
	{
		ft_split_free_alloc(return_str, j - 1);
		return (NULL);
	}
	return (return_str[j]);
}

char	**ft_split_fill_arrays(char *input, char **return_str, char c)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (input[i])
	{
		while (input[i] == c)
			i++;
		start = i;
		while (input[i] && input[i] != c)
			i++;
		if (i > start)
		{
			if (ft_split_calloc_call(return_str, i, j, start) == NULL)
				return (NULL);
			ft_strncpy(return_str[j], &input[start], i - start);
			j++;
		}
	}
	return_str[j] = NULL;
	return (return_str);
}

char	**ft_split(char *input, char c)
{
	char	**return_str;
	int		token_counter;

	token_counter = ft_split_token_counter(input, c);
	return_str = ft_calloc((token_counter + 1), sizeof(char *));
	if (return_str == NULL)
		return (NULL);
	if (ft_split_fill_arrays(input, return_str, c) == NULL)
	{
		free(return_str);
		return (NULL);
	}
	return (return_str);
}
