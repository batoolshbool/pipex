/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 10:03:28 by bshbool           #+#    #+#             */
/*   Updated: 2025/11/10 18:30:41 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_and_save(int fd, char *buffer)
{
	char	*malloced;
	ssize_t	readd;
	char	*temp;

	malloced = malloc(BUFFER_SIZE + 1);
	if (!malloced)
		return (NULL);
	readd = 1;
	while ((!buffer || !ft_strchr(buffer, '\n')) && readd > 0)
	{
		readd = read(fd, malloced, BUFFER_SIZE);
		if (readd < 0)
		{
			free(malloced);
			return (NULL);
		}
		malloced[readd] = '\0';
		temp = buffer;
		buffer = ft_strjoin(temp, malloced);
		free(temp);
	}
	free(malloced);
	return (buffer);
}

static char	*extract_line(char *buffer)
{
	char	*line;
	int		i;

	if (!buffer || !buffer[0])
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_substr(buffer, 0, i);
	return (line);
}

static char	*clear_buffer(char *buffer)
{
	int		i;
	char	*new;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	i++;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	new = ft_substr(buffer, i, ft_strlen(buffer) - i);
	free(buffer);
	return (new);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*returned_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = read_and_save(fd, buffer);
	if (!buffer)
		return (NULL);
	returned_line = extract_line(buffer);
	if (!returned_line)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	buffer = clear_buffer(buffer);
	return (returned_line);
}

// #include "get_next_line.h"
// #include <fcntl.h>
// #include <stdio.h>
// int main()
// {
// 	int fd = open("a.txt", O_RDONLY);
// 	char *line;

// 	while ((line = get_next_line(fd)) != NULL)
// 	{
// 		printf("%s", line);
// 		free(line);
// 	}

// 	close(fd);
// 	return 0;
// }