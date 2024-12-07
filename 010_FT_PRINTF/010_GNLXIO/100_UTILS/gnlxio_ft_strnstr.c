/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlxio_ft_strnstr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 16:43:27 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/23 12:30:50 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

char	*gnlxio_ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	jindex;
	size_t	little_len;

	index = 0;
	little_len = gnlxio_ft_strlen(little);
	if (little_len == 0)
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[index] != '\0' && index < len)
	{
		jindex = 0;
		while (big[index + jindex] == little[jindex] && jindex + index < len)
		{
			if (!little[jindex + 1])
				return ((char *)big + index);
			jindex++;
		}
		index++;
	}
	return (NULL);
}
