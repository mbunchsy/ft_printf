/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumspos.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:40:02 by mramos-j          #+#    #+#             */
/*   Updated: 2020/10/08 20:01:59 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_numsizq(t_lista *env, long long int arg, int arglen)
{
	int espacios;
	int ceros;

	if (env->width > arglen && (env->prec == 0 || env->prec < arglen))
	{
		espacios = env->width - arglen - 1;
		ft_putlnbr(arg, env);
		ft_putlchar(espacios, ' ', env);
	}
	else if (env->width > arglen && env->prec > arglen)
	{
		espacios = env->width - env->prec - 1;
		ceros = env->prec - arglen - 1;
		ft_putlchar(ceros, '0', env);
		ft_putlnbr(arg, env);
		ft_putlchar(espacios, ' ', env);
	}
	else if (env->width < env->prec && env->prec > arglen)
	{
		ceros = env->prec - arglen - 1;
		ft_putlchar(ceros, '0', env);
		ft_putlnbr(arg, env);
	}
	else
		ft_putlnbr(arg, env);
}

static void	ft_numsprec(t_lista *env, long long int arg, int arglen)
{
	int preclen;

	preclen = env->prec - arglen - 1;
	ft_putlchar(preclen, '0', env);
	ft_putlnbr(arg, env);
}

static void	ft_numspw(t_lista *env, long long int arg, int arglen)
{
	int ceros;
	int espacios;

	if (env->width > env->prec && env->prec > arglen && env->width > arglen)
	{
		espacios = env->width - env->prec - 1;
		ft_putlchar(espacios, ' ', env);
		ceros = env->prec - arglen - 1;
		ft_putlchar(ceros, '0', env);
		ft_putlnbr(arg, env);
	}
	else if (env->width > env->prec && env->prec <= arglen)
	{
		espacios = env->width - arglen - 1;
		ft_putlchar(espacios, ' ', env);
		ft_putlnbr(arg, env);
	}
	else if (env->prec >= env->width && env->prec > arglen)
	{
		ceros = env->prec - arglen - 1;
		ft_putlchar(ceros, '0', env);
		ft_putlnbr(arg, env);
	}
	else
		ft_putlnbr(arg, env);
}

static void	ft_numswidth(t_lista *env, long long int arg, int arglen)
{
	int widthlen;

	if ((env->width > arglen) && env->flag[1])
	{
		widthlen = (env->width - arglen - 1);
		ft_putlchar(widthlen, '0', env);
		ft_putlnbr(arg, env);
	}
	else if (env->width)
	{
		widthlen = (env->width - arglen - 1);
		ft_putlchar(widthlen, ' ', env);
		ft_putlnbr(arg, env);
	}
	else
		ft_putlnbr(arg, env);
}

void		ft_printnumspos(t_lista *env, long long int arg)
{
	int	arglen;

	arglen = ft_nbrlen(arg);
	if (env->prec == -1)
		ft_numsprecneg(env, arg, arglen);
	else if (env->flag[0] == 1)
		ft_numsizq(env, arg, arglen);
	else if (env->width != 0 && env->prec > 0)
		ft_numspw(env, arg, arglen);
	else if (env->width != 0 && (env->prec == 0 || env->prec == -1))
		ft_numswidth(env, arg, arglen);
	else if (env->prec > 0 && env->width == 0)
		ft_numsprec(env, arg, arglen);
	else
		ft_putlnbr(arg, env);
}
