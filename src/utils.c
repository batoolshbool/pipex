/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 08:00:42 by bshbool           #+#    #+#             */
/*   Updated: 2026/01/20 15:14:12 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static void	free_split(char **cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return ;
	while (cmd[i])
		free(cmd[i++]);
	free(cmd);
}

char	*loop_path(char **paths, char *cmd)
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

	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5))
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

char	*get_cmd_path(char **cmd, char **envp)
{
	if (ft_strchr(cmd[0], '/'))
	{
		if (access(cmd[0], X_OK) == 0)
			return (ft_strdup(cmd[0]));
		return (NULL);
	}
	return (find_path(cmd[0], envp));
}

void	execute(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, ' ');
	if (!cmd || !cmd[0])
		exit(127);
	path = get_cmd_path(cmd, envp);
	if (!path)
	{
		free_split(cmd);
		write(2, "command not found\n", 18);
		exit(127);
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_split(cmd);
		exit(126);
	}
}

/*envp[0] = "USER=you"
envp[1] = "HOME=/home/you"
envp[2] = "PATH=/usr/local/bin:/usr/bin:/bin"*/