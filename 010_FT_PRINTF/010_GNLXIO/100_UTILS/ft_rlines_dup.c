/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlines_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:07:52 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/23 19:07:55 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

t_rlines	ft_rlines_dup(t_rlines rlines)
{
	t_rlines	new_lines;
	int			len;
	int			i;

	if (!rlines)
		return (NULL);
	len = ft_rlines_len(rlines);
	new_lines = gnlxio_ft_calloc(len + 1, sizeof(char *));
	if (!new_lines)
	{
		perror("GNLXIO:ft_rlines_dup.c:22:gnlxio_ft_calloc()");
		return (NULL);
	}
	i = -1;
	while (rlines[++i])
	{
		new_lines[i] = gnlxio_ft_strdup(rlines[i]);
		if (!new_lines[i])
		{
			perror("GNLXIO:ft_rlines_dup.c:31:gnlxio_ft_calloc()");
			ft_free_rlines(&new_lines);
			return (NULL);
		}
	}
	return (new_lines);
}
