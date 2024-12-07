/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:25:36 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/10 11:25:37 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;
	int		index;

	len = ft_strlen(src);
	dest = malloc(sizeof(char) * len + 1);
	if (!dest)
		return (dest);
	dest[len] = '\0';
	index = 0;
	while (index < len)
	{
		dest[index] = src[index];
		index++;
	}
	return (dest);
}
