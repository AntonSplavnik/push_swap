/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:11:56 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/28 00:26:59 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

int		ft_strcmp(char *input1, char *input2);
int		commands_call(t_stacks *stacks, char *command);
void	execution(t_stacks *stacks, char **argv);
int		main(int argc, char **argv);

#endif