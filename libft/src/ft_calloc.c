/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshbool <bshbool@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 17:14:50 by bshbool           #+#    #+#             */
/*   Updated: 2025/09/01 10:03:14 by bshbool          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*var;

	if (!nmemb || !size)
		return (malloc(0));
	var = malloc(size * nmemb);
	if (!var)
		return (NULL);
	ft_bzero(var, size * nmemb);
	return (var);
}

//#include <stdio.h>
//#include <stdlib.h>
//int main() {
//	int n = 2;
//	//int *array = (int*)calloc(n, sizeof(int));
//	//printf("Array elements after calloc: ");
//	//for (int i = 0; i < n; i++) {
//	//	printf("%darr ", array[i]);
//	//}
//	//printf("\n");
//	int *array2 = (int*)ft_calloc(n, sizeof(int));
//	printf("Array elements after ft_calloc: ");
//	for (int i = 0; i < n; i++) {
//		printf("%d ", array2[i]);
//	}
//	printf("\n");
//	//free(array);
//	free(array2);
//	return (0);
//}
