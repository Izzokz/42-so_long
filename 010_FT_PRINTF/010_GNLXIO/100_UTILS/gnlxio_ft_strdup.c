/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlxio_ft_strdup.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:13:56 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/16 13:27:48 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

char	*gnlxio_ft_strdup(const char *src)
{
	char	*dest;
	int		len;
	int		index;

	len = gnlxio_ft_strlen(src);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (dest);
	dest[len] = '\0';
	index = -1;
	while (++index < len)
		dest[index] = src[index];
	return (dest);
}
