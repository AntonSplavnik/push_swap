/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:54 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/31 20:43:29 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_int_array
{
	int	*unsorted_numbers;
	int	unsorted_numbers_num;
}			t_int_array;

//utility_functions.c
int		ft_atoi(char *input_str);
void	ft_putstr(char *str);
void	ft_bzero(void *str, size_t number);
void	*ft_calloc(size_t num, size_t size);
char	*ft_strncpy(char *dest, const char *src, size_t n);

//ft_split.c
int		ft_split_token_counter(char *input, char c);
void	ft_split_free_alloc(char **return_str, int j);
char	**ft_split_fill_arrays(int token_counter,
			char *input, char **return_str, char c);
char	**ft_split(char *input, char c);

//parsing.c
int		number_counter(char **str);
int		input_restrictions(char *input_str);
int		limits(int number);
int		duplicate_check(int *input, int size);

//main.c
void	input_to_array(int argc, char **str);
int		main(int argc, char **argv);

#endif