/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:35:57 by mramos-j          #+#    #+#             */
/*   Updated: 2020/09/29 18:36:05 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi(const char *str)
{
	int		sign;
	int		result;
	int		i;
	int		cypher;

	cypher = 0;
	result = 0;
	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && cypher++ != -2)
		result = (result * 10) + (str[i++] - '0');
	if (cypher > 19)
	{
		if (sign == -1)
			return (0);
		return (-1);
	}
	return (sign * result);
}
