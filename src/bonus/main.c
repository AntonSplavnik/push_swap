/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:57:47 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/29 02:51:28 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "checker.h"
#include "get_next_line.h"

int	commands_call(t_stacks *stacks, char *command)
{
	if (ft_strcmp(command, "pa\n") == 0)
		push_a(stacks, 0);
	else if (ft_strcmp(command, "pb\n") == 0)
		push_b(stacks, 0);
	else if (ft_strcmp(command, "sa\n") == 0)
		swap_a(stacks, 0);
	else if (ft_strcmp(command, "sb\n") == 0)
		swap_b(stacks, 0);
	else if (ft_strcmp(command, "ss\n") == 0)
		swap_a_b(stacks, 0);
	else if (ft_strcmp(command, "ra\n") == 0)
		rotate_a(stacks, 0);
	else if (ft_strcmp(command, "rb\n") == 0)
		rotate_b(stacks, 0);
	else if (ft_strcmp(command, "rr\n") == 0)
		rotate_a_b(stacks, 0);
	else if (ft_strcmp(command, "rra\n") == 0)
		reverse_rotate_a(stacks, 0);
	else if (ft_strcmp(command, "rrb\n") == 0)
		reverse_rotate_b(stacks, 0);
	else if (ft_strcmp(command, "rrr\n") == 0)
		reverse_rotate_a_b(stacks, 0);
	else
		return (1);
	return (0);
}

char	*read_commands(t_stacks *stacks)
{
	char	*commands;

	commands = get_next_line(0);
	while (commands != NULL)
	{
		if (commands_call(stacks, commands) == 1)
		{
			ft_putstr("Error\n");
			free(commands);
			free_stacks(stacks);
			exit (1);
		}
		free(commands);
		commands = get_next_line(0);
	}
	return (commands);
}

void	sort_check_checker(t_stacks *stacks)
{
	if (stacks->stack_b_len == 0 && sort_compare(stacks) == 0)
	{
		ft_putstr("OK\n");
		free_stacks(stacks);
		exit (0);
	}
	else
		ft_putstr("KO\n");
	free_stacks(stacks);
}

void	execution(t_stacks *stacks, char **argv)
{
	init(stacks, argv);
	quicksort(stacks->stack_presort, 0, stacks->stack_presort_len - 1);
	read_commands(stacks);
	sort_check_checker(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		ft_putstr("Error\n");
	else
		execution(&stacks, argv);
	return (0);
}
