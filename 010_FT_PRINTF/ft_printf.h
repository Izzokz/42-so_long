/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kzhen-cl <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 14:47:45 by kzhen-cl          #+#    #+#             */
/*   Updated: 2024/10/16 14:47:47 by kzhen-cl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <errno.h>
# include "010_GNLXIO/gnlxio.h"

typedef struct s_params
{
	const char	*str;
	size_t		i;
	int			fd;
	va_list		args;
}	t_params;

long	ft_pow(int number, int exp);
char	*ft_strdup(const char *str);
size_t	ft_strlen(const char *str);
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
char	*ft_itoa(int n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_getbase(unsigned long nbr, int base, int up);
int		ft_conv(const char type, const char c);
int		ft_write_b(t_params *pa);
int		ft_write_c(char value, int fd);
int		ft_write_s(char *value, int fd);
int		ft_write_d(int value, int fd);
int		ft_write_x(int value, int up, int fd);
int		ft_write_p(unsigned long value, int fd);
int		ft_write_u(unsigned int value, int fd);
int		ft_write_bool(int value, int colored, int fd);
int		ft_write_file(t_params *pa);
int		ft_process_all_s(char **chain, char *sep, int fd);
int		ft_process_all_d(int *array, char *sep, int fd);
int		ft_process_all_u(unsigned int *array, char *sep, int fd);
int		ft_process_all_p(unsigned long *ptr, char *sep, int fd);
int		ft_process(t_params *pa);
int		ft_write_all(t_params *pa);
int		ft_printf_fd(const char *str, int fd, ...);
int		ft_printf(const char *str, ...);
int		ft_printf_err(const char *msg, int fd, ...);

#endif
