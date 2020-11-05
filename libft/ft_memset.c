/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcachon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 16:49:07 by gcachon-          #+#    #+#             */
/*   Updated: 2019/11/26 00:03:19 by gcachon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	*ft_memset(void *str, int c, size_t len)
{
	char	*ptr;

	ptr = (char*)str;
	while (len--)
	{
		*ptr++ = c;
	}
	return (str);
}
