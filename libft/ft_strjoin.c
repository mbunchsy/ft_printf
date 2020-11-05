/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcachon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 17:43:53 by gcachon-          #+#    #+#             */
/*   Updated: 2019/11/26 01:51:41 by gcachon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s;
	size_t	l;

	if (!s1 || !s2)
		return (NULL);
	l = 0;
	i = ft_strlen(s1);
	j = ft_strlen(s2);
	if (!(s = (char*)malloc(i + j + 1)))
		return (NULL);
	while (*s1 != '\0')
	{
		s[l] = *s1++;
		l++;
	}
	while (*s2 != '\0')
	{
		s[l] = *s2++;
		l++;
	}
	s[l] = '\0';
	return (s);
}
