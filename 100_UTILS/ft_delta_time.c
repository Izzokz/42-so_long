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
#include <stdio.h>

char	ft_fps_match(void)
{
	static int	tick_counter = 0;
	static int	ticks_per_frame = 0;

	ticks_per_frame = 350 / 60;
	tick_counter++;
	if (tick_counter >= ticks_per_frame)
	{
		tick_counter = 0;
		return (1);
	}
	return (0);
}

char	ft_speed_match_process(void)
{
	static struct timespec	last_time = {0, 0};
	struct timespec			current_time;
	float					deltaxtime[2];

	deltaxtime[1] = 1.0f / 350;
	clock_gettime(CLOCK_MONOTONIC, &current_time);
	deltaxtime[0] = (current_time.tv_sec - last_time.tv_sec)
		+ (current_time.tv_nsec - last_time.tv_nsec) / 1000000000.0f;
	if (deltaxtime[0] >= deltaxtime[1])
	{
		last_time = current_time;
		return (1);
	}
	return (0);
}
