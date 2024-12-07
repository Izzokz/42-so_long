/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlxio_ft_split.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:49:24 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/06 14:37:16 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

/*
Chains : Number of Chains
*/
static int	ft_strlench(const char *line, char *sep)
{
	t_ints	i;

	i.i = 0;
	i.count = 0;
	while (line[i.i])
	{
		while (line[i.i] && gnlxio_ft_strnstr(line + i.i,
				sep, gnlxio_ft_strlen(sep)))
			i.i += gnlxio_ft_strlen(sep);
		if (line[i.i])
		{
			(i.count)++;
			while (line[i.i] && !gnlxio_ft_strnstr(line + i.i,
					sep, gnlxio_ft_strlen(sep)))
				i.i++;
		}
	}
	return (i.count);
}

/*
Char : Length from 0 to char
*/
static int	ft_strlenc(const char *line, char *sep)
{
	int	i;

	i = -1;
	while (line[++i] && !gnlxio_ft_strnstr(line + i,
			sep, gnlxio_ft_strlen(sep)))
		;
	return (i);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*new_str;
	size_t	i;
	size_t	prelen;

	if (!s)
		return (NULL);
	if (start >= gnlxio_ft_strlen(s))
		return (gnlxio_ft_strdup(""));
	prelen = gnlxio_ft_strlen(s) - (size_t)start;
	if (prelen > len)
		prelen = len;
	new_str = gnlxio_ft_calloc(sizeof(char), prelen + 1);
	if (!new_str)
		return (NULL);
	i = -1;
	while (s[(size_t)start + ++i] && i < len)
		new_str[i] = s[(size_t)start + i];
	new_str[i] = '\0';
	return (new_str);
}

static void	ft_strsbuild(char ***strs, char *line, char *sep)
{
	int	chainlen;
	int	nextsep;
	int	i;

	chainlen = ft_strlench(line, sep);
	*strs = gnlxio_ft_calloc(sizeof(char *), chainlen + 1);
	if (!(*strs))
		return ;
	nextsep = 0;
	i = -1;
	while (++i < chainlen)
	{
		while (*line && gnlxio_ft_strnstr(line, sep, gnlxio_ft_strlen(sep)))
			line += gnlxio_ft_strlen(sep);
		nextsep = ft_strlenc(line, sep);
		(*strs)[i] = ft_substr(line, 0, nextsep);
		if (!(*strs)[i])
			return (ft_free_rlines(strs));
		line += nextsep;
	}
}

char	**gnlxio_ft_split(char *line, char *sep)
{
	char	**strs;
	char	*ldup;

	if (!line)
		return (NULL);
	ldup = gnlxio_ft_strdup(line);
	if (!ldup)
		return (NULL);
	ft_strsbuild(&strs, ldup, sep);
	free(ldup);
	return (strs);
}
