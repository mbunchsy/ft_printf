/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printfmain.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 19:29:28 by mrosario          #+#    #+#             */
/*   Updated: 2020/10/13 21:53:15 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include "libftprintf.h"
#include "../includes/ft_printf.h"
#include <stdio.h>
#include <limits.h>

int main(void)
{

	char *str1 = {"Blablablo"};
	char *str2 = {"\0"};
	int	ent1 = 42;
	int ent2 = -42;
	unsigned int ent3 = UINT_MAX;
	char *str3 = NULL;

	printf("\n%s\n%.0s\n%c\n%c\n%042i\n%-42d\n%u\n%x\n%p\n%s", str1, str2, *str1, *str2, ent1, ent2, ent3, ent3, &str1, str3);
	printf("--------\n");
	ft_printf("\n%s\n%.0s\n%c\n%c\n%042i\n%-42d\n%u\n%x\n%p\n%s", str1, str2, *str1, *str2, ent1, ent2, ent3, ent3, &str1, str3);
	printf("--------\n\n");
	system("leaks a.out");
	return (0);
}