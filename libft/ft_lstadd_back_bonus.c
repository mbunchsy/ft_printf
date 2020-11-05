/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:38:14 by mramos-j          #+#    #+#             */
/*   Updated: 2020/09/29 18:38:16 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*p;

	if (alst)
	{
		p = *alst;
		if (!*alst)
			*alst = new;
		else
		{
			while (p->next != NULL)
			{
				p = p->next;
			}
			p->next = new;
			new->next = NULL;
		}
	}
}
