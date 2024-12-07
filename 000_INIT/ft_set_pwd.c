/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_pwd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 22:16:22 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/07 22:16:23 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	ft_set_pwd(t_gobj *game, char **envp)
{
	int	i;

	i = -1;
	while (envp[++i])
		if (ft_strnstr(envp[i], "PWD=", 4))
			game->pwd = ft_substr(envp[i], 4, -1);
	if (!game->pwd)
		return (-1);
	return (1);
}
