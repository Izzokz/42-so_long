/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:49:41 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 18:36:45 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_img_err(void)
{
	ft_printf("Missing image. Be sure to get all images installed.");
	return (-1);
}

static int	ft_img_init(t_gobj *game)
{
	t_ints	i;

	i.count = 5;
	game->imgs = ft_calloc(i.count + 1, sizeof(void *));
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
	return (i.count);
}

static void	player_init(t_player *player, int plrid)
{
	player->i = 0;
	player->j = 0;
	player->spd = SPEED;
	player->moves = 0;
	player->exit = 'E' + (((plrid + 1) % 2) * ('e' - 'E'));
	player->finish = 0;
}

static void	game_init(t_gobj *game, t_player *p1, char **envp)
{
	int	key_id;

	player_init(p1, 1);
	game->mlx = NULL;
	game->win = NULL;
	game->imgs = NULL;
	game->dmap = NULL;
	game->str = (t_str){NULL, NULL, NULL};
	game->p1 = p1;
	game->player_count = 1;
	game->envp = (char *const *)envp;
	game->pwd = NULL;
	ft_set_pwd(game, envp);
	key_id = -1;
	while (++key_id < 131072)
		game->keys_state[key_id] = 0;
}

int	main(int argc, char **argv, char **envp)
{
	t_gobj		game;
	t_player	p1;

	if (argc < 2)
	{
		ft_printf("No map given. Retry.");
		return (-1);
	}
	game_init(&game, &p1, envp);
	ft_map_parser(&game, argv[1]);
	game.mlx = mlx_init();
	if (!game.mlx)
		ft_end(&game, -1);
	game.win = mlx_new_window(game.mlx, game.width * 32,
			game.height * 32, "SoulM8");
	if (!game.win)
		ft_end(&game, -1);
	if (ft_img_init(&game) < 0)
		ft_end(&game, -1);
	ft_loop_process(&game);
	ft_printf("\n");
	ft_print_stats(&game);
	mlx_loop(game.mlx);
}
