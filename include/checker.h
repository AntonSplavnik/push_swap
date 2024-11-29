/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asplavni <asplavni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 22:11:56 by asplavni          #+#    #+#             */
/*   Updated: 2024/11/29 02:49:33 by asplavni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "shared.h"

int		commands_call(t_stacks *stacks, char *command);
char	*read_commands(t_stacks *stacks);
void	sort_check_checker(t_stacks *stacks);
void	execution(t_stacks *stacks, char **argv);
int		main(int argc, char **argv);

#endif