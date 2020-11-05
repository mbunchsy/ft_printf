/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 17:42:32 by mramos-j          #+#    #+#             */
/*   Updated: 2020/10/08 20:01:55 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_nbrlen(int n)
{
	int		i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i = 3;
	}
	if (n == 0)
		return (1);
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

int		ft_charchr(char *str, char c)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ft_putlchar(int p, char c, t_lista *env)
{
	int i;

	i = 0;
	while (p >= i)
	{
		write(1, &c, 1);
		i++;
		env->ret++;
	}
}
