/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 17:33:51 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/10 17:33:52 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s, const char *set)
{
	size_t	e;
	size_t	b;
	char	*new_str;

	e = ft_strlen(s);
	b = -1;
	if (e == 0 && !ft_strchr(set, '\0'))
		return ("");
	while (s[--e] && ft_strchr(set, s[e]))
		;
	while (s[++b] && ft_strchr(set, s[b]))
		;
	if (b > e)
	{
		new_str = malloc(1);
		new_str[0] = '\0';
		return (new_str);
	}
	new_str = ft_substr(s, b, e - b + 1);
	return (new_str);
}
