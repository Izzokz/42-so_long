/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_input.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:48:21 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/11/26 10:48:22 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../gnlxio.h"

char	*ft_input(void)
{
	char	*input;

	input = get_next_line(0);
	if (!input)
		return (NULL);
	input[gnlxio_ft_strlen(input) - 1] = '\0';
	return (input);
}
