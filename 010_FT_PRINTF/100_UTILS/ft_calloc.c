/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 10:02:26 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/10 10:02:27 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	i;

	if ((long)nmemb == 0 || (long)size == 0)
		return (malloc(0));
	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	i = -1;
	while (++i < nmemb * size)
		*(unsigned char *)(alloc + i) = '\0';
	return (alloc);
}
