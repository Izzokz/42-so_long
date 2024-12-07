/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rlines_cutendl.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 19:30:11 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/23 19:30:47 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

void	ft_rline_cutendl(t_rlines rline)
{
	int	len;

	len = gnlxio_ft_strlen(*rline);
	if (len == 0)
		;
	else if ((*rline)[len - 1] == '\n')
		(*rline)[len - 1] = '\0';
}

void	ft_rlines_cutendl(t_rlines *rlines)
{
	t_ints	ints;

	if (!rlines || !(*rlines))
		return ;
	ints.i = -1;
	while ((*rlines)[++(ints.i)])
		ft_rline_cutendl(&((*rlines)[ints.i]));
}

void	ft_slines_cutendl(t_slines *slines)
{
	t_ints	i;

	if (!slines || !(*slines))
		return ;
	i.i = -1;
	while ((*slines)[++(i.i)])
		ft_rlines_cutendl(&((*slines)[i.i]));
}
