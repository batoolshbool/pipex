/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 07:56:24 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/14 15:21:23 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_proc(char *argv[], char **envp, int *fd)
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
		error("ERROR: Open infile failed");
	dup2(file, 0);
	dup2(fd[1], 1);
	close(fd[0]);
	close(file);
	execute(argv[2], envp);
}

void	parent_proc(char *argv[], char **envp, int *fd)
{
	int	file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
		error("ERROR: Open outfile failed");
	dup2(file, 1);
	dup2(fd[0], 0);
	close(fd[1]);
	close(file);
	execute(argv[3], envp);
}

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
		error("ERROR: ./pipex infile cmd1 cmd2 outfile");
	if (pipe(fd) == -1)
		error("ERROR: pipe failed");
	pid1 = fork();
	if (pid1 == -1)
		error("ERROR: fork failed");
	if (pid1 == 0)
		child_proc(argv, envp, fd);
	pid2 = fork();
	if (pid2 == -1)
		error("ERROR: fork failed");
	if (pid2 == 0)
		parent_proc(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
