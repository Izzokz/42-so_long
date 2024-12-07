/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_restart.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:02:30 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 22:02:31 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	next_map_err(t_gobj *game, char ***next_map)
{
	ft_printf_err("Sorry we had issue generating another map.", 1);
	ft_free_rlines(next_map);
	ft_end(game, -1);
}

static char	*ft_get_path_exe(t_gobj *game)
{
	char	*path;

	path = ft_strdup(game->pwd);
	if (!path)
		return (NULL);
	path = gnlxio_ft_strjoinfree(&path, &(char *){ft_strdup("/so_long")});
	return (path);
}

static void	launch_new_prog(char **next_map, t_gobj *game)
{
	int		pid;

	pid = fork();
	if (pid < 0)
	{
		ft_printf_err("Sorry we had issue starting a new progrgam", 1);
		ft_end(NULL, -1);
	}
	if (pid == 0)
	{
		execve(next_map[0], next_map, game->envp);
		ft_free_rlines(&next_map);
		ft_end(game, -1);
	}
}

void	ft_restart(t_gobj *game)
{
	char	**next_map;

	if (!(game->str.map_dep))
		ft_end(game, 0);
	next_map = ft_calloc(3, sizeof(char *));
	if (!next_map)
		next_map_err(game, NULL);
	next_map[0] = ft_get_path_exe(game);
	if (!(next_map[0]))
		next_map_err(game, &next_map);
	next_map[1] = ft_str_random(game->str.map_dep);
	if (!(next_map[1]))
		next_map_err(game, &next_map);
	launch_new_prog(next_map, game);
	ft_free_rlines(&next_map);
	ft_end(game, 0);
}
