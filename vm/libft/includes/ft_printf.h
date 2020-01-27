/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lode-spi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 11:08:41 by lode-spi          #+#    #+#             */
/*   Updated: 2019/08/31 22:39:14 by lode-spi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <stdarg.h>
# include "../includes/libft.h"

# define FSP 0x01
# define FPL 0x02
# define FMI 0x04
# define FNO 0x08
# define FZE 0x10

# define MAX_PAD 31

# define FINITE -1
# define NAN    1
# define INF    2

typedef union	u_v
{
	long		li;
	long double ld;
}				t_v;

typedef struct	s_ld
{
	long double	ldval;
	int			err;
	int			exp;
	int			nsig;
	char		*p;
}				t_ld;

typedef struct	s_formspec
{
	uintmax_t	uim;
	intmax_t	im;
	t_v			v;
	wchar_t		*wc;
	size_t		size;
	char		*s;
	char		flags;
	int			width;
	int			prec;
	char		qual;
	int			n0;
	int			nz0;
	int			n1;
	int			nz1;
	int			n2;
	int			nz2;
}				t_formspec;

static const long double g_pows[] = {
	1e1L, 1e2L, 1e4L, 1e8L, 1e16L, 1e32L,
	1e64L, 1e128L, 1e256L, 1e512L, 1e1024L, 1e2048L, 1e4096L,
};

int				ft_printf(const char *restrict format, ...);
int				print_formated(const char *restrict format, va_list ap);
void			get_formspec(const char *restrict *format, t_formspec *fs);
int				dispatch(va_list ap, t_formspec *fs, char specif, char *ac);
void			handle_wchar(va_list ap, t_formspec *fs, char *ac);
void			handle_sint(va_list ap, t_formspec *fs, char specif, char *ac);
void			handle_uint(va_list ap, t_formspec *fs, char specif, char *ac);
void			handle_string(va_list ap, t_formspec *fs);
void			handle_ptr(va_list ap, t_formspec *fs, char *ac);
void			handle_ld(va_list ap, t_formspec *fs, char *ac);
void			handle_wstring(va_list ap, t_formspec *fs);
int				numbits(wchar_t c);
void			wctob(t_formspec *fs);
void			uimtob(t_formspec *fs, char specif);
void			imtob(t_formspec *fs);
void			ldtob(t_formspec *fs, char *ac);
void			ordered_release(t_formspec *fs, char *ac, char specif);
short			unscale_ld(int *exp, long double input);
void			scale(int *exp, long double *ldval);
void			fill_buff_ld(t_formspec *fs, t_ld *vars);
void			genld(t_formspec *fs, char *p, short nsig, short xexp);
#endif
