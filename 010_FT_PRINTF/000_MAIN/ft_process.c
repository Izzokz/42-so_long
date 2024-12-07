/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_process.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 15:08:43 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/17 15:08:44 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	is_flag(const char *flag, t_params *pa)
{
	size_t	k;
	size_t	init;

	init = pa->i;
	k = 0;
	while (pa->str[pa->i] && flag[k]
		&& pa->str[pa->i] == flag[k])
	{
		(pa->i)++;
		k++;
	}
	if (!flag[k] && pa->str[--(pa->i)] == flag[k - 1])
		return (1);
	pa->i = init;
	return (0);
}

static int	do_write(t_params *pa)
{
	if (pa->str[pa->i] == '*')
		return (ft_write_all(pa));
	if (is_flag("f#", pa))
		return (ft_write_file(pa));
	if (is_flag("_0", pa))
		return (ft_write_bool(va_arg(pa->args, int), 0, pa->fd));
	if (is_flag("_1", pa))
		return (ft_write_bool(va_arg(pa->args, int), 1, pa->fd));
	if (pa->str[pa->i] == 'b' || pa->str[pa->i] == 'B')
		return (ft_write_b(pa));
	if (pa->str[pa->i] == 'c')
		return (ft_write_c((char)va_arg(pa->args, int), pa->fd));
	if (pa->str[pa->i] == 's')
		return (ft_write_s(va_arg(pa->args, char *), pa->fd));
	if (pa->str[pa->i] == 'i' || pa->str[pa->i] == 'd')
		return (ft_write_d(va_arg(pa->args, int), pa->fd));
	if (pa->str[pa->i] == 'x')
		return (ft_write_x(va_arg(pa->args, int), 0, pa->fd));
	if (pa->str[pa->i] == 'X')
		return (ft_write_x(va_arg(pa->args, int), 1, pa->fd));
	if (pa->str[pa->i] == 'p')
		return (ft_write_p(va_arg(pa->args, unsigned long), pa->fd));
	if (pa->str[pa->i] == 'u')
		return (ft_write_u(va_arg(pa->args, unsigned int), pa->fd));
	return (write(pa->fd, "%", 1));
}

int	ft_process(t_params *pa)
{
	size_t	len;
	size_t	temp_len;
	size_t	err;

	len = 0;
	err = 0;
	while (pa->str[++(pa->i)])
	{
		if (pa->str[pa->i] == '%')
		{
			(pa->i)++;
			temp_len = do_write(pa);
			if (!temp_len)
				err = 1;
			len += temp_len;
		}
		else
			len += write(pa->fd, &(pa->str[pa->i]), 1);
	}
	va_end(pa->args);
	if (err)
		return (-1);
	return (len);
}
