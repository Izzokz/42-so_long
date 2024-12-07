/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 12:55:18 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/09 12:55:20 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index;
	size_t	jindex;
	size_t	little_len;

	index = 0;
	little_len = ft_strlen(little);
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
