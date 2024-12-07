/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <kzhen-cl@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 23:39:52 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/23 23:39:54 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_lineno(t_params *pa)
{
	size_t	j;
	int		sign;
	int		lineno;

	lineno = 0;
	sign = 1;
	j = pa->i;
	if (pa->str[++j] != '[')
		return (0);
	if (pa->str[j + 1] == '-')
	{
		sign = -sign;
		j++;
	}
	while (pa->str[++j] && pa->str[j] != ']' && ft_conv('n', pa->str[j]))
		;
	if (pa->str[j] != ']' || j < pa->i + 3)
		return (0);
	pa->i += 2;
	while (pa->i < j)
	{
		lineno = (lineno * 10) + (pa->str[pa->i] - '0');
		(pa->i)++;
	}
	return (lineno * sign);
}

static int	ft_write_from_name(t_params *pa)
{
	char	**rlines;
	char	*rline;
	int		lineno;
	int		len;

	lineno = get_lineno(pa);
	if (!lineno && pa->str[pa->i + 1] == '[')
		return (0);
	else if (lineno)
	{
		rline = ft_get_line(va_arg(pa->args, const char *), lineno);
		if (!rline)
			return (0);
		len = ft_write_s(rline, pa->fd);
		free(rline);
	}
	else
	{
		rlines = ft_readfile(va_arg(pa->args, const char *));
		if (invalid_rlines_free(&rlines))
			return (0);
		len = ft_printf_fd("%*s", pa->fd, rlines);
		ft_free_rlines(&rlines);
	}
	return (len);
}

static int	ft_write_line(char **rlines, int lineno, t_params *pa)
{
	char	*rline;
	int		len;

	ft_fix_lineno(&lineno, ft_rlines_len(rlines));
	rline = ft_strdup(rlines[lineno - 1]);
	if (!rline)
		return (0);
	len = ft_write_s(rline, pa->fd);
	free(rline);
	return (len);
}

int	ft_write_file(t_params *pa)
{
	char	**rlines;
	int		lineno;
	int		len;

	if (pa->str[pa->i + 1] == '/')
	{
		(pa->i)++;
		return (ft_write_from_name(pa));
	}
	rlines = ft_readlines(va_arg(pa->args, int));
	if (invalid_rlines_free(&rlines))
		return (0);
	lineno = get_lineno(pa);
	if (!lineno && pa->str[pa->i + 1] == '[')
		len = 0;
	else if (lineno)
		len = ft_write_line(rlines, lineno, pa);
	else
		len = ft_printf_fd("%*s", pa->fd, rlines);
	ft_free_rlines(&rlines);
	return (len);
}
