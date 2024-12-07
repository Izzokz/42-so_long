/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process_all.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 10:26:58 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/02 10:27:00 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_process_all_s(char **chain, char *sep, int fd)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (chain[++i])
	{
		len += ft_write_s(chain[i], fd);
		if (chain[i + 1] && sep)
			len += ft_write_s(sep, fd);
	}
	return (len);
}

int	ft_process_all_d(int *array, char *sep, int fd)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (array[++i])
	{
		len += ft_write_d(array[i], fd);
		if (array[i + 1] && sep)
			len += ft_write_s(sep, fd);
	}
	return (len);
}

int	ft_process_all_u(unsigned int *array, char *sep, int fd)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (array[++i])
	{
		len += ft_write_u(array[i], fd);
		if (array[i + 1] && sep)
			len += ft_write_s(sep, fd);
	}
	return (len);
}

int	ft_process_all_p(unsigned long *ptr, char *sep, int fd)
{
	int	i;
	int	len;

	i = -1;
	len = 0;
	while (ptr[++i])
	{
		len += ft_write_p(ptr[i], fd);
		if (ptr[i + 1] && sep)
			len += ft_write_s(sep, fd);
	}
	return (len);
}
