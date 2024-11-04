/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:12:32 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/04 15:13:48 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// char	**process_argument(char *argv)
// {
// 	int		i;
// 	char	**splited_numbers;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		if (argv[i] == ' ')
// 		{
// 			splited_numbers = ft_split(argv, ' ');
// 			return (splited_numbers);
// 		}
// 		i++;
// 	}
// 	splited_numbers = ft_calloc(2, sizeof(char *));
// 	if (splited_numbers == NULL)
// 		return (NULL);
// 	splited_numbers[0] = ft_calloc(ft_strlen((const char *)argv), sizeof(char *));
// 	splited_numbers[0] = ft_strncpy(splited_numbers[0],
// 			(const char *)argv, (size_t)ft_strlen((const char *)argv));
// 	splited_numbers[1] = NULL;
// 	return (splited_numbers);
// }

char	**process_argument(char *argv)
{
	return (ft_split(argv, ' '));
}


size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
