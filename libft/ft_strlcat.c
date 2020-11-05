/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcachon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 16:23:35 by gcachon-          #+#    #+#             */
/*   Updated: 2019/11/26 00:44:06 by gcachon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t i;
	size_t j;
	size_t l;

	i = 0;
	j = 0;
	l = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
		j++;
	while (src[l] != '\0' && (i + l) < dstsize - 1 && dstsize > 0)
	{
		dst[i + l] = src[l];
		l++;
	}
	dst[i + l] = '\0';
	if (dstsize >= i)
		return (i + j);
	return (j + dstsize);
}
