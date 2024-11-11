/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:54 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/11 21:40:30 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_stacks
{
	int	*stack_a;
	int	*stack_b;
	int	len;
	int	stack_a_len;
	int	stack_b_len;
}			t_stacks;

// utility_functions.c
void	ft_putstr(char *str);
void	ft_bzero(void *str, size_t number);
long	ft_atoi(char *input_str);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strncpy(char *dest, const char *src, size_t n);

// ft_split.c
int		ft_split_token_counter(char *input, char c);
void	ft_split_free_alloc(char **return_str, int j);
char	**ft_split_fill_arrays(char *input, char **return_str, char c);
char	**ft_split(char *input, char c);
char	*ft_split_calloc_call(char **return_str, int i, int j, int start);

// number_counter.c
int		number_counter(char **argv);

// parsing.c
void	empty_argument_checker(char **argv);
int		limits(long number);
int		duplicate_check(int *input, int size);
int		input_restrictions_helper(char *input_str, int i);
int		input_restrictions(char *input_str);

// fill_array.c
void	clenup_on_error(char **processed_argument, t_stacks *int_array);
int		process_and_validate_argument(t_stacks *int_array,
			char *processed_argument, int k);
void	free_processed_argument(char **processed_argument);
void	fill_array(char **argv, t_stacks *int_array);

// initialization
void	init(char **argv, t_stacks *stacks);
void	stack_a_initialisation(t_stacks *int_arrays, char **argv);
void	stack_b_initialisation(t_stacks	*int_arrays);
void	algorythm(t_stacks *stacks);


//sorting functions
void	push_a(t_stacks *stacks);
void	push_b(t_stacks *stacks);

void	swap_a(t_stacks	*stacks);
void	swap_b(t_stacks	*stacks);

void	rotate_a(t_stacks *stacks);
void	rotate_b(t_stacks *stacks);

void	reverse_rotate_a(t_stacks *stacks);
void	reverse_rotate_b(t_stacks *stacks);

// sorting.c
int		calc_largest(t_stacks *stacks);
void	algorythm(t_stacks *stacks);

//sort check
int		sort_check(t_stacks *stacks);

//execution
void	execution(char **argv, t_stacks *stacks);

//main.c
int		main(int argc, char **argv);

#endif