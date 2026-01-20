/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 16:49:48 by bshbool           #+#    #+#             */
/*   Updated: 2025/08/30 16:41:43 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	//char tweet[] = "This is my @mention hi";
	char *m  = strchr(tweet, '@');
	char *m2 = ft_strchr(tweet, '@');
	printf("%s\n", m);
	printf("%s\n", m2);
}*/
