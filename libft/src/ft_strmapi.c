/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/12 19:47:37 by bshbool           #+#    #+#             */
/*   Updated: 2025/08/30 16:46:06 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*var;
	size_t	len;
	size_t	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	var = (char *)malloc(sizeof(char) * (len + 1));
	if (!var)
		return (NULL);
	i = 0;
	while (i < len)
	{
		var[i] = f(i, s[i]);
		i++;
	}
	var[i] = '\0';
	return (var);
}
/*char func(unsigned int i, char c)
 {
	if (i % 2 == 0)
		return ((char)ft_toupper(c));
	else
		return ((char)ft_tolower(c));
 }

 #include <stdio.h>
 int main()
 {
	char *i = ft_strmapi("Helloooo", func);
	printf("%s\n", i);
 }*/