/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 08:00:42 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/01 11:43:04 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(char *msg)
{
	perror(msg);
	exit(EXIT_FAILURE);
}

char	*loop_path(char **path, char *cmd)
{
	int		i;
	char	*the_path;
	char	*new_path;

	i = 0;
	while (path[i])
	{
		the_path = ft_strjoin(path[i], "/");
		new_path = ft_strjoin(the_path, cmd);
		free(the_path);
		if (access(new_path, F_OK) == 0)
			return (new_path);
		free(new_path);
		i++;
	}
	return (NULL);
}

char	*find_path(char *cmd, char **envp)
{
	int		i;
	char	*full_path;
	char	**splitted_paths;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	splitted_paths = ft_split(envp[i] + 5, ':');
	full_path = loop_path(splitted_paths, cmd);
	i = 0;
	while (splitted_paths[i])
		free(splitted_paths[i++]);
	free(splitted_paths);
	return (full_path);
}

char	*get_cmd_path(char **cmd, char **envp)
{
	char	*path;

	if (ft_strchr(cmd[0], '/'))
		path = ft_strdup(cmd[0]);
	else
		path = find_path(cmd[0], envp);
	if (!path)
	{
		free_cmd(cmd);
		error("ERROR: Command not found");
	}
	return (path);
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	if (!argv || argv[0] == '\0')
		error("ERROR: Empty command");
	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
	{
		if (cmd)
			free(cmd);
		error("ERROR: Empty command");
	}
	path = get_cmd_path(cmd, envp);
	if (execve(path, cmd, envp) == -1)
		error("ERROR: execve failed!");
}

/*envp[0] = "USER=you"
envp[1] = "HOME=/home/you"
envp[2] = "PATH=/usr/local/bin:/usr/bin:/bin"*/