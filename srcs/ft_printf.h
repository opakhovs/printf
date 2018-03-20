/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opakhovs <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 14:33:42 by opakhovs          #+#    #+#             */
/*   Updated: 2018/03/05 15:05:33 by opakhovs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>
# include "../includes/libft.h"

# define CHECK (flags->ll==0&&flags->l==0&&flags->z==0&&flags->j==0)
# define MASK (unsigned int)49280
# define MASK2 (unsigned int)14712960
# define MASK3 (unsigned int)4034953344

typedef struct	s_flags
{
	int		plus;
	int		minus;
	int		bp;
	int		p;
	int		ap;
	int		space;
	int		zero;
	int		hh;
	int		h;
	int		z;
	int		j;
	int		l;
	int		ll;
	int		hash;
}				t_flags;

void			o_line_hash(char **str);
void			operate_o_line(char **str, t_flags *flags, uintmax_t num);
int				o_line(va_list *valist, t_flags *flags, char ***res);
int				oo_line(va_list *valist, t_flags *flags, char ***res);
void			x_line_hash(char **str);
void			xx_line_hash(char **str);
int				no_line(t_flags *flags, char c, char ***res);
void			operate_x_line(char **str, t_flags *flags, uintmax_t num);
void			operate_xx_line(char **str, t_flags *flags, uintmax_t num);
int				x_line(va_list *valist, t_flags *flags, char ***res);
int				xx_line(va_list *valist, t_flags *flags, char ***res);
void			operate_per_line(char **str, t_flags *flags, int check);
int				per_line(t_flags *flags, char ***res);
void			resize_res(char ***res, int length, char *str);
void			resize_dog(char ***res, int **p);
char			*ft_min();
size_t			ft_greater(size_t strlen, t_flags *flags);
void			operate_u_line(char **str,
	t_flags *flags, int check, uintmax_t num);
int				u_line(va_list *valist, t_flags *flags, char ***res);
int				uu_line(va_list *valist, t_flags *flags, char ***res);
int				freew(wchar_t **str);
void			free_locate(char **str);
void			freestr(char ***res);
int				ft_strcount(char ***res);
int				ft_strlenl(wchar_t *str);
void			p_line_pap(char **str, t_flags *flags);
void			p_line_zbp(char **str, t_flags *flags);
void			p_line_bp(char **str, t_flags *flags);
void			p_line_mbp(char **str, t_flags *flags);
void			p_rewrite(char **str);
void			p_anrewrite(char **str);
int				ft_atoii(const char *format, int *i);
void			operate_p_line(char **str, t_flags *flags);
int				c_line(va_list *valist, t_flags *flags, char ***res, int **p);
int				cc_line(va_list *valist, t_flags *flags, char ***res, int **p);
int				p_line(va_list *valist, t_flags *flags, char ***res);
void			d_line_space(char **str, t_flags *flags, int check);
void			d_line_pap(char **str, t_flags *flags);
void			d_line_zbp(char **str, t_flags *flags);
void			d_line_bp(char **str, t_flags *flags);
void			d_line_mbp(char **str, t_flags *flags);
void			d_line_plus(char **str);
void			operate_d_line(char **str, t_flags *flags, int check, int zero);
int				d_line(va_list *valist, t_flags *flags, char ***res);
int				dd_line(va_list *valist, t_flags *flags, char ***res);
void			s_line_zbp(char **str, t_flags *flags);
void			s_line_bp(char **str, t_flags *flags);
void			s_line_mbp(char **str, t_flags *flags);
void			s_line_pap(char **str, t_flags *flags);
size_t			ft_wstrlen(wchar_t *str);
wchar_t			*ft_wstrnew(size_t size);
void			dcycle(t_flags *flags, int *i, int *j);
void			str_1(char **str, char **nstr, t_flags *flags);
void			str_2(char **str, char **nstr, t_flags *flags);
void			ft_putwchar_in_char(wchar_t chr, char **str, int i);
void			wstr_to_str(wchar_t *str, char **temp, t_flags *flags);
int				copy_c_line(t_flags *flags, char ***res, int **p, char c);
void			operate_ss_line(char **str, t_flags *flags);
int				ss_line(va_list *valist, t_flags *flags, char ***res);
void			operate_s_line(char **str, t_flags *flags, int check);
char			*putnbr(long long int num);
char			*u_putnbr(uintmax_t num);
char			ft_last_elem(char ***res);
void			free_last_line(char ***res);
char			*o_putnbr(uintmax_t num);
char			*x_putnbr(uintmax_t num);
char			*xx_putnbr(uintmax_t num);
int				flags1(const char *fo, int *i, t_flags *flags);
int				flags2(const char *fo, int *i, t_flags *flags);
int				flags3(const char *fo, int *i, t_flags *flags);
int				flags4(const char *fo, int *i, t_flags *flags);
int				s_line(va_list *valist, t_flags *flags, char ***res);
t_flags			new_flags();
int				sym_add(char ***res, char c, int length);
int				is_correct_flag(const char *fo, int *i, t_flags *flags);
t_flags			check_flags(const char *format, int *i);
void			print(char **res, int *p);
int				free_res(char ***res, int **p, char **str);
int				an_part1(va_list *valist, t_flags flags,
	char ***res, int **p);
int				an_part2(char c, va_list *valist, t_flags flags, char ***res);
int				cycle(va_list *valist, const char *format, char ***res,
	int **p);
int				analyser(va_list *valist, const char *format);
int				ft_printf(const char *format, ...);

#endif
