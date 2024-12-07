/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 18:51:19 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/07 17:35:00 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	start_escape(const char *str, int *index)
{
	while (str[*index] == ' '
		|| (str[*index] >= 9 && str[*index] <= 13))
		*index += 1;
	return ;
}

int	ft_atoi(const char *str)
{
	int	number;
	int	index;
	int	sign;

	number = 0;
	index = 0;
	sign = 1;
	start_escape(str, &index);
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign *= -1;
		index++;
	}
	while (str[index])
	{
		if (ft_isdigit(str[index]))
			number = number * 10 + str[index] - 48;
		else
			break ;
		index++;
	}
	return (number * sign);
}
