/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 10:49:24 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/14 10:49:26 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
Chains : Number of Chains
*/
static int	ft_strlench(const char *s, char c)
{
	int	i;
	int	t;

	i = -1;
	t = 0;
	while (s[++i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			t++;
	}
	return (t);
}

/*
Char : Length from 0 to char
*/
static int	ft_strlenc(const char *s, char c)
{
	int	i;

	i = -1;
	while (s[++i] && s[i] != c)
		;
	return (i);
}

static void	ft_strsfree(char ***strs, size_t strs_i)
{
	while (strs_i > 0)
		free((*strs)[--strs_i]);
	free(*strs);
	*strs = NULL;
}

static void	ft_strsbuild(char ***strs, char *s, char c)
{
	int	chainlen;
	int	nextc;
	int	cl;

	chainlen = ft_strlench(s, c);
	*strs = ft_calloc(sizeof(char *), chainlen + 1);
	if (!(*strs))
		return (ft_bzero(*strs, 0));
	nextc = 0;
	cl = -1;
	while (++cl < chainlen)
	{
		while (s[0] == c)
			s++;
		nextc = ft_strlenc(s, c);
		(*strs)[cl] = ft_substr(s, 0, nextc);
		if (!(*strs)[cl])
			return (ft_strsfree(strs, cl));
		s += nextc;
	}
}

char	**ft_split(const char *s, char c)
{
	char	**strs;

	if (!s)
		return (NULL);
	ft_strsbuild(&strs, (char *)s, c);
	return (strs);
}
