/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 16:49:56 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/12 16:49:57 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx-linux/mlx.h"
# include "010_FT_PRINTF/ft_printf.h"
# include "020_LIBFT/libft.h"
# include "030_FT_RANDOM/ft_random.h"
# include "so_long_gobj.h"
# include <X11/keysym.h>

float	ft_delta_time(void);
int		is_valid_move(t_gobj *game, int i, int j);
int		is_valid_char(char c);
int		ft_playable_p1(t_rlines map, int i, int j);
int		ft_playable_p2(t_rlines map, int i, int j);
char	ft_two_players_manager(t_rlines map);
int		are_valid_walls(t_rlines map);
int		is_rect_map(t_rlines map);
int		ft_init_imgs(t_gobj *game);
int		ft_init_window(t_gobj *game);
void	ft_init_player(t_player *player, int plrid);
int		ft_init_game(t_gobj *game, t_player *p1, t_player *p2, char *map_name);
void	ft_print_stats(t_gobj *game);
int		ft_get_map_data(t_gobj *game, char *map_name);
int		ft_set_str(t_gobj *game, char *map_name);
void	ft_quit_game(t_gobj *game);
void	ft_exit_area(t_gobj *game, t_player **player);
void	ft_free_enemies(t_enemy ***enemies);
int		is_complete(t_gobj *game);
int		ft_count_coins(t_gobj *game, char coin_id);
int		ft_collect(t_gobj *game, int pi, int pj);
int		ft_collect2(t_gobj *game, int pi, int pj);
int		ft_collect_super(t_gobj *game, int pi, int pj);
int		ft_collect_key(t_gobj *game, int pi, int pj);
void	ft_super(t_gobj *gm, t_player *plr);
void	ft_unlock_player(t_gobj *game, t_player *plr);
void	ft_move_plr_n(t_gobj *game, t_player *plr);
void	ft_move_plr_s(t_gobj *game, t_player *plr);
void	ft_move_plr_w(t_gobj *game, t_player *plr);
void	ft_move_plr_e(t_gobj *game, t_player *plr);
void	ft_paint_floor(t_gobj *game, t_player *plr);
void	ft_move_enemies(t_gobj *game);
int		ft_merge_from(t_gobj *game, t_enemy *ene, int id);
void	ft_set_players(t_gobj *game);
void	ft_set_enemies(t_gobj *game);
int		ft_key_control(t_gobj *game);
int		ft_loop_process(t_gobj *game);
int		ft_updated_window_re_print(t_gobj *game);
void	ft_screen_form(t_gobj *game);
void	ft_change_screen_form(t_gobj *game);
void	ft_copy_to_dmap(t_gobj *game, void *img, int i, int j);
void	ft_print_doors(t_gobj *game);
void	ft_print_entities(t_gobj *game);
void	ft_print_map(t_gobj *game);
void	ft_update_dmap(t_gobj *game, int i, int j);
void	ft_update_tile(t_gobj *game, int i, int j);
void	ft_free_gobj(t_gobj *game);
void	ft_end(t_gobj *game, int exit_id);
void	ft_map_parser(t_gobj *game, char *map_name);
void	ft_restart(t_gobj *game, int retry);

#endif
