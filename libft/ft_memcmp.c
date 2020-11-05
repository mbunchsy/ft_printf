/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcachon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 19:38:49 by gcachon-          #+#    #+#             */
/*   Updated: 2019/11/26 01:50:42 by gcachon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*sc1;
	unsigned char	*sc2;
	size_t			i;

	sc1 = (unsigned char*)s1;
	sc2 = (unsigned char*)s2;
	i = 0;
	while (i < n)
	{
		if (sc1[i] != sc2[i])
			return (sc1[i] - sc2[i]);
		else
			i++;
	}
	return (0);
}
