/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:03:07 by mramos-j          #+#    #+#             */
/*   Updated: 2020/10/08 20:02:04 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putpads(t_lista *env, int less, int arglen)
{
	int	i;
	int	widthlen;

	i = 0;
	if (env->prec > arglen && !env->width)
		return ;
	if (env->prec > 0 && env->prec < arglen)
		widthlen = env->width - env->prec;
	else if (env->parche == 1)
		widthlen = env->width - arglen;
	else
		widthlen = env->width - arglen;
	if (env->prec == -1 && env->parche == 0)
		widthlen += arglen;
	if (env->width && env->flag[1] && !env->flag[0])
		ft_putlchar(widthlen - 1, '0', env);
	else if (env->width && ((!less && env->flag[0]) ||
	(less && !env->flag[0])))
	{
		while (++i <= widthlen)
			ft_putchar(' ');
		env->ret += i - 1;
	}
}

void		ft_printchar(t_lista *env, va_list ap)
{
	char c;

	if (env->type == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	if (env->width || env->prec)
		ft_putpads(env, 1, 1);
	ft_putchar(c);
	if (env->width && env->flag[0] == 1)
		ft_putpads(env, 0, 1);
	env->ret += 1;
}

void		ft_printstr(t_lista *env, char *c)
{
	int i;

	i = 0;
	if (!c)
		c = "(null)";
	if (env->width || env->prec != -1)
		ft_putpads(env, 1, ft_strlen(c));
	if (env->prec != 0 && env->prec != -1)
	{
		while (i < env->prec && c[i])
			ft_putchar(c[i++]);
		env->ret += i;
	}
	else if (env->prec != -1 || env->parche == 1)
	{
		ft_putstr_fd(c, 1);
		env->ret += ft_strlen(c);
	}
	if (env->width > 0 && env->flag[0])
		ft_putpads(env, 0, ft_strlen(c));
}
