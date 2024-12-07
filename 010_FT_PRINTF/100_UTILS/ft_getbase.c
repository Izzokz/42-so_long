/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getbase.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 16:35:28 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/30 00:07:32 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static void	init_len(unsigned long nbr, int base, int *len)
{
	if (nbr > 0)
		init_len(nbr / base, base, len);
	if (nbr / base == 0 && nbr % base == 0)
		return ;
	*len += 1;
	return ;
}

static void	setchar(char **str, unsigned long nbr, int up)
{
	char	nbr_to_char;

	nbr_to_char = nbr + '0';
	if (nbr > 9)
	{
		if (up)
			nbr_to_char = nbr + 'A' - 10;
		else
			nbr_to_char = nbr + 'a' - 10;
	}
	(*str)[ft_strlen(*str)] = nbr_to_char;
	return ;
}

static void	recursive_core(char **str, unsigned long nbr, int base, int up)
{
	if (nbr >= (unsigned long)base)
		recursive_core(str, nbr / base, base, up);
	setchar(str, nbr % base, up);
	return ;
}

char	*ft_getbase(unsigned long nbr, int base, int up)
{
	int		len;
	char	*str;

	if (!nbr)
	{
		str = ft_calloc(2, sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '0';
		return (str);
	}
	len = 0;
	init_len(nbr, base, &len);
	str = ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	recursive_core(&str, nbr, base, up);
	return (str);
}
