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

# ifndef FPS
#  define FPS 220.0f //Force Player Speed
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
}		t_str;

typedef struct s_gobj
{
	void		*mlx;
	void		*win;
	void		**imgs;
	t_str		str;
	void		*dmap;
	t_player	*p1;
	char *const	*envp;
	char		*pwd;
	int			height;
	int			width;
	int			keys_state[131072];
	int			player_count;
}		t_gobj;

#endif
