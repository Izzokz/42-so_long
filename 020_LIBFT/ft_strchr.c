/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 11:00:24 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/08 11:00:27 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (index == 0 || s[index - 1] != '\0')
	{
		if (s[index] == (char)c)
			return ((char *)&s[index]);
		index++;
	}
	return (NULL);
}
