/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 13:54:22 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/15 13:54:24 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <stdlib.h>
#include <time.h>
#include <fcntl.h>

int	ft_random(int max)
{
	struct timespec	seed;

	clock_gettime(0, &seed);
	if (max < 0)
		max *= -1;
	if (max == 0)
		return (1);
	return ((seed.tv_nsec % max) + 1);
}

char	*ft_str_random(char **chain)
{
	int		len;
	char	*output;

	len = 0;
	while (chain[len])
		len++;
	if (len == 0)
		return (NULL);
	output = ft_strdup(chain[ft_random(len) - 1]);
	return (output);
}
