/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 08:05:21 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/14 15:47:20 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

void	run_commands(int start, int argc, char **argv, char **envp)
{
	while (start < argc - 2)
		child_proc(argv[start++], envp);
}

static char	*loop_path(char **paths, char *cmd)
{
	int		i;
	char	*tmp;
	char	*full;

	i = 0;
	while (paths[i])
	{
		tmp = ft_strjoin(paths[i], "/");
		full = ft_strjoin(tmp, cmd);
		free(tmp);
		if (access(full, X_OK) == 0)
			return (full);
		free(full);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	**paths;
	char	*full;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	if (!envp[i])
		return (NULL);
	paths = ft_split(envp[i] + 5, ':');
	full = loop_path(paths, cmd);
	i = 0;
	while (paths[i])
		free(paths[i++]);
	free(paths);
	return (full);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	if (!argv || !*argv)
		error("ERROR: Empty command!");
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
		error("ERROR: Empty command!");
	path = find_path(cmd[0], envp);
	if (!path)
	{
		i = 0;
		while (cmd[i])
			free(cmd[i++]);
		free(cmd);
		error("ERROR: command not found!");
	}
	execve(path, cmd, envp);
	free(path);
	i = 0;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
	error("ERROR: execve failed!");
}
