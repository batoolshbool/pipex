/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 07:56:24 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/20 20:17:31 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	child_proc(char *argv[], char **envp, int *fd)
{
	int	file;

	file = open(argv[1], O_RDONLY);
	if (file == -1)
	{
		perror(argv[1]);
		close(fd[1]);
		close(fd[0]);
		exit(1);
	}
	dup2(file, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	close(file);
	execute(argv[2], envp);
}

void	parent_proc(char *argv[], char **envp, int *fd)
{
	int	file;

	file = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (file == -1)
	{
		perror(argv[4]);
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(file, STDOUT_FILENO);
	close(fd[1]);
	close(fd[0]);
	close(file);
	execute(argv[3], envp);
}

static pid_t	create_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		perror("fork");
	return (pid);
}

void	create_pipe(int fd[2])
{
	if (pipe(fd) == -1)
	{
		perror("pipe");
		exit(1);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int		fd[2];
	pid_t	pid1;
	pid_t	pid2;

	if (argc != 5)
	{
		write(2, "Usage: ./pipex infile cmd1 cmd2 outfile\n", 41);
		return (1);
	}
	create_pipe(fd);
	pid1 = create_fork();
	if (pid1 == 0)
		child_proc(argv, envp, fd);
	pid2 = create_fork();
	if (pid2 == 0)
		parent_proc(argv, envp, fd);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}
