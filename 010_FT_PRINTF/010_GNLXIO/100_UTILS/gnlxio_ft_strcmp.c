/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnlxio_ft_strcmp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 12:30:13 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/23 12:30:15 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

int	gnlxio_ft_strcmp(char	*string1, char *string2)
{
	int	index;

	index = 0;
	while (string1[index] == string2[index])
	{
		if ((string1[index] == '\0' && string2[index] == '\0')
			|| (string1[index] != string2[index]))
			break ;
		index++;
	}
	return (string1[index] - string2[index]);
}
