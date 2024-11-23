/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:43:04 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/22 15:47:19 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	calc_largest(int *stack, int len)
{
	int	buffer;

	buffer = stack[len - 1];
	if (buffer < stack[len - 2])
		buffer = stack[len - 2];
	else if (buffer < stack[len - 3])
		buffer = stack[len - 3];
	return (buffer);
}

void	sort_3(int *stack, int len)
{
	int	largest_num;

	if (len != 3)
		return ;

	largest_num = calc_largest(stack, len);
	if (stack[len - 1] == largest_num)
		rotate(stack, len);

	else if (stack[len - 2] == largest_num)
		reverse_rotate(stack, len);

	if (stack[len - 1] > stack[len - 2])
		swap(stack, len);
}
