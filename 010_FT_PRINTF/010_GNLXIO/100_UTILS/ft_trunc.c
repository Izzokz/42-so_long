/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:44:51 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/26 13:44:54 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

int	ft_trunc(char *filename)
{
	int	fd;

	fd = open(filename, O_TRUNC | O_WRONLY);
	if (fd < 0)
	{
		perror("GNLXIO:ft_trunc.c:19:open()");
		return (-1);
	}
	close(fd);
	return (1);
}
