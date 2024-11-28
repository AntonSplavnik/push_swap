/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:54 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 01:25:17 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHARED_H
# define SHARED_H

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
	int	*stack_presort;
	int	len;
	int	stack_a_len;
	int	stack_b_len;
	int	stack_presort_len;
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
void	free_stacks(t_stacks *stacks);

// initialization
void	init(t_stacks *stacks, char **argv);
void	stack_a_initialisation(t_stacks *int_arrays, char **argv);
void	stack_b_initialisation(t_stacks	*int_arrays);
void	stack_presorted_init(t_stacks *stacks);

//operations
void	push_a(t_stacks *stacks, int flag);
void	push_b(t_stacks *stacks, int flag);

void	swap(int *stack, int len);
void	swap_a(t_stacks *stacks, int flag);
void	swap_b(t_stacks *stacks, int flag);
void	swap_a_b(t_stacks *stacks, int flag);

void	rotate(int *stack, int len);
void	rotate_a(t_stacks *stacks, int flag);
void	rotate_b(t_stacks *stacks, int flag);
void	rotate_a_b(t_stacks *stacks, int flag);

void	reverse_rotate(int *stack, int len);
void	reverse_rotate_a(t_stacks *stacks, int flag);
void	reverse_rotate_b(t_stacks *stacks, int flag);
void	reverse_rotate_a_b(t_stacks *stacks, int flag);

// quicksort.c
void	quicksort_swap(int *a, int *b);
int		partition(int arr[], int low, int high);
void	quicksort(int arr[], int low, int high);

//sort check
// int		sort_check(t_stacks *stacks);
int		sort_check(int *input, int len);
int		sort_compare(t_stacks *stacks);

#endif
