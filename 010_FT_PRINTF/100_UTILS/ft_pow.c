/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 12:59:14 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/30 12:59:16 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

long	ft_pow(int number, int exp)
{
	long	value;

	if (exp == 0)
		return (1);
	value = number;
	while (--exp)
		value *= number;
	return (value);
}
