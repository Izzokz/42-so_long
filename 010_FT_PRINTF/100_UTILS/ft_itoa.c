/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 12:15:20 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/14 12:15:21 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_itoalen(int *n, int *sign)
{
	int	i;
	int	temp_n;

	if (*n < 0)
	{
		*n *= -1;
		*sign += 1;
	}
	i = 1;
	temp_n = *n;
	while (temp_n > 9)
	{
		temp_n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = 0;
	i = ft_itoalen(&n, &sign) + sign;
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[i] = '\0';
	while (n > 9)
	{
		str[--i] = n % 10 + '0';
		n /= 10;
	}
	str[--i] = n + '0';
	if (sign)
		str[--i] = '-';
	return (str);
}
