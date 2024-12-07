/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 11:44:08 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/10 11:44:09 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	prelen;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	prelen = ft_strlen(s) - (size_t)start;
	if (prelen > len)
		prelen = len;
	new_str = ft_calloc(sizeof(char), prelen + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (s[(size_t)start + ++i] && i < len)
		new_str[i] = s[(size_t)start + i];
	new_str[i] = '\0';
	return (new_str);
}
