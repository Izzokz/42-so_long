/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/02 09:49:18 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/02 09:49:19 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	call_all(void *ptr, t_params *pa, char *sep)
{
	if (pa->str[pa->i] == 'd' || pa->str[pa->i] == 'i')
		return (ft_process_all_d((int *)ptr, sep, pa->fd));
	if (pa->str[pa->i] == 's')
		return (ft_process_all_s((char **)ptr, sep, pa->fd));
	if (pa->str[pa->i] == 'u')
		return (ft_process_all_u((unsigned int *)ptr, sep, pa->fd));
	if (pa->str[pa->i] == 'p')
		return (ft_process_all_p((unsigned long *)ptr, sep, pa->fd));
	return (0);
}

static int	call_of_duty(void **origin, int depth, t_params *pa, char *sep)
{
	int		j;
	int		len;

	len = 0;
	if (!origin || depth == 0)
		return (0);
	j = -1;
	if (depth > 1)
	{
		while (origin[++j] != NULL)
		{
			len += call_of_duty(origin[j], depth - 1, pa, sep);
			if (origin[j + 1] != NULL && sep)
				len += ft_write_s(sep, pa->fd);
		}
	}
	else
		len += call_all(origin, pa, sep);
	return (len);
}

static char	*get_sep(t_params *pa)
{
	size_t	j;
	size_t	k;
	char	*sep;

	sep = NULL;
	j = pa->i;
	if (pa->str[j] != '[')
		return (sep);
	while (pa->str[++j] && pa->str[j] != ']')
		;
	if (pa->str[j] != ']' || pa->str[j - 1] == '[')
		return (NULL);
	(pa->i)++;
	sep = ft_calloc(j - pa->i + 1, sizeof(char));
	k = 0;
	while (pa->i < j)
	{
		sep[k] = pa->str[pa->i];
		(pa->i)++;
		k++;
	}
	(pa->i)++;
	return (sep);
}

static int	get_rdepth(t_params *pa)
{
	(pa->i)++;
	if (pa->str[pa->i] == '.')
	{
		if (pa->str[pa->i + 1] >= '0' && pa->str[pa->i + 1] <= '9')
		{
			pa->i += 2;
			return (pa->str[pa->i - 1] - '0' + 1);
		}
		else
			return (-1);
	}
	return (0);
}

int	ft_write_all(t_params *pa)
{
	size_t	len;
	char	*sep;
	int		recursive;
	void	*ptr;

	len = 0;
	recursive = get_rdepth(pa);
	if (recursive == -1)
		return (0);
	sep = get_sep(pa);
	ptr = va_arg(pa->args, void *);
	if (!ptr)
		return (0);
	if (recursive)
		len += call_of_duty(ptr, recursive - 1, pa, sep);
	else
		len += call_all(ptr, pa, sep);
	if (sep)
	{
		free(sep);
		sep = NULL;
	}
	return (len);
}
