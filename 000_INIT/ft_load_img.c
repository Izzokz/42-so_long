/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_img.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:34:42 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/12 16:34:43 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_load_img(t_gobj *game, char *filename)
{
	char	*path;
	void	*img;
	t_ints	i;

	path = ft_strjoin("999_GOBJ/img/", filename);
	if (!path)
	{
		ft_printf_err("A problem occured", 1);
		return (-1);
	}
	img = mlx_xpm_file_to_image(game->mlx, path, &(i.x), &(i.y));
	free(path);
	i.i = -1;
	while (game->imgs[++(i.i)])
		;
	game->imgs[i.i] = img;
	return (game->imgs[i.i] != NULL);
}
