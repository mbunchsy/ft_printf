/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:39:26 by mramos-j          #+#    #+#             */
/*   Updated: 2020/10/08 20:02:01 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_len_hexa(long long int nb)
{
	int	i;

	i = 1;
	if (nb >= 16)
		i += ft_len_hexa(nb / 16);
	return (i);
}

static void	ft_change_hexa(t_lista *env, unsigned int nb, char *base)
{
	if (nb >= 16)
		ft_change_hexa(env, nb / 16, base);
	ft_putlchar(0, base[(nb % 16)], env);
}

static void	ft_putpads(t_lista *env, int less, int arglen)
{
	int	i;
	int	widthlen;
	int	ceros;

	i = 0;
	if (env->width && env->prec > arglen)
	{
		widthlen = env->width - env->prec;
		ceros = env->prec - arglen - 1;
	}
	else if (env->prec && !env->width)
		ceros = env->prec - arglen - 1;
	else
		widthlen = env->width - arglen;
	if (env->prec == -1)
		widthlen += arglen;
	if (env->width && env->flag[1] && less != 0 && !env->prec)
		ft_putlchar(widthlen - 1, '0', env);
	else if (env->width && ((!less && env->flag[0]) ||
	(less && !env->flag[0])))
		ft_putlchar(widthlen - 1, ' ', env);
	if (env->prec > arglen && less != 0)
		ft_putlchar(ceros, '0', env);
}

void		ft_printhexa(t_lista *env, int nb)
{
	if ((env->width || env->prec) && nb >= 0)
		ft_putpads(env, 1, ft_len_hexa(nb));
	if ((env->prec != -1 || nb != 0) && env->type == 'x')
		ft_change_hexa(env, nb, "0123456789abcdef");
	if ((env->prec != -1 || nb != 0) && env->type == 'X')
		ft_change_hexa(env, nb, "0123456789ABCDEF");
	if (env->width > 0 && env->flag[0] && nb >= 0)
		ft_putpads(env, 0, ft_len_hexa(nb));
}
