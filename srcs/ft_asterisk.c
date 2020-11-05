/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_asterisk.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:59:57 by mramos-j          #+#    #+#             */
/*   Updated: 2020/10/08 20:02:19 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_asterisk(t_lista *env, const char *format, va_list ap)
{
	int	arg;

	arg = va_arg(ap, int);
	if (arg < 0)
	{
		arg = -arg;
		if (format[env->i - 2] != '.')
		{
			env->flag[0] = 1;
			env->width = arg;
		}
		if (env->dot == 1)
		{
			env->prec = -1;
			env->parche = 1;
		}
	}
	else
	{
		if (env->dot == 1)
			env->prec = arg;
		if (env->flag[2] == 1 && format[env->i - 2] != '.')
			env->width = arg;
	}
}
