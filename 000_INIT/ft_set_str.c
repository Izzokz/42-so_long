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

static t_rlines	redirect_map(t_rlines map_dep)
{
	if (!map_dep)
		return (NULL);
	ft_rlines_cutendl(&map_dep);
	if (!map_dep)
		return (NULL);
	if (in_rlines("NONE", map_dep))
		return (NULL);
	return (ft_rlines_dup(map_dep));
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
	game->str.map_dep = redirect_map(map_data[1]);
	if (map_data[1])
		ft_set_rules(game, map_data[2]);
	ft_rlines_cutendl(&(game->str.map_dep));
	function_free(&map_data, path);
	return (0);
}

int	ft_set_str(t_gobj *game, char *map_name)
{
	t_str	str;

	if (game->stage == 0 && game->retry == 0)
	{
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
	}
	game->current_map = ft_strdup(map_name);
	if (!(game->current_map))
	{
		ft_printf_err("A problem occured (ft_set_str.c:61)", 1);
		return (-1);
	}
	return (0);
}
