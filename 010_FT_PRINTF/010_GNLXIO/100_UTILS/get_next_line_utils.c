/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/21 12:05:32 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/15 13:59:58 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

void	*gnlxio_ft_calloc(size_t nmemb, size_t size)
{
	void	*alloc;
	size_t	i;

	if ((long)nmemb == 0 || (long)size == 0)
		return (malloc(0));
	if (size && nmemb > SIZE_MAX / size)
		return (NULL);
	alloc = NULL;
	alloc = malloc(nmemb * size);
	if (!alloc)
		return (NULL);
	i = -1;
	while (++i < nmemb * size)
		*(unsigned char *)(alloc + i) = '\0';
	return (alloc);
}

size_t	gnlxio_ft_strlen(const char *str)
{
	size_t	len;

	if (!str)
		return (0);
	len = -1;
	while (str[++len])
		;
	return (len);
}

static size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	init_dest;
	size_t	init_src;

	i = gnlxio_ft_strlen((const char *)dest);
	j = 0;
	init_dest = i;
	init_src = gnlxio_ft_strlen(src);
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

char	*gnlxio_ft_strjoinfree(char **s1, char **s2)
{
	size_t	len;
	char	*new_str;

	len = gnlxio_ft_strlen(*s1);
	if (*s2)
		len += gnlxio_ft_strlen(*s2);
	new_str = gnlxio_ft_calloc(len + 1, 1);
	if (!new_str)
		return (NULL);
	if (*s1)
	{
		ft_strlcat(new_str, *s1, len + 1);
		free(*s1);
		*s1 = NULL;
	}
	if (*s2)
	{
		ft_strlcat(new_str, *s2, len + 1);
		free(*s2);
		*s2 = NULL;
	}
	return (new_str);
}
