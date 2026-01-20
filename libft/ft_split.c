/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/13 18:49:11 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/02 13:29:34 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static char	*ft_dupfunc(const char *s, size_t a, char c)
{
	char	*var;
	size_t	j;
	size_t	i;
	size_t	start;

	start = a;
	while (s[a] && s[a] != c)
		a++;
	i = a - start;
	var = (char *)malloc((i + 1) * sizeof(char));
	if (!var)
		return (NULL);
	j = 0;
	while (j < i)
	{
		var[j] = s[start + j];
		j++;
	}
	var[j] = '\0';
	return (var);
}

static char	**ft_free(char **var, size_t j)
{
	if (!var)
		return (NULL);
	while (j > 0)
	{
		j--;
		if (var[j])
		{
			free(var[j]);
			var[j] = NULL;
		}
	}
	free(var);
	return (NULL);
}

static char	**ft_fill(char const *s, char c, char **var)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
		{
			var[j] = ft_dupfunc(s, i, c);
			if (!var[j])
				return (ft_free(var, j));
			j++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	var[j] = NULL;
	return (var);
}

char	**ft_split(char const *s, char c)
{
	size_t	count;
	char	**var;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	var = malloc((count + 1) * sizeof(char *));
	if (!var)
		return (NULL);
	var = ft_fill(s, c, var);
	return (var);
}

// #include <stdio.h>
// int main()
// {
// 	char **meow = ft_split("  meow meow meow meow :3", ' ');
// 	int i = 0 ;
// 	while(meow[i])
// 	{
// 		printf("%s\n", meow[i]);
// 		free(meow[i]);
// 		i++;
// 	}
// 	free(meow);
// }