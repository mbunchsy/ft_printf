/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcachon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 21:12:40 by gcachon-          #+#    #+#             */
/*   Updated: 2019/11/26 01:26:41 by gcachon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*str;
	unsigned const char	*ptr;
	unsigned char		ch;
	unsigned int		i;

	str = dst;
	ptr = src;
	ch = c;
	i = 0;
	while (i < n)
	{
		str[i] = ptr[i];
		if (ptr[i] == ch)
			return ((void *)&dst[i + 1]);
		i++;
	}
	return (NULL);
}
