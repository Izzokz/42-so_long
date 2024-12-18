/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_rlines.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:50:13 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/18 17:00:03 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

static int	ft_strcmp(char	*string1, char *string2)
{
	int	index;

	index = 0;
	while (string1[index] == string2[index])
	{
		if ((string1[index] == '\0' && string2[index] == '\0')
			|| (string1[index] != string2[index]))
			break ;
		index ++;
	}
	return (string1[index] - string2[index]);
}

int	in_rlines(char *line, t_rlines rlines)
{
	int	i;

	i = -1;
	while (rlines[++i])
		if (ft_strcmp(line, rlines[i]) == 0)
			return (1);
	return (0);
}

int	in_slines(char *line, t_slines slines)
{
	int	i;

	i = -1;
	while (slines[++i])
		if (in_rlines(line, slines[i]))
			return (1);
	return (0);
}

int	in_file(char *line, const char *filename)
{
	t_rlines	rlines;
	int			found;

	rlines = ft_readfile(filename);
	if (!rlines)
		return (-1);
	found = in_rlines(line, rlines);
	ft_free_rlines(&rlines);
	return (found);
}
