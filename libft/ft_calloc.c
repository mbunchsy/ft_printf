/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:37:03 by mramos-j          #+#    #+#             */
/*   Updated: 2020/09/29 18:37:08 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	*ft_calloc(size_t count, size_t size)
{
	char	*result;
	size_t	i;

	i = 0;
	if (!(result = (char *)malloc(count * size)))
		return (NULL);
	while (i < (count * size))
		result[i++] = 0;
	return (result);
}
