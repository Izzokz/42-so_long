/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delta_time.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:53:34 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/05 15:53:36 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <time.h>

float	ft_delta_time(void)
{
	static struct timespec	last_time = {0, 0};
	struct timespec			current_time;
	float					delta;

	clock_gettime(CLOCK_MONOTONIC, &current_time);
	delta = (current_time.tv_sec - last_time.tv_sec)
		+ (current_time.tv_nsec - last_time.tv_nsec) / 1000000000.0f;
	if (delta < 0)
		delta += 1.0f;
	if (delta > 0.1f)
		delta = 0.1f;
	last_time = current_time;
	return (delta);
}
