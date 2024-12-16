/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_imgs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:34:42 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/09 15:06:59 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_load_img(t_gobj *game, char *filename)
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

static int	ft_img_err(void)
{
	ft_printf("Missing image. Be sure to get all images installed.\n");
	return (-1);
}

static int	ft_init_imgs2(t_gobj *game, int count)
{
	if (!ft_load_img(game, "plqy@2.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "3x!T.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "D1n3R0.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "door.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "0Odr.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "SUPER!.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "key.xpm"))
		return (ft_img_err());
	return (count);
}

int	ft_init_imgs(t_gobj *game)
{
	int	count;

	count = 14;
	game->imgs = ft_calloc(count + 1, sizeof(void *));
	if (!game->imgs)
		return (-1);
	if (!ft_load_img(game, "floor.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "wall.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "player1.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "coin.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "exit.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "wqll.xpm"))
		return (ft_img_err());
	if (!ft_load_img(game, "fl00r.xpm"))
		return (ft_img_err());
	return (ft_init_imgs2(game, count));
}
