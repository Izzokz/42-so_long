/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 16:33:30 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/08 16:33:32 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	index;

	if (size == 0)
		return (ft_strlen(src));
	index = 0;
	while (index < size - 1 && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	dest[index] = 0;
	return (ft_strlen(src));
}
