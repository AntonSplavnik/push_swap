/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 21:30:34 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/29 02:33:12 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGORITHM_H
# define ALGORITHM_H

# include "shared.h"

// sort_utils.c
void	move_index_a_top(t_stacks *stacks, int index);
void	move_index_b_top(t_stacks *stacks, int index);

// sort_utils.c
int		min_index(int *stack, int len);
int		max_index(int *stack, int len);
int		find_min(t_stacks *stacks);
int		find_max(t_stacks *stacks);

// sort_3.c
int		sort_3_calc_largest(int *stack, int len);
void	sort_3(int *stack, int len);

// sort_average.c
int		sum(int *stack, int len);
int		find_index_to_push(int *stack, int len, int avrg);
void	bring_index_to_top(t_stacks *stacks, int index_to_push);
void	push_average_to_b(t_stacks *stacks);

// sort_torque_2.c
int		find_insert_position_for_bounds(t_stacks *stacks, int min);
int		find_insert_position_between(t_stacks *stacks, int num);
int		find_correct_position_in_a(t_stacks *stacks, int num);

// sort_turk.c
int		calculate_stack_operations(int stack_size, int index);
int		calculate_operations(t_stacks *stacks, int index_b);
int		find_cheapest_in_b(t_stacks *stacks);
void	push_cheapest_to_a(t_stacks *stacks, int index);

// sorting.c
void	move_samllest_to_top(t_stacks *stacks);
void	algorithm(t_stacks *stacks);

//execution
void	execution(t_stacks *stacks, char **argv);

//main.c
int		main(int argc, char **argv);

#endif
