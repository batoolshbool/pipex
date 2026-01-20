/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 08:05:32 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/20 15:15:06 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	child_proc(char *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
	{
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		execute(cmd, envp);
	}
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}

static void	here_doc_child(char *limiter, int *fd)
{
	char	*line;
	char	*stop;

	stop = ft_strjoin(limiter, "\n");
	close(fd[0]);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (!ft_strncmp(line, stop, ft_strlen(stop)))
		{
			free(line);
			break ;
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	free(stop);
	close(fd[1]);
	exit(0);
}

void	here_doc(char *limiter)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		exit(1);
	pid = fork();
	if (pid == -1)
		exit(1);
	if (pid == 0)
		here_doc_child(limiter, fd);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}

static int	setup_files(int argc, char **argv, int *out)
{
	int	in;

	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		*out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (*out < 0)
			exit(1);
		return (3);
	}
	in = open(argv[1], O_RDONLY);
	if (in < 0)
	{
		perror(argv[1]);
		in = open("/dev/null", O_RDONLY);
	}
	dup2(in, STDIN_FILENO);
	close(in);
	*out = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (*out < 0)
		exit(1);
	return (2);
}

int	main(int argc, char **argv, char **envp)
{
	int		out;
	int		i;
	pid_t	pid;

	if (argc < 5)
		return (1);
	if (!ft_strncmp(argv[1], "here_doc", 8))
		here_doc(argv[2]);
	i = setup_files(argc, argv, &out);
	while (i < argc - 2)
		child_proc(argv[i++], envp);
	pid = fork();
	if (pid == 0)
	{
		dup2(out, STDOUT_FILENO);
		close(out);
		execute(argv[argc - 2], envp);
	}
	close(out);
	while (wait(NULL) > 0)
		;
	return (0);
}
