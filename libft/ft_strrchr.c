/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/05 12:28:35 by bshbool           #+#    #+#             */
/*   Updated: 2025/08/30 16:42:37 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;
	char	*occur;

	occur = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			occur = (char *)&str[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (occur);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
        char tweet[] = "Hello, World!";
        char *m  = strrchr(tweet, 'H');
        char *m2 = ft_strrchr(tweet, 'H');
	char *m3 = strchr(tweet, 'H');
        printf("%s\n", m);
        printf("%s\n", m2);
	printf("%s\n", m3);

}*/
