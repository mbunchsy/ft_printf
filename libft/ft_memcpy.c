/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcachon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:50:11 by gcachon-          #+#    #+#             */
/*   Updated: 2019/11/25 23:59:05 by gcachon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*str;
	char		*ptr;

	str = (char*)dst;
	ptr = (char*)src;
	i = 0;
	if (str == ptr)
		return (dst);
	while (i < n)
	{
		str[i] = ptr[i];
		i++;
	}
	return (dst);
}
