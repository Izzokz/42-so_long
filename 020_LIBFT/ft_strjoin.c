/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 16:40:54 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/10 16:40:55 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	len;
	char	*new_str;

	len = ft_strlen(s1) + ft_strlen(s2);
	new_str = ft_calloc(sizeof(char [len + 1]), 1);
	if (!new_str)
		return (NULL);
	ft_strlcat(new_str, s1, len + 1);
	ft_strlcat(new_str, s2, len + 1);
	return (new_str);
}
