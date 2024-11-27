/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:30:34 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/27 22:08:31 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORYTHM_H
# define ALGORYTHM_H

#include "shared.h"

// sort_3.c
int		sort_3_calc_largest(int *stack, int len);
void	sort_3(int *stack, int len);

//	sort.5.c
int		calc_smallest(int *stack, int len);
int		calc_largest(int *stack, int len);
int		find_correct_pos_in_a(t_stacks *stacks);
void	sort_5(t_stacks *stacks);

// sort_turk.c
int		min_index(int *stack, int len);
int		max_index(int *stack, int len);
int		find_min(t_stacks *stacks);
int		find_max(t_stacks *stacks);
int		find_correct_position_in_a(t_stacks *stacks, int num);
int		calculate_stack_operations(int stack_size, int index);
int		calculate_operations(t_stacks *stacks, int index_b);
int		find_cheapest_in_b(t_stacks *stacks);
void	push_cheapest_to_a(t_stacks *stacks, int index);

// sort_average.c
int		ft_abs(int num);
int		sum(int *stack, int len);
int		find_index(int	*stack, int len, int num);
int		find_closes_num(int	*stack, int len, int averadge);
int		find_index_to_push(int *stack, int len, int avrg);
void	push_average_to_b(t_stacks *stacks);

// sorting.c
void	sorter(t_stacks *stacks);
void	algorythm(t_stacks *stacks);

//execution
void	execution(char **argv, t_stacks *stacks);

//main.c
void	free_stacks(t_stacks *stacks);
int		main(int argc, char **argv);


#endif