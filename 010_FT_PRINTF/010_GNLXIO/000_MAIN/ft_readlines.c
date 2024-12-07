/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readlines.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:01:58 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/15 15:01:59 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

t_rlines	ft_readlines(int fd)
{
	t_rlines	lines;
	char		*line;
	int			i;

	lines = gnlxio_ft_calloc(2, sizeof(char *));
	if (!lines)
		return (NULL);
	line = get_next_line(fd);
	i = -1;
	while (line)
	{
		lines[++i] = gnlxio_ft_strdup(line);
		ft_realloc_rlines(&lines, 1);
		if (invalid_rlines_free(&lines) == -1)
		{
			perror("GNLXIO:ft_readlines.c:29:ft_realloc_rlines()");
			return (NULL);
		}
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	return (lines);
}
