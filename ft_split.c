/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 20:38:38 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/30 20:55:53 by asplavni         ###   ########.fr       */
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
		if (input[i] && input[i] != c)
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

char	**ft_split_fill_arrays(int token_counter,
			char *input, char **return_str, char c)
{
	int		start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (input[i])
	{
		while (input[i] == c)
			i++;
		start = i;
		while (input[i] && input[i] != c)
			i++;
		return_str[j] = ft_calloc((i - start + 1), sizeof(char));
		if (return_str[j] == NULL)
		{
			ft_split_free_alloc(return_str, j - 1);
			return (NULL);
		}
		ft_strncpy(return_str[j], &input[start], i - start);
		j++;
	}
	return_str[j] = NULL;
}

char	**ft_split(char *input, char c)
{
	char	**return_str;
	int		token_counter;

	token_counter = ft_split_token_counter(input, c);
	return_str = ft_calloc((token_counter + 1), sizeof(char *));

	if (return_str == NULL)
		return (NULL);
	if (ft_split_fill_arrays(token_counter, input, return_str, c) == NULL)
	{
		free(return_str);
		return (NULL);
	}
	return (return_str);
}
