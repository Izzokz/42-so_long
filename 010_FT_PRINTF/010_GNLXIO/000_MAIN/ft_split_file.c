/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <kzhen-cl@student.42angouleme.fr  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:59:58 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/06 19:59:59 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

static int	ft_itoalen(int *nbr, int *sign)
{
	int	i;
	int	temp_nbr;

	if (*nbr < 0)
	{
		*nbr = -(*nbr);
		*sign = 1;
	}
	i = 1;
	temp_nbr = *nbr;
	while (temp_nbr > 9)
	{
		temp_nbr /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa(int nbr)
{
	char	*str;
	int		sign;
	int		len;

	if (nbr == -2147483648)
		return (gnlxio_ft_strdup("-2147483648"));
	sign = 0;
	len = ft_itoalen(&nbr, &sign);
	str = gnlxio_ft_calloc(len + 1, sizeof(char));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (nbr > 9)
	{
		str[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	str[--len] = nbr + '0';
	if (sign)
		str[--len] = '-';
	return (str);
}

static void	free_all(t_slines *slines,
	char **filename_prefix, char **new_filename)
{
	ft_free_slines(slines);
	if (filename_prefix && *filename_prefix)
	{
		free(*filename_prefix);
		*filename_prefix = NULL;
	}
	if (new_filename && *new_filename)
	{
		free(*new_filename);
		*new_filename = NULL;
	}
}

static int	split_loop(char **filename_prefix, t_slines *slines)
{
	char	*new_filename;
	int		i;

	i = -1;
	while ((*slines)[++i])
	{
		new_filename = gnlxio_ft_strjoinfree(&(char *){ft_itoa(i)},
				&(char *){gnlxio_ft_strdup(*filename_prefix)});
		if (!new_filename)
		{
			perror("GNLXIO:ft_split_file.c:70:gnlxio_ft_strjoinfree()");
			break ;
		}
		if (ft_gen_file(new_filename, "0744") == -1)
		{
			perror("GNLXIO:ft_split_file.c:77:ft_gen_file()");
			break ;
		}
		ft_rewrite_file(new_filename, (*slines)[i]);
		free_all(NULL, NULL, &new_filename);
	}
	free_all(slines, filename_prefix, &new_filename);
	return (i);
}

int	ft_split_file(const char *filename, char *sep)
{
	t_slines	slines;
	char		*prefix;

	slines = ft_readfile_split(filename, sep);
	if (invalid_slines_free(&slines))
	{
		perror("GNLXIO:ft_split_file.c:94:ft_readfile_split()");
		return (0);
	}
	prefix = gnlxio_ft_strjoinfree(&(char *){gnlxio_ft_strdup("_spl_")},
			&(char *){gnlxio_ft_strdup(filename)});
	if (!prefix)
	{
		perror("GNLXIO:ft_split_file.c:100:gnlxio_ft_strjoinfree()");
		ft_free_slines(&slines);
		return (0);
	}
	return (split_loop(&prefix, &slines));
}
