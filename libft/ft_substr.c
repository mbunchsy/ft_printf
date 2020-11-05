/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcachon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 00:28:21 by gcachon-          #+#    #+#             */
/*   Updated: 2019/11/26 01:52:11 by gcachon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	i;
	size_t	size;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	size = ((ft_strlen(s + start) > len) ? len : ft_strlen(s + start));
	if (!(s1 = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size && *s)
	{
		s1[i] = s[i + start];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
