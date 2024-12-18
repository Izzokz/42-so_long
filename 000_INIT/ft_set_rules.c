/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_rules.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 16:10:49 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/12/18 16:10:51 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	ft_strcmp(char	*string1, char *string2)
{
	int	index;

	index = 0;
	while (string1[index] == string2[index])
	{
		if ((string1[index] == '\0' && string2[index] == '\0')
			|| (string1[index] != string2[index]))
			break ;
		index ++;
	}
	return (string1[index] - string2[index]);
}

static char	*get_rule(const char *rule, t_rlines rules)
{
	char	*value;
	int		i;

	i = -1;
	value = NULL;
	while (rules[++i])
	{
		if (ft_strnstr(rules[i], rule, ft_strlen(rule)))
		{
			value = ft_substr(rules[i], ft_strlen(rule), -1);
			break ;
		}
	}
	return (value);
}

static float	get_float_from_range(char *rule_value)
{
	if (ft_strcmp(rule_value, "0.1f") == 0)
		return (0.1f);
	if (ft_strcmp(rule_value, "0.2f") == 0)
		return (0.2f);
	if (ft_strcmp(rule_value, "0.3f") == 0)
		return (0.3f);
	if (ft_strcmp(rule_value, "0.4f") == 0)
		return (0.4f);
	if (ft_strcmp(rule_value, "0.5f") == 0)
		return (0.5f);
	if (ft_strcmp(rule_value, "0.6f") == 0)
		return (0.6f);
	if (ft_strcmp(rule_value, "0.7f") == 0)
		return (0.7f);
	if (ft_strcmp(rule_value, "0.8f") == 0)
		return (0.8f);
	if (ft_strcmp(rule_value, "0.9f") == 0)
		return (0.9f);
	return (1.0f);
}

static int	get_bool(char *rule_value)
{
	return (ft_strcmp(rule_value, "TRUE") == 0
		|| ft_atoi(rule_value) != 0);
}

void	ft_set_rules(t_gobj *game, t_rlines rules)
{
	char	*actual_rule;

	if (invalid_rlines(rules))
		return ;
	ft_rlines_cutendl(&rules);
	if (invalid_rlines(rules))
		return ;
	actual_rule = get_rule("BRN=", rules);
	if (actual_rule)
	{
		game->brn = get_float_from_range(actual_rule);
		free(actual_rule);
	}
	actual_rule = get_rule("THEME=", rules);
	if (actual_rule)
	{
		game->theme = get_float_from_range(actual_rule);
		free(actual_rule);
	}
	actual_rule = get_rule("PAINT=", rules);
	if (actual_rule)
	{
		game->paint = get_bool(actual_rule);
		free(actual_rule);
	}
}
