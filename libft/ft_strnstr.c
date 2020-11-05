/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcachon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 23:26:27 by gcachon-          #+#    #+#             */
/*   Updated: 2019/11/29 19:17:53 by gcachon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned int	i;
	unsigned int	j;

	if (!*needle)
		return ((char*)haystack);
	i = 0;
	while (haystack[i] && i < len)
	{
		j = 0;
		while (haystack[i + j] && i + j < len
				&& needle[j] && haystack[i + j] == needle[j])
			j++;
		if (!needle[j])
			return ((char*)haystack + i);
		i++;
	}
	return (NULL);
}
