/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_rlines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <kzhen-cl@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:57:47 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/06 12:57:50 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

static int	ft_rlines_count(t_rlines rlines, char *sep)
{
	t_ints	i;
	int		in_chain;

	i.count = 0;
	in_chain = 0;
	i.i = -1;
	while (rlines[++(i.i)])
	{
		if (gnlxio_ft_strcmp(rlines[i.i], sep) != 0)
		{
			if (!in_chain)
			{
				in_chain = 1;
				(i.count)++;
			}
		}
		else
			in_chain = 0;
	}
	return (i.count);
}

static int	ft_add_to_chain(t_slines *split,
	t_rlines rlines, char *sep, t_ints *i)
{
	i->len = 0;
	i->j = i->i - 1;
	while (rlines[++(i->j)] && gnlxio_ft_strcmp(rlines[i->j], sep) != 0)
		(i->len)++;
	if (!(*split)[i->x])
	{
		(*split)[i->x] = gnlxio_ft_calloc(i->len + 1, sizeof(t_rlines));
		if (!(*split)[i->x])
			return (0);
	}
	(*split)[i->x][++(i->y)] = gnlxio_ft_strdup(rlines[i->i]);
	if (!(*split)[i->x][i->y])
		return (0);
	return (1);
}

static int	ft_finalize_chain(t_slines *split, t_ints *i)
{
	if (!split || !(*split))
		return (0);
	if ((*split)[i->x])
	{
		ft_realloc_rlines(&((*split)[i->x]), i->y + 2);
		if (!(*split)[i->x])
			return (0);
		(*split)[i->x][i->y + 1] = NULL;
		i->x++;
		i->y = -1;
	}
	return (1);
}

static t_slines	ft_split_rlines_process(t_slines *split,
	t_rlines rlines, char *sep, t_ints *i)
{
	if (!split || !(*split) || !rlines)
		return (NULL);
	while (rlines[++(i->i)])
	{
		if (gnlxio_ft_strcmp(rlines[i->i], sep) == 0)
		{
			if (!ft_finalize_chain(split, i))
				return (ft_free_slines(split), NULL);
		}
		else if (!ft_add_to_chain(split, rlines, sep, i))
			return (ft_free_slines(split), NULL);
	}
	if (!ft_finalize_chain(split, i))
		return (ft_free_slines(split), NULL);
	return (*split);
}

t_slines	ft_split_rlines(t_rlines rlines, char *sep)
{
	t_slines	split;
	t_ints		i;

	if (invalid_rlines(rlines) || !sep)
		return (NULL);
	i.count = ft_rlines_count(rlines, sep);
	split = gnlxio_ft_calloc(i.count + 1, sizeof(t_rlines));
	if (!split)
		return (NULL);
	split[i.count] = NULL;
	i.x = 0;
	i.y = -1;
	i.i = -1;
	return (ft_split_rlines_process(&split, rlines, sep, &i));
}
