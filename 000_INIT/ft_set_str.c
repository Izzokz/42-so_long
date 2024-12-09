/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_str.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 14:57:26 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 18:42:29 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	function_free(t_slines *map_data, char *path)
{
	ft_free_slines(map_data);
	if (path)
		free(path);
}

int	ft_get_map_data(t_gobj *game, char *map_name)
{
	char		*path;
	t_slines	map_data;

	path = ft_strjoin("999_GOBJ/maps/", map_name);
	if (!path)
	{
		ft_printf_err("A problem occured (ft_set_str.c:29)", 1);
		return (-1);
	}
	map_data = ft_readfile_split(path, "\n");
	if (invalid_slines(map_data))
	{
		ft_printf_err("Corrupted map_data", 1);
		function_free(&map_data, path);
		return (-1);
	}
	game->str.map = ft_rlines_dup(map_data[0]);
	game->str.map_dep = ft_rlines_dup(map_data[1]);
	ft_rlines_cutendl(&(game->str.map_dep));
	function_free(&map_data, path);
	return (0);
}

int	ft_set_str(t_gobj *game)
{
	t_str	str;

	str.map = NULL;
	str.map_dep = NULL;
	str.msg = ft_readfile_split("999_GOBJ/str/msg.txt", "***----***\n");
	ft_slines_cutendl(&(str.msg));
	if (!(str.msg))
	{
		ft_printf_err("A problem occured (ft_set_str.c:53)", 1);
		return (-1);
	}
	game->str = str;
	return (0);
}
