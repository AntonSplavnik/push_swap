/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorter_first_try.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:23:46 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/14 16:24:19 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	sorter(t_stacks stacks)
{
		int	i;
	i = 0;
	while (i < stacks->stack_presort_len)
	{
		if (stacks->stack_a[stacks->stack_a_len - 1] == stacks->stack_presort[i])
		{
			push_b(stacks);
			i++;
		}
		else
			rotate_a(stacks);
	}
	while (stacks->stack_b_len > 0)
		push_a(stacks);
}
