/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnums.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:39:48 by mramos-j          #+#    #+#             */
/*   Updated: 2020/10/08 20:02:00 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putlnbr(unsigned int n, t_lista *env)
{
	if (n > 9)
		ft_putlnbr(n / 10, env);
	ft_putchar(n % 10 + '0');
	env->ret++;
}

void	ft_numsprecneg(t_lista *env, long long int arg, int arglen)
{
	int espacios;

	if (env->prec == -1 && !env->flag[2] && env->width > arglen)
	{
		espacios = env->width - 1;
		ft_putlchar(espacios, ' ', env);
	}
	else if (env->prec == -1 && env->width > arglen)
	{
		espacios = env->width - 1;
		ft_putlchar(espacios, ' ', env);
	}
	else if (arg != 0)
		ft_putlnbr(arg, env);
	else if (arg == 0 && env->prec == -1 && env->parche == 1)
		ft_putlnbr(arg, env);
}

void	ft_printnums(t_lista *env, va_list ap)
{
	int	nb;

	nb = va_arg(ap, int);
	if (nb < 0)
		ft_printnumsneg(env, nb);
	else
		ft_printnumspos(env, nb);
}
