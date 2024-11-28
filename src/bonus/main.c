/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:57:47 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 18:42:56 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shared.h"
#include "checker.h"
#include "get_next_line.h"

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

int	commands_call(t_stacks *stacks, char *command)
{
	if (ft_strcmp(command,"pa\n") == 0)
		push_a(stacks, 0);
	else if (ft_strcmp(command,"pb\n") == 0)
		push_b(stacks, 0);
	else if (ft_strcmp(command,"sa\n") == 0)
		swap_a(stacks, 0);
	else if (ft_strcmp(command,"sb\n") == 0)
		swap_b(stacks, 0);
	else if (ft_strcmp(command,"ss\n") == 0)
		swap_a_b(stacks, 0);
	else if (ft_strcmp(command,"ra\n") == 0)
		rotate_a(stacks, 0);
	else if (ft_strcmp(command,"rb\n") == 0)
		rotate_b(stacks, 0);
	else if (ft_strcmp(command,"rr\n") == 0)
		rotate_a_b(stacks, 0);
	else if (ft_strcmp(command,"rra\n") == 0)
		reverse_rotate_a(stacks, 0);
	else if (ft_strcmp(command,"rrb\n") == 0)
		reverse_rotate_b(stacks, 0);
	else if (ft_strcmp(command,"rrr\n") == 0)
		reverse_rotate_a_b(stacks, 0);
	else
		return (1);

	return (0);
}

void	execution(t_stacks *stacks, char **argv)
{
	char *command;

	init(stacks, argv);
	quicksort(stacks->stack_presort, 0, stacks->stack_presort_len - 1);

	// if (sort_check(stacks->stack_a, stacks->stack_a_len) == 0)
	// {
	// 	free_stacks(stacks);
	// 	exit (0);
	// }

	command = get_next_line(0);

	while (command != NULL)
	{
		if (commands_call(stacks, command) == 1)
		{
			ft_putstr("Error");
			free(command);
			free_stacks(stacks);
			exit (1);
		}
		free(command);
		command = get_next_line(0);
	}

	// for (int i = stacks->stack_a_len; i > 0; i--)
	// 	printf("%d. stack_A: %d\n", i - 1, stacks->stack_a[i - 1]);

	// ft_putstr("\n");

	// for (int i = stacks->stack_b_len; i > 0; i--)
	// 	printf("%d. stack_B: %d\n", i - 1, stacks->stack_b[i - 1]);

	if (stacks->stack_b_len == 0 && sort_compare(stacks) == 0)
	{
		ft_putstr("OK\n");
		free(command);
		free_stacks(stacks);
		exit (0);
	}
	else
		ft_putstr("KO\n");

	free_stacks(stacks);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	if (argc < 2)
		ft_putstr("Error: Wrong number of arguments.\n"
			"Should be more then two arguments.\n");
	else
		execution(&stacks, argv);
	return (0);
}
