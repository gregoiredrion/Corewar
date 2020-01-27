/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdrion <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 15:28:23 by gdrion            #+#    #+#             */
/*   Updated: 2019/10/29 12:34:41 by gdrion           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <locale.h>
# include <stdarg.h>
# include <math.h>
# include <wchar.h>
# include <limits.h>

typedef struct	s_flags
{
	int		width;
	int		precision;
	int		minus;
	int		plus;
	int		hash;
	int		ll;
	int		l;
	int		bigl;
	int		hh;
	int		h;
	int		j;
	int		z;
	int		space;
	int		info1;
	int		info2;
	char	zero;
	char	conv;
}				t_flags;

char			*ft_dtoa2(long double nb, t_flags *flags);
char			*ft_itoa_new(intmax_t n);
char			*join_regarding_bz(char *s1, int info1, char *s2, int info2);
int				ft_strlen_info(char *s1, int info1);
void			ft_putstrn(char *s1, int info);
int				fill_incr(const char *s, t_flags *f);
int				ft_printf(const char *format, ...);
char			*ft_buf_char(char *buf, char c, int info, int nb_bz);
char			*join_and_free(char *buf, char *conv);
/*
**  find_flags.c
*/
void			fill_flags(char *str, t_flags *f);
/*
**  create_struct.c
*/
t_flags			*ft_create_struct(void);
void			init_flags(t_flags *f);
/*
**  ft_itoa_t.c
*/
char			*ft_lltoa(intmax_t n);
char			*ft_ultoa(uintmax_t n);
/*
**  unicode.c
*/
char			*unicode(wint_t a);
int				get_byte_len(wint_t a);
/*
**   Unicode thing
*/
char			*handle_unicode_string(va_list ap, t_flags *f);
/*
**  choose_conv.c
*/
char			*choose_conv(va_list ap, t_flags *f);
/*
**  string_conv.c
*/
char			*ft_conv_s(va_list ap, t_flags *f);
char			*ft_modify_arg_s(char *arg, t_flags *f);
/*
**  char_conv.c
*/
char			*ft_conv_c(va_list ap, t_flags *f);
/*
**  int_conv.c
*/
char			*ft_conv_d(va_list ap, t_flags *f);
char			*ft_simple_conv_d(char *nb, t_flags *f);
char			*aapply_prec_d(t_flags *f, char *nb);
char			*aaply_width_d(t_flags *f, int w_len, char *nb);
/*
**  u_conv.c
*/
char			*ft_conv_u(va_list ap, t_flags *f);
/*
**  x_conv.c
*/
char			*ft_conv_x(va_list ap, t_flags *f);
/*
**  o_conv.c
*/
char			*ft_conv_o(va_list ap, t_flags *f);
/*
**  f_conv.c
*/
char			*ft_conv_f(va_list ap, t_flags *f);

#endif
