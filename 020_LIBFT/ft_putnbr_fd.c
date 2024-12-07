/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 16:33:12 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/14 16:33:13 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int nbr, int fd)
{
	char	to_print;

	if (nbr == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (nbr < 0)
	{
		nbr *= -1;
		write(fd, "-", 1);
	}
	if (nbr > 9)
	{
		ft_putnbr_fd(nbr / 10, fd);
	}
	to_print = (nbr % 10) + '0';
	write(fd, &to_print, 1);
}
