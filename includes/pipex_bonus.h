/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 07:52:30 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/01 11:50:47 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

void	error(char *msg);
void	run_commands(int start, int argc, char **argv, char **envp);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
void	here_doc(char *limiter, int argc);
void	child_proc(char *cmd, char **envp);
int		open_infile(char *file);

#endif