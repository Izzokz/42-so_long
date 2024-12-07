/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gen_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 12:09:24 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/26 12:09:25 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

static int	usr_perm(char *perm)
{
	if (perm[1] == '7')
		return (S_IRWXU);
	if (perm[1] == '4')
		return (S_IRUSR);
	if (perm[1] == '2')
		return (S_IWUSR);
	if (perm[1] == '1')
		return (S_IXUSR);
	return (-1);
}

static int	grp_perm(char *perm)
{
	if (perm[2] == '7')
		return (S_IRWXG);
	if (perm[2] == '4')
		return (S_IRGRP);
	if (perm[2] == '2')
		return (S_IWGRP);
	if (perm[2] == '1')
		return (S_IXGRP);
	return (-1);
}

static int	oth_perm(char *perm)
{
	if (perm[3] == '7')
		return (S_IRWXO);
	if (perm[3] == '4')
		return (S_IROTH);
	if (perm[3] == '2')
		return (S_IWOTH);
	if (perm[3] == '1')
		return (S_IXOTH);
	return (-1);
}

int	ft_gen_file(char *filename, char *perm)
{
	int	fd;
	int	usr;
	int	grp;
	int	oth;

	if (gnlxio_ft_strlen(perm) != 4)
		return (-1);
	usr = usr_perm(perm);
	grp = grp_perm(perm);
	oth = oth_perm(perm);
	if (usr == -1 || grp == -1 || oth == -1)
		return (-1);
	fd = open(filename, O_CREAT, oth | grp | usr);
	if (fd < 0)
	{
		perror("GNLXIO:ft_gen_file.c:19:open()");
		return (-1);
	}
	close(fd);
	return (1);
}
