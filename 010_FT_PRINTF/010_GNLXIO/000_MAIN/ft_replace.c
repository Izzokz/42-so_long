/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 15:47:26 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/22 15:47:27 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

static int	ft_realloc(char **line, int len)
{
	char	*temp;
	int		i;
	int		current_len;
	int		new_len;

	if (!line || !(*line) || len == 0)
		return (0);
	current_len = gnlxio_ft_strlen(*line);
	new_len = current_len + len;
	temp = gnlxio_ft_calloc(new_len + 2, sizeof(char));
	if (!temp)
	{
		perror("GNLXIO:ft_replace.c:26:gnlxio_ft_calloc()");
		return (0);
	}
	i = -1;
	while (++i < new_len && i < current_len)
		temp[i] = (*line)[i];
	free(*line);
	*line = temp;
	if (new_len < 0)
		(*line)[new_len] = '\0';
	return (len);
}

static void	ft_expand_line(char **rline, char *to, t_ints *ints)
{
	ints->i += ints->len1 - 1;
	ints->k = -1;
	while (++(ints->k) < ints->len2)
		(*rline)[++(ints->j)] = to[ints->k];
	(ints->count)++;
}

static void	ft_replace(char **rline, char *from, char *to, t_ints *ints)
{
	char	*temp;

	temp = gnlxio_ft_strdup(*rline);
	if (!temp)
		return ;
	while (temp[++(ints->i)] && temp[ints->i] != '\n')
	{
		if (gnlxio_ft_strnstr((temp + ints->i), from, ints->len1))
		{
			ft_realloc(rline, ints->len2 - ints->len1);
			ft_expand_line(rline, to, ints);
		}
		else
		{
			ft_realloc(rline, 1);
			(*rline)[++(ints->j)] = temp[ints->i];
		}
	}
	ft_realloc(rline, 2);
	(*rline)[++(ints->j)] = '\n';
	(*rline)[++(ints->j)] = '\0';
	free(temp);
}

int	ft_replace_rlines(t_rlines *rlines, char *from, char *to)
{
	int		i;
	t_ints	ints;

	if (!(*rlines) || !from || !gnlxio_ft_strlen(from)
		|| !gnlxio_ft_strcmp(from, to))
		return (-1);
	if (!to)
		to = "";
	ints.count = 0;
	ints.len1 = gnlxio_ft_strlen(from);
	ints.len2 = gnlxio_ft_strlen(to);
	i = -1;
	while ((*rlines)[++i])
	{
		ints.i = -1;
		ints.j = -1;
		ft_replace(&(*rlines)[i], from, to, &ints);
	}
	return (ints.count);
}

int	ft_replace_file(const char *filename, char *from, char *to)
{
	t_rlines	rlines;
	int			count;

	if (!from || !gnlxio_ft_strlen(from) || !gnlxio_ft_strcmp(from, to))
		return (-1);
	rlines = ft_readfile(filename);
	if (!rlines)
		return (-1);
	count = ft_replace_rlines(&rlines, from, to);
	if (count > 0)
		ft_rewrite_file(filename, rlines);
	ft_free_rlines(&rlines);
	return (count);
}
