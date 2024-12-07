/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fix_lineno.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 11:26:37 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/19 11:26:39 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

/*
Behaviour :
	If <lineno> is greater than the number of lines
	of the current file or smaller than 0,
	it will loop until it is valid.
	If <len> equals 0, <lineno> won't be valid anymore
Example :
	ft_fix_lineno(5, 3) >>> 2
	ft_fix_lineno(9, 3) >>> 3
	ft_fix_lineno(-1, 3) >>> 3
	ft_fix_lineno(-3, 3) >>> 1
	ft_fix_lineno(8, 0) >>> 0
*/
void	ft_fix_lineno(int *lineno, int len)
{
	if (!len)
	{
		*lineno = 0;
		return ;
	}
	if (*lineno < 0)
		*lineno += 1;
	while (*lineno > len || *lineno <= 0)
	{
		if (*lineno > len)
			*lineno = *lineno - len;
		if (*lineno <= 0)
			*lineno += len;
	}
	return ;
}
