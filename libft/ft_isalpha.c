/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 13:29:19 by bshbool           #+#    #+#             */
/*   Updated: 2025/08/30 12:43:15 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	return (0);
}

/*#include <stdio.h>
#include <ctype.h>

int	main(void) {
  char c = 'A';
  if (isalpha(c)) {
    printf("%c is a letter\n", c);
  } else {
    printf("%c is not a letter\n", c);
  }
   if (ft_isalpha(c)) {
    printf("%c is a letter\n", c);
  } else {
    printf("%c is not a letter\n", c);
  }
  return (0);
}*/
