/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 07:50:50 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/01 07:52:13 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>
# include "libft.h"

void	error(char *msg);
char	*loop_path(char **path, char *cmd);
char	*find_path(char *cmd, char **envp);
void	execute(char *argv, char **envp);
void	child_proc(char *argv[], char **envp, int *fd);
void	parent_proc(char *argv[], char **envp, int *fd);

#endif