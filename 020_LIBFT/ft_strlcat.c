/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 18:17:33 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/08 18:17:36 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	init_dest;
	size_t	init_src;

	i = ft_strlen((const char *)dest);
	j = 0;
	init_dest = ft_strlen((const char *)dest);
	init_src = ft_strlen(src);
	if (size <= init_dest)
		return (size + init_src);
	while (src[j] && j < size - init_dest - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (init_dest + init_src);
}
