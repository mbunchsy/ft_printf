/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcachon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:14:48 by gcachon-          #+#    #+#             */
/*   Updated: 2019/11/26 01:29:02 by gcachon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;
	char		*ldest;
	char		*lsrc;
	int			i;

	d = dst;
	s = src;
	i = 0;
	if (d == s)
		return (dst);
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		ldest = d + (len - 1);
		lsrc = (char*)s + (len - 1);
		while (len--)
			*ldest-- = *lsrc--;
	}
	return (dst);
}
