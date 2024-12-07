/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rewrite_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 13:10:09 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/16 13:25:41 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

int	ft_rewrite_file(const char *filename, t_rlines lines)
{
	int	fd;
	int	i;

	if (!filename)
		return (-1);
	fd = open(filename, O_WRONLY | O_TRUNC);
	if (fd < 0)
	{
		perror("GNLXIO:ft_rewrite_file.c:22:open()");
		return (-1);
	}
	i = -1;
	while (lines[++i])
		gnlxio_ft_putstr_fd(lines[i], fd);
	close(fd);
	return (i);
}
