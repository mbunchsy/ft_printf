/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcachon- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:37:35 by gcachon-          #+#    #+#             */
/*   Updated: 2019/11/26 01:20:47 by gcachon-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*fstr;
	unsigned int	i;
	int				j;

	if (s && f)
	{
		i = 0;
		j = ft_strlen((char *)s);
		if (!(fstr = (char *)malloc(j + 1)))
			return (NULL);
		while (s[i] != 0)
		{
			fstr[i] = f(i, s[i]);
			i++;
		}
		fstr[i] = '\0';
		return (fstr);
	}
	return (NULL);
}
