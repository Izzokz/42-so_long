/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 15:28:12 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/09 15:28:13 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	ft_init_player(t_player *player, int plrid)
{
	player->i = 0;
	player->j = 0;
	player->spd = SPEED;
	player->moves = 0;
	player->exit = 'E' + (((plrid + 1) % 2) * ('#' - 'E'));
	if (plrid == 2)
		player->finish = -2;
	else
		player->finish = 0;
}

static void	ft_set_keys_off(t_gobj *game)
{
	game->keys_state[XK_Escape] = 0;
	game->keys_state[XK_w] = 0;
	game->keys_state[XK_a] = 0;
	game->keys_state[XK_s] = 0;
	game->keys_state[XK_d] = 0;
	game->keys_state[XK_Up] = 0;
	game->keys_state[XK_Down] = 0;
	game->keys_state[XK_Right] = 0;
	game->keys_state[XK_Left] = 0;
	game->keys_state[XK_Control_L] = 0;
	game->keys_state[XK_r] = 0;
}

static void	ft_init_gobj(t_gobj *game, t_player *p1,
	t_player *p2, char *map_name)
{
	ft_init_player(p1, 1);
	ft_init_player(p2, 2);
	if (game->stage == 0 && game->retry == 0)
	{
		game->p1 = p1;
		game->p2 = p2;
		game->win = NULL;
		game->imgs = NULL;
		game->dmap = NULL;
		game->current_map = NULL;
	}
	else
	{
		mlx_destroy_image(game->mlx, game->dmap);
		mlx_destroy_window(game->mlx, game->win);
		game->win = NULL;
		game->dmap = NULL;
		free(game->current_map);
		game->current_map = NULL;
		ft_free_rlines(&(game->str.map));
		ft_free_rlines(&(game->str.map_dep));
	}
	if (ft_set_str(game, map_name) == -1)
		ft_end(game, -1);
}

static void	exit_if_not_ber(t_gobj *game, char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (len <= 4 || map_name[len - 1] != 'r'
		|| map_name[len - 2] != 'e' || map_name[len - 3] != 'b'
		|| map_name[len - 4] != '.')
	{
		ft_printf("I do not think %s is a valid map name...\n", map_name);
		if (game->stage > 0)
		{
			free(game->str.next_map);
			game->str.next_map = NULL;
		}
		ft_end(game, 0);
	}
}

int	ft_init_game(t_gobj *game, t_player *p1, t_player *p2, char *map_name)
{
	game->loaded = 0;
	ft_set_keys_off(game);
	ft_init_gobj(game, p1, p2, map_name);
	exit_if_not_ber(game, map_name);
	if (!game->imgs)
		if (ft_init_imgs(game) == -1)
			return (-1);
	ft_map_parser(game, map_name);
	game->player_count = 1 + (game->p2->finish == 0);
	if (!game || !game->p1 || !game->imgs || !game->height || !game->width
		|| invalid_rlines(game->str.map) || invalid_slines(game->str.msg)
		|| ft_init_window(game) == -1 || !game->p1->coin_count)
		return (-1);
	game->loaded = 1;
	ft_print_map(game);
	ft_loop_process(game);
	ft_printf("Stage %d >>> %s\n", game->stage, map_name);
	ft_print_stats(game);
	if (game->stage > 0 || game->retry > 0)
	{
		free(game->str.next_map);
		game->str.next_map = NULL;
	}
	mlx_loop(game->mlx);
	return (0);
}
