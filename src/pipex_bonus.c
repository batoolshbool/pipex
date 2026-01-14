/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 08:05:32 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/14 15:50:42 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	child_proc(char *cmd, char **envp)
{
	int		fd[2];
	pid_t	pid;

	if (pipe(fd) == -1)
		error("pipe");
	pid = fork();
	if (pid == -1)
		error("fork");
	if (pid == 0)
	{
		dup2(fd[1], 1);
		close(fd[0]);
		close(fd[1]);
		execute(cmd, envp);
	}
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
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
	exit(EXIT_SUCCESS);
}

void	here_doc(char *limiter, int argc)
{
	int		fd[2];
	pid_t	pid;

	if (argc < 6)
		error("bad arguments");
	if (pipe(fd) == -1)
		error("pipe");
	pid = fork();
	if (pid == -1)
		error("fork");
	if (pid == 0)
		here_doc_child(limiter, fd);
	close(fd[1]);
	dup2(fd[0], 0);
	close(fd[0]);
	waitpid(pid, NULL, 0);
}

static int	setup_files(int argc, char **argv, int *in_file, int *out_file)
{
	int	i;

	i = 2;
	if (!ft_strncmp(argv[1], "here_doc", 8))
	{
		i = 3;
		*out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_APPEND, 0644);
		if (*out_file < 0)
			error("ERROR: cannot open outfile");
	}
	else
	{
		*in_file = open(argv[1], O_RDONLY);
		if (*in_file < 0)
		{
			perror(argv[1]);
			*in_file = open("/dev/null", O_RDONLY);
		}
		dup2(*in_file, 0);
		close(*in_file);
		*out_file = open(argv[argc - 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (*out_file < 0)
			error("ERROR: cannot open outfile");
	}
	return (i);
}

// int	main(int argc, char **argv, char **envp)
// {
// 	int	in_file;
// 	int	out_file;
// 	int	i;

// 	if (argc < 5)
// 	{
// 		write(2, "Error: too few arguments\n", 25);
// 		exit(EXIT_FAILURE);
// 	}
// 	if (!ft_strncmp(argv[1], "here_doc", 8))
// 		here_doc(argv[2], argc);
// 	i = setup_files(argc, argv, &in_file, &out_file);
// 	run_commands(i, argc, argv, envp);
// 	dup2(out_file, 1);
// 	close(out_file);
// 	execute(argv[argc - 2], envp);
// }

int	main(int argc, char **argv, char **envp)
{
	int		in_file;
	int		out_file;
	int		i;
	pid_t	pid;

	if (argc < 5)
		error("too few arguments");
	if (!ft_strncmp(argv[1], "here_doc", 8))
		here_doc(argv[2], argc);
	i = setup_files(argc, argv, &in_file, &out_file);
	run_commands(i, argc, argv, envp);
	pid = fork();
	if (pid == -1)
		error("fork");
	if (pid == 0)
	{
		dup2(out_file, 1);
		close(out_file);
		execute(argv[argc - 2], envp);
	}
	close(out_file);
	while (wait(NULL) > 0)
		;
}
