/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc_rlines.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:12:07 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/26 14:16:30 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

/*
It it fails, it continues to free everything
*/
static void	ft_chainshift(char **dest, char **src)
{
	int	i;
	int	fail;

	if (!dest || !src)
		return ;
	i = -1;
	fail = 0;
	while (src[++i])
	{
		if (!fail)
			dest[i] = gnlxio_ft_strdup(src[i]);
		if (!dest[i])
			fail = 1;
		free(src[i]);
		src[i] = NULL;
	}
	if (src)
		free(src);
	src = NULL;
}

void	ft_realloc_rlines(t_rlines *chain, int nmemb)
{
	int			len;
	t_rlines	temp;

	if (!chain || !(*chain) || nmemb <= 0)
		return ;
	len = -1;
	while ((*chain)[++len])
		;
	temp = gnlxio_ft_calloc(len + nmemb + 1, sizeof(char *));
	if (!temp)
		return ;
	ft_chainshift(temp, *chain);
	*chain = temp;
	(*chain)[len + nmemb] = NULL;
}

static void	ft_rlines_chainshift(t_rlines *dest, t_rlines *src)
{
	int	i;
	int	fail;

	if (!dest || !src)
		return ;
	i = -1;
	fail = 0;
	while (src[++i])
	{
		if (!fail)
			ft_chainshift(&(*dest)[i], &(*src)[i]);
		if (!dest[i])
			fail = 1;
	}
	ft_free_rlines(src);
}

void	ft_realloc_slines(t_slines *chain, int nmemb)
{
	int			len;
	t_slines	temp;

	if (!chain || !(*chain) || nmemb <= 0)
		return ;
	len = -1;
	while ((*chain)[++len])
		;
	temp = gnlxio_ft_calloc(len + nmemb + 1, sizeof(t_rlines));
	if (!temp)
		return ;
	ft_rlines_chainshift(temp, *chain);
	ft_free_slines(chain);
	*chain = temp;
	(*chain)[len + nmemb] = NULL;
}
