/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/08 13:59:54 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/08 13:59:55 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	findothocc(const char *s, int c)
{
	int	index;

	index = 0;
	while (index == 0 || s[index - 1] != '\0')
	{
		if (index != 0 && s[index] == (char)c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strrchr(const char *s, int c)
{
	int	index;

	index = 0;
	while (index == 0 || s[index - 1] != '\0')
	{
		if (s[index] == (char)c && !findothocc(&s[index], c))
			return ((char *)&s[index]);
		index++;
	}
	return (NULL);
}
