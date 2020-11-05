/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:39:16 by mramos-j          #+#    #+#             */
/*   Updated: 2020/10/08 20:02:03 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_read(t_lista *env, const char *format, va_list ap)
{
	while (format[env->i])
	{
		if (format[env->i] == '%')
		{
			env->i++;
			if (ft_parse(env, format, ap))
				ft_compute(env, ap);
			ft_reinit(env);
		}
		else
		{
			ft_putchar(format[env->i]);
			env->i++;
			env->ret++;
		}
	}
}

int		ft_printf(const char *format, ...)
{
	t_lista	*env;
	va_list	ap;
	size_t	ret;

	if (!format)
		return (-1);
	if (!(env = malloc(sizeof(t_lista))) || !(ft_init(env)))
		return (-1);
	va_start(ap, format);
	ft_read(env, format, ap);
	ret = env->ret;
	free(env);
	return (ret);
}
