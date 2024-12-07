/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_slines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <kzhen-cl@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 20:13:43 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/06 20:13:46 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

int	zombie_slines(t_slines slines)
{
	return (slines && (!slines[0] || zombie_rlines(slines[0])));
}

int	invalid_slines(t_slines slines)
{
	return (!slines || zombie_slines(slines));
}

int	zombie_slines_free(t_slines *slines)
{
	if (slines)
	{
		if (zombie_slines(*slines))
		{
			ft_free_slines(slines);
			return (1);
		}
	}
	return (0);
}

int	invalid_slines_free(t_slines *slines)
{
	if (slines)
	{
		if (invalid_slines(*slines))
		{
			ft_free_slines(slines);
			return (1);
		}
		return (0);
	}
	return (1);
}
