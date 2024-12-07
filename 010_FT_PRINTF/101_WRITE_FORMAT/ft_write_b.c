/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <kzhen-cl@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 00:07:17 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/30 00:07:20 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

/*
This function works like a converter from an alnum character
to an integer if <type> == 'c', acts like isdigit if
<type> == 'n' and acts like isalnum if <type> == 'a'
*/
int	ft_conv(const char type, const char c)
{
	int	conv;

	conv = 0;
	if (type == 'c')
	{
		conv = -1;
		if (c >= '0' && c <= '9')
			conv = c - '0';
		if (c >= 'a' && c <= 'z')
			conv = c - 'a' + 10;
		if (c >= 'A' && c <= 'Z')
			conv = c - 'A' + 10;
	}
	if (type == 'n')
		conv = (c >= '0' && c <= '9');
	if (type == 'a')
		conv = ((c >= '0' && c <= '9')
				|| (c >= 'a' && c <= 'z')
				|| (c >= 'A' && c <= 'Z'));
	return (conv);
}

static int	from_base(t_params *pa)
{
	size_t	j;
	int		base;

	base = 0;
	j = pa->i;
	if (pa->str[++j] != '[')
		return (-1);
	while (pa->str[++j] && pa->str[j] != ']' && ft_conv('n', pa->str[j]))
		;
	if (pa->str[j] != ']' || j > pa->i + 4 || j < pa->i + 3)
		return (-1);
	pa->i += 2;
	while (pa->i < j)
	{
		base = (base * 10) + (pa->str[pa->i] - '0');
		(pa->i)++;
	}
	return (base);
}

static int	base_after_b(t_params *pa)
{
	size_t	j;
	int		base;

	base = 0;
	j = pa->i;
	if (ft_strlen(pa->str) > j + 2 && ft_conv('n', pa->str[j + 1])
		&& ft_conv('n', pa->str[j + 2]))
	{
		base = 10 * (pa->str[j + 1] - '0') + pa->str[j + 2] - '0';
		pa->i += 2;
	}
	else if (ft_strlen(pa->str) > j + 1 && ft_conv('n', pa->str[j + 1]))
	{
		base = pa->str[j + 1] - '0';
		(pa->i)++;
	}
	return (base);
}

static int	ft_getdec(const char *str, int base)
{
	unsigned long	dec;
	int				len;
	int				c_to_i;
	int				weight;

	if (!str)
		return (0);
	len = ft_strlen(str);
	dec = 0;
	weight = -1;
	while (--len >= 0)
	{
		c_to_i = ft_conv('c', str[len]);
		if (base <= c_to_i || c_to_i < 0)
			return (0);
		dec += c_to_i * ft_pow(base, ++weight);
	}
	return (dec);
}

/*
<str> is the first parameter of ft_printf()
<p_str> is the string to print
If the user does not use ft_printf in a good way
the result may differ
*/
int	ft_write_b(t_params *pa)
{
	size_t	len;
	char	*p_str;
	char	c;
	int		from;
	int		base;

	c = pa->str[pa->i];
	from = from_base(pa);
	base = base_after_b(pa);
	p_str = NULL;
	len = 0;
	if (from != -1 && (from >= 2 && from <= 36))
		from = ft_getdec(va_arg(pa->args, const char *), from);
	else
		from = va_arg(pa->args, unsigned long);
	if (base && (base >= 2 && base <= 36))
		p_str = ft_getbase(from, base, c == 'B');
	if (p_str)
	{
		ft_putstr_fd(p_str, pa->fd);
		len = ft_strlen(p_str);
		free(p_str);
		p_str = NULL;
	}
	return (len);
}
