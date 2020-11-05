/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:52:08 by mramos-j          #+#    #+#             */
/*   Updated: 2020/10/08 20:02:05 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_parseprec(t_lista *env, const char *format)
{
	env->dot = 1;
	env->i++;
	while (format[env->i] == '0')
		env->i++;
	if (format[env->i] == '-' || !(ft_isdigit(format[env->i])))
		env->prec = -1;
	else if (ft_isdigit(format[env->i]))
	{
		env->prec = ft_atoi(&format[env->i]);
		env->i += ft_nbrlen(env->prec);
	}
}

void	ft_parsewidth(t_lista *env, const char *format)
{
	env->width = ft_atoi(&format[env->i]);
	env->i += ft_nbrlen(env->width);
}

void	ft_parseflag(t_lista *env, const char *format, va_list ap)
{
	if (format[env->i] == '-')
	{
		env->flag[0] = 1;
		env->i++;
	}
	if (format[env->i] == '0')
	{
		env->flag[1] = 1;
		env->i++;
	}
	if (format[env->i] == '*')
	{
		env->flag[2] = 1;
		env->i++;
		ft_asterisk(env, format, ap);
	}
}

void	ft_parsetflag(t_lista *env, const char *format, va_list ap)
{
	if (format[env->i] == '-' || format[env->i] == '*' ||
	format[env->i] == '0')
		ft_parseflag(env, format, ap);
	if (format[env->i] == '.')
		ft_parseprec(env, format);
	if (ft_isdigit(format[env->i]) && format[env->i] != '0')
		ft_parsewidth(env, format);
}

int		ft_parse(t_lista *env, const char *format, va_list ap)
{
	while (format[env->i] == '-' || format[env->i] == '0' ||
	format[env->i] == '.' || format[env->i] == '*' ||
	ft_isdigit(format[env->i]))
		ft_parsetflag(env, format, ap);
	if (env->prec == 0 && env->dot == 1)
		env->prec = -1;
	if (ft_charchr("cspdiuxX%", format[env->i]))
		env->type = format[env->i++];
	return (1);
}
