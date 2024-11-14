/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:20:14 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/14 16:20:31 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	calc_largest(t_stacks *stacks)
{
	int	buffer;

	buffer = stacks->stack_a[stacks->stack_a_len - 1];
	if (buffer < stacks->stack_a[stacks->stack_a_len - 2])
		buffer = stacks->stack_a[stacks->stack_a_len - 2];
	else if (buffer < stacks->stack_a[stacks->stack_a_len - 3])
		buffer = stacks->stack_a[stacks->stack_a_len - 3];

	return (buffer);
}

void	sort_3(t_stacks *stacks)
{
	int	largest_num;

	largest_num = calc_largest(stacks);
	if (stacks->stack_a[stacks->stack_a_len - 1] == largest_num)
		rotate_a(stacks);
	else if (stacks->stack_a[stacks->stack_a_len - 2] == largest_num)
		reverse_rotate_a(stacks);
	if (stacks->stack_a[stacks->stack_a_len - 1] > \
	stacks->stack_a[stacks->stack_a_len - 2])
		swap_a(stacks);
}