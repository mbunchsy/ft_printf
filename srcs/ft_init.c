/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:01:42 by mramos-j          #+#    #+#             */
/*   Updated: 2020/10/08 20:02:06 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_reinit(t_lista *env)
{
	env->width = 0;
	env->prec = 0;
	env->dot = 0;
	env->flag[0] = 0;
	env->flag[1] = 0;
	env->flag[2] = 0;
	env->modif = '\0';
	env->type = '\0';
	env->parche = 0;
	return (1);
}

int	ft_init(t_lista *env)
{
	env->width = 0;
	env->prec = 0;
	env->dot = 0;
	env->flag[0] = 0;
	env->flag[1] = 0;
	env->flag[2] = 0;
	env->modif = '\0';
	env->type = '\0';
	env->ret = 0;
	env->i = 0;
	env->parche = 0;
	return (1);
}
