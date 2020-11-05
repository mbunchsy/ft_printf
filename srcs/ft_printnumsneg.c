/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumsneg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:39:55 by mramos-j          #+#    #+#             */
/*   Updated: 2020/10/08 20:01:59 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	ft_numsizqn(t_lista *env, long long int argn, int arglen)
{
	int ceros;
	int espacios;

	ceros = env->prec - arglen;
	if (env->width && (env->prec == 0 || env->prec < arglen))
	{
		espacios = env->width - arglen - 1;
		ft_putlchar(0, '-', env);
		ft_putlnbr(argn, env);
		ft_putlchar(espacios, ' ', env);
	}
	else if (env->width > arglen && env->prec > arglen)
	{
		espacios = env->width - env->prec - 2;
		ft_putlchar(0, '-', env);
		ft_putlchar(ceros, '0', env);
		ft_putlnbr(argn, env);
		ft_putlchar(espacios, ' ', env);
	}
	else if (env->width < env->prec && env->prec > arglen)
	{
		ft_putlchar(0, '-', env);
		ft_putlchar(ceros, '0', env);
		ft_putlnbr(argn, env);
	}
}

static void	ft_numspwn(t_lista *env, long long int argn, int arglen)
{
	int ceros;
	int espacios;

	ceros = env->prec - arglen;
	if (env->width >= env->prec && env->prec > arglen && env->width > arglen)
	{
		espacios = env->width - env->prec - 2;
		ft_putlchar(espacios, ' ', env);
		ft_putlchar(0, '-', env);
		ft_putlchar(ceros, '0', env);
		ft_putlnbr(argn, env);
	}
	else if (env->width >= env->prec && env->prec < arglen)
	{
		espacios = env->width - arglen - 1;
		ft_putlchar(espacios, ' ', env);
		ft_putlchar(0, '-', env);
		ft_putlnbr(argn, env);
	}
	else if (env->prec > env->width && env->prec > arglen)
	{
		ft_putlchar(0, '-', env);
		ft_putlchar(ceros, '0', env);
		ft_putlnbr(argn, env);
	}
}

static void	ft_numswidthn(t_lista *env, long long int argn, int arglen)
{
	int widthlen;

	if ((env->width > arglen) && env->flag[1])
	{
		widthlen = (env->width - arglen - 1);
		ft_putlchar(0, '-', env);
		ft_putlchar(widthlen, '0', env);
		ft_putlnbr(argn, env);
	}
	else if (env->width)
	{
		widthlen = (env->width - arglen - 1);
		ft_putlchar(widthlen, ' ', env);
		ft_putlchar(0, '-', env);
		ft_putlnbr(argn, env);
	}
}

static void	ft_numsprecn(t_lista *env, long long int argn, int arglen)
{
	int preclen;

	preclen = env->prec - arglen;
	ft_putlchar(0, '-', env);
	ft_putlchar(preclen, '0', env);
	ft_putlnbr(argn, env);
}

void		ft_printnumsneg(t_lista *env, long long int arg)
{
	int argn;
	int arglen;

	argn = -arg;
	arglen = ft_nbrlen(argn) + 1;
	if (env->flag[0] == 1 && (env->width || env->prec))
		ft_numsizqn(env, argn, arglen);
	else if (env->width != 0 && env->prec > 0)
		ft_numspwn(env, argn, arglen);
	else if (env->width != 0 && (env->prec == 0 || env->prec == -1))
		ft_numswidthn(env, argn, arglen);
	else if (env->prec > 0 && env->width == 0)
		ft_numsprecn(env, argn, arglen);
	else
	{
		ft_putlchar(0, '-', env);
		ft_putlnbr(argn, env);
	}
}
