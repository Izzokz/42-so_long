/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:52:25 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/26 14:52:28 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

static void	put_new_line(char *line, int fd)
{
	gnlxio_ft_putstr_fd(line, fd);
	if (line && (gnlxio_ft_strlen(line) == 0
			|| line[gnlxio_ft_strlen(line) - 1] != '\n'))
		gnlxio_ft_putstr_fd("\n", fd);
}

static int	put_line(char *filename, char *line, int lineno, t_rlines *rlines)
{
	int	i;
	int	fd;

	fd = open(filename, O_WRONLY);
	if (fd < 0)
	{
		perror("GNLXIO:ft_add_line.c:28:open()");
		ft_free_rlines(rlines);
		return (-1);
	}
	ft_fix_lineno(&lineno, ft_rlines_len(*rlines) + 1);
	i = -1;
	while (rlines && (*rlines) && (*rlines)[++i])
	{
		if (i + 1 == lineno)
			put_new_line(line, fd);
		gnlxio_ft_putstr_fd((*rlines)[i], fd);
	}
	if (i + 1 == lineno)
		put_new_line(line, fd);
	ft_free_rlines(rlines);
	close(fd);
	return (1);
}

int	ft_add_line(char *filename, char *line, long long method)
{
	t_rlines	rlines;

	if (!filename)
		return (-1);
	if (method == A_TRUNC)
	{
		if (ft_trunc(filename) == -1)
		{
			perror("GNLXIO:ft_add_line.c:58:ft_trunc()");
			ft_free_rlines(&rlines);
			return (-1);
		}
		method = 1;
	}
	rlines = ft_readfile(filename);
	if (!rlines)
	{
		perror("GNLXIO:ft_add_line.c:66:ft_readfile()");
		return (-1);
	}
	if (method < INT_MIN || method > INT_MAX)
		return (-1);
	return (put_line(filename, line, (int)method, &rlines) == -1);
}
