/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printpointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:40:46 by mramos-j          #+#    #+#             */
/*   Updated: 2020/10/08 20:01:56 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_putpads(t_lista *env, int less, int arglen)
{
	int	widthlen;
	int	ceros;

	if (env->width && env->prec > arglen)
	{
		widthlen = env->width - env->prec - 2;
		ceros = env->prec - arglen;
	}
	else if (env->prec && !env->width)
		ceros = env->prec - arglen;
	else
		widthlen = env->width - arglen - 2;
	if (env->prec == -1)
		widthlen += arglen;
	if (env->width && env->flag[1] && less != 0 && !env->prec)
		ft_putlchar(widthlen - 1, '0', env);
	else if (env->width && ((!less && env->flag[0]) ||
	(less && !env->flag[0])))
		ft_putlchar(widthlen - 1, ' ', env);
	if (env->prec > arglen && less != 0)
	{
		ft_putstr_fd("0x", 1);
		env->ret += 2;
		ft_putlchar(ceros - 1, '0', env);
	}
}

static int	ft_len_hexa(uintptr_t nb)
{
	int	i;

	i = 1;
	if (nb >= 16)
		i += ft_len_hexa(nb / 16);
	return (i);
}

static void	ft_change_hexa(t_lista *env, uintptr_t nb, char *base)
{
	if (nb >= 16)
		ft_change_hexa(env, nb / 16, base);
	ft_putlchar(0, base[(nb % 16)], env);
}

void		ft_printpointer(t_lista *env, uintptr_t arg)
{
	if ((env->width || env->prec) && !env->flag[0])
		ft_putpads(env, 1, ft_len_hexa(arg));
	if (arg && env->width < env->prec)
		ft_change_hexa(env, arg, "0123456789abcdef");
	else if (arg)
	{
		ft_putstr_fd("0x", 1);
		env->ret += 2;
		ft_change_hexa(env, arg, "0123456789abcdef");
	}
	else if (env->prec == -1)
	{
		ft_putstr_fd("0x", 1);
		env->ret += 2;
	}
	else if (env->width || !env->prec)
	{
		ft_putstr_fd("0x", 1);
		env->ret += 2;
		ft_putlchar(0, '0', env);
	}
	else if (arg == 0)
		ft_putlchar(0, '0', env);
	if (env->width && env->flag[0])
		ft_putpads(env, 0, ft_len_hexa(arg));
}
