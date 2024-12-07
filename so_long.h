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
void	ft_print_stats(t_gobj *game);
int		ft_get_map_data(t_gobj *game, char *map_name);
int		ft_set_str(t_gobj *game);
int		ft_set_pwd(t_gobj *game, char **envp);
void	ft_quit_game(t_gobj *game);
void	ft_exit_area(t_gobj *game, t_player **player);
int		is_complete(t_gobj *game);
int		ft_count_coins(t_gobj *game, char coin_id);
int		ft_collect(t_gobj *game, int pi, int pj);
void	ft_move_player_n(t_gobj *game);
void	ft_move_player_s(t_gobj *game);
void	ft_move_player_w(t_gobj *game);
void	ft_move_player_e(t_gobj *game);
void	ft_set_player(t_gobj *game);
int		ft_key_control(t_gobj *game);
int		ft_loop_process(t_gobj *game);
int		ft_load_img(t_gobj *game, char *filename);
void	ft_print_map(t_gobj *game);
void	ft_free_gobj(t_gobj *game);
void	ft_end(t_gobj *game, int exit_id);
void	ft_map_parser(t_gobj *game, char *map_name);
void	ft_restart(t_gobj *game);

#endif
