/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mramos-j <mramos-j@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 19:11:51 by gcachon-          #+#    #+#             */
/*   Updated: 2020/10/08 20:02:20 by mramos-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdint.h>
# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_lista
{
	char	flag[3];
	int		width;
	int		prec;
	int		dot;
	char	modif;
	char	type;
	int		ret;
	int		i;
	int		parche;
}				t_lista;

int				ft_printf(const char *format, ...);
void			ft_read(t_lista *env, const char *format, va_list ap);
int				ft_parse(t_lista *env, const char *format, va_list ap);
void			ft_parsetflag(t_lista *env, const char *format, va_list ap);
void			ft_parseflag(t_lista *env, const char *format, va_list ap);
void			ft_parsewidth(t_lista *env, const char *format);
void			ft_parseprec(t_lista *env, const char *format);
int				ft_nbrlen(int n);
int				ft_charchr(char *str, char c);
int				ft_reinit(t_lista *env);
int				ft_init(t_lista *env);
void			ft_compute (t_lista *env, va_list ap);
void			ft_printnums(t_lista *env, va_list ap);
void			ft_putlchar (int p, char c, t_lista *env);
void			ft_numsprecneg(t_lista *env, long long int arg, int arglen);
void			ft_printnumsneg (t_lista *env, long long int arg);
void			ft_printnumspos(t_lista *env, long long int arg);
void			ft_putlnbr(unsigned int n, t_lista *env);
void			ft_printnumsu(t_lista *env, unsigned int arg);
void			ft_printchar(t_lista *env, va_list ap);
void			ft_printstr(t_lista *env, char *c);
void			ft_printhexa(t_lista *env, int nb);
void			ft_printpointer(t_lista *env, uintptr_t arg);
void			ft_asterisk(t_lista *env, const char *format, va_list ap);

#endif
