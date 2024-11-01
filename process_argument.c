/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_argument.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 17:12:32 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/01 17:14:36 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**process_argument(char *argv)
{
	int		i;
	char	**splited_numbers;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ')
		{
			splited_numbers = split(argv[i], ' ');
			return (splited_numbers);
		}
		i++;
	}
	splited_numbers = ft_calloc(2, sizeof(char *));
	if (splited_numbers == NULL)
		return (NULL);
	splited_numbers[0] = argv;
	splited_numbers[1] = NULL;
	return (splited_numbers);
}
