/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:54 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/24 19:10:39 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

//helper_functions.c
void	ft_putstr(char *str);
void	ft_memset(void *str, int c, size_t number);
void	ft_bzero(void *str, size_t number);
void	*ft_calloc(size_t num, size_t size);
//int	count_ints_in_an_array(int *numbers);
//int	*ft_realloc(int *input_array, int new_leangth);
int		ft_atoi(char *input_str);

//parsing.c
int		string_restrictions_checker(char *input_str);
int		duplicate_check(int *input, int size);

//main.c
void	input_to_array(int argc, char **str);
int		main(int argc, char **argv);

#endif