/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:54 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/02 21:11:09 by asplavni         ###   ########.fr       */
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

typedef struct s_int_array
{
	int	*unsorted_numbers;
	int	unsorted_numbers_num;
	int	unsorted_numbers_iterator;
}			t_int_array;

//utility_functions.c
void	ft_putstr(char *str);
void	ft_bzero(void *str, size_t number);
int		ft_atoi(char *input_str);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strncpy(char *dest, const char *src, size_t n);
size_t	ft_strlen(const char *s);

//ft_split.c
int		ft_split_token_counter(char *input, char c);
void	ft_split_free_alloc(char **return_str, int j);
char	**ft_split_fill_arrays(char *input, char **return_str, char c);
char	**ft_split(char *input, char c);

//parsing.c
int		input_restrictions(char *input_str);
int		limits(long number);
int		duplicate_check(int *input, int size);

//number_counter.c
int		number_counter(char **argv);

//process_argument.c
char	**process_argument(char *argv);

//fill_array.c
void	clenup_on_error(int j, char **processed_argument);
int		process_and_validate_argument(t_int_array int_array,
			char *processed_argument, int j);
void	free_processed_argument(char **processed_argument);
void	fill_array(char **argv, t_int_array int_array);

//main.c
void	input_to_array(char **str);
int		main(int argc, char **argv);

#endif