/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:49 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/27 19:46:32 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**process_argument(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (argv[i] == ' ' && i == 0)
			i++;
	}
}

void	input_to_array(int argc, char **str)
{
	int		i;
	int		n;
	int		elements_count;
	int		*unsorted_numbers;
	char	**arrs;


	i = 1;
	elements_count = element_counter(str);

	process_argument(**str);
	while (str[i])
	{
		arrs[i] = split(str[i]);
		n += count_elements(arrs[i]);
	}

	ft_putstr("\nUnsorted numbers:\n");
	while (i <= argc)
	{
		if (string_restrictions(str[i]) == 1)
			exit (1);
		else if (limits(ft_atoi(str[i])) == 1)
			exit (1);
		i++;
	}

	i = 1;
	unsorted_numbers = ft_calloc(argc, sizeof(int));
	if (unsorted_numbers == NULL)
	{
		ft_putstr("Error: Memory allocation\n");
		exit (1);
	}
	while (i <= argc)
	{
		unsorted_numbers[i - 1] = ft_atoi(str[i]);
		printf("\t\t\t%d\n", unsorted_numbers [i - 1]);
		i++;
	}
	if (duplicate_check(unsorted_numbers, argc) == 1)
	{
		ft_putstr("Error: Duplicate found\n");
		free(unsorted_numbers);
		exit (1);
	}
	free(unsorted_numbers);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putstr("Error: Wrong number of arguments.\n"
			"Should be more then two arguments.\n");
	}
	else
		input_to_array(argc - 1, argv);
	ft_putstr("\n");
	return (0);
}
