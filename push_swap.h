/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 13:40:54 by asplavni          #+#    #+#             */
/*   Updated: 2024/10/25 18:52:47 by asplavni         ###   ########.fr       */
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
int		*ft_realloc(int *input_array, int new_length, int old_length);
int		ft_atoi(char *input_str);

//parsing.c
int		string_restrictions(char *input_str);
int		limits(int number);
int		duplicate_check(int *input, int size);

//main.c
void	input_to_array(int argc, char **str);
int		main(int argc, char **argv);

#endif