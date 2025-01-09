/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_mandatory.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 14:42:26 by kzhen-cl          #+#    #+#             */
/*   Updated: 2025/01/05 14:42:27 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_MANDATORY_H
# define SO_LONG_MANDATORY_H

# include "../mlx-linux/mlx.h"
# include "../010_FT_PRINTF/ft_printf.h"
# include "../020_LIBFT/libft.h"
# include <X11/keysym.h>

typedef struct s_player
{
	int	moves;
	int	finish;
	int	i;
	int	j;
	int	coin_count;
}		t_player;

typedef struct s_gobj
{
	void		*mlx;
	void		*win;
	void		**imgs;
	t_rlines	map;
	void		*dmap;
	t_player	*p1;
	int			ticks;
	int			win_i;
	int			win_j;
	int			height;
	int			width;
	int			keys_state[131072];
}		t_gobj;

int		ft_count_coins(t_gobj *game);
int		ft_get_map_data(t_gobj *game, const char *map_name);
int		ft_init_game(t_gobj *game, t_player *p1, const char *map_name);
int		ft_init_imgs(t_gobj *game);
int		ft_loop_process(t_gobj *game);
void	ft_set_player(t_gobj *game);
void	ft_map_parser(t_gobj *game, const char *map_name);
int		is_valid_char(char c);
int		are_valid_walls(t_rlines map);
int		is_rect_map(t_rlines map);
int		is_complete(t_gobj *game);
void	ft_end(t_gobj *game, int exit_id);
int		ft_key_control(t_gobj *game);
void	ft_print_map(t_gobj *game);
void	ft_update_map(t_gobj *game, int i, int j);
void	ft_move_plr_n(t_gobj *game, t_player *plr);
void	ft_move_plr_s(t_gobj *game, t_player *plr);
void	ft_move_plr_e(t_gobj *game, t_player *plr);
void	ft_move_plr_w(t_gobj *game, t_player *plr);
void	ft_exit_area(t_gobj *game, t_player **plr);
void	ft_update_dmap(t_gobj *game, int i, int j);

#endif
