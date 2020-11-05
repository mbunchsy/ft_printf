/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:36:17 by mramos-j          #+#    #+#             */
/*   Updated: 2020/09/29 18:36:53 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ptr;
	size_t			c;

	c = n;
	ptr = (unsigned char*)s;
	while (c--)
	{
		ptr[c] = '\0';
	}
}
