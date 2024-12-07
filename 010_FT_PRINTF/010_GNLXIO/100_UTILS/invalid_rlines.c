/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invalid_rlines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <kzhen-cl@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 01:05:58 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/24 01:06:00 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

/*
Zombie means rlines have been malloc'd but are empty
*/
int	zombie_rlines(t_rlines rlines)
{
	return (rlines && !rlines[0]);
}

/*
Invalid means rlines are zombies or NULL
*/
int	invalid_rlines(t_rlines rlines)
{
	return (!rlines || zombie_rlines(rlines));
}

/*
If rlines are zombies, free them
Prefer use invalid version as ft_free_rlines() does not free NULL pointers
*/
int	zombie_rlines_free(t_rlines *rlines)
{
	if (rlines)
	{
		if (zombie_rlines(*rlines))
		{
			ft_free_rlines(rlines);
			return (1);
		}
	}
	return (0);
}

/*
If rlines are invalid, try to free them
*/
int	invalid_rlines_free(t_rlines *rlines)
{
	if (rlines)
	{
		if (invalid_rlines(*rlines))
		{
			ft_free_rlines(rlines);
			return (1);
		}
		return (0);
	}
	return (1);
}
