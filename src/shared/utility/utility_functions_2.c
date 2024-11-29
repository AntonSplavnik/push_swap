/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 18:47:22 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 18:47:49 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"

int	ft_strcmp(char *input1, char *input2)
{
	int	i;

	i = 0;
	while (input1[i])
	{
		if (input1[i] != input2[i])
		{
			return (1);
		}
		i++;
	}
	if (input1[i] || input2[i])
		return (1);
	return (0);
}
