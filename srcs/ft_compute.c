/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 16:52:25 by mramos-j          #+#    #+#             */
/*   Updated: 2020/10/08 20:02:11 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_compute(t_lista *env, va_list ap)
{
	if (env->type == 'd' || env->type == 'i')
		ft_printnums(env, ap);
	if (env->type == 'c' || env->type == '%')
		ft_printchar(env, ap);
	if (env->type == 's')
		ft_printstr(env, va_arg(ap, char *));
	if (env->type == 'u')
		ft_printnumsu(env, va_arg(ap, unsigned int));
	if (env->type == 'x' || env->type == 'X')
		ft_printhexa(env, va_arg(ap, int));
	if (env->type == 'p')
		ft_printpointer(env, va_arg(ap, uintptr_t));
}
