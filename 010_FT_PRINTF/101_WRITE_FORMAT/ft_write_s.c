/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_s.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:55:25 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/17 15:55:26 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_write_c(char value, int fd)
{
	ft_putchar_fd(value, fd);
	return (1);
}

int	ft_write_s(char *value, int fd)
{
	if (!value)
	{
		ft_putstr_fd("(null)", fd);
		return (6);
	}
	ft_putstr_fd(value, fd);
	return (ft_strlen(value));
}
