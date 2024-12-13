/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_gobj.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 10:54:31 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 18:35:03 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_GOBJ_H
# define SO_LONG_GOBJ_H

# ifndef SPEED
#  define SPEED 1.0f
# endif

# ifndef FPS // Force Player Speed
#  define FPS 220.0f
# endif

# ifndef OWLINE // Over Write Line
#  define OWLINE "\r                                                         \r"
# endif

typedef struct s_player
{
	int		moves;
	int		finish;
	float	spd;
	int		i;
	int		j;
	int		coin_count;
	char	exit;
}		t_player;

typedef struct s_str
{
	t_slines	msg;
	t_rlines	map;
	t_rlines	map_dep;
	char		*next_map;
}		t_str;

typedef struct s_gobj
{
	void		*mlx;
	void		*win;
	void		**imgs;
	void		*screen_form;
	char		*current_map;
	t_str		str;
	void		*dmap;
	t_player	*p1;
	t_player	*p2;
	int			height;
	int			width;
	int			keys_state[131072];
	int			player_count;
	int			stage;
	int			loaded;
	int			retry;
	int			win_i;
	int			win_j;
}		t_gobj;

#endif
