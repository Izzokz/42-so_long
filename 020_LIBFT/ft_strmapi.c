/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 14:43:12 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/14 14:43:12 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*new_str;
	int		i;

	i = -1;
	new_str = ft_calloc(sizeof(char), ft_strlen(s) + 1);
	if (!new_str)
		return (NULL);
	while ((unsigned int)s[++i])
		new_str[i] = f((unsigned int)i, (char)s[i]);
	return (new_str);
}
