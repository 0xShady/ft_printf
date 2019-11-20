/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 23:47:43 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/20 00:11:13 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <string.h>

typedef struct	s_flag
{
	int			prec;
	int			width;
	int			moins;
	int			zero;
}				t_flag;

int				ft_printf(char *frm, ...);
char			*flag_conv(char *frm, int flag);
int				ft_check_flag(char *s, va_list arg, int *flag);
int				get_flag(char *s, va_list arg);
int				ship_flag(t_flag flag, va_list arg, char c);
char			ft_get_conv(char *s);
int				ft_check_zero(char *s);
int				ft_check_moins(char *s);
int				ft_get_width(char *s, va_list arg, int *moins);
int				ft_get_prec(char *s, va_list arg);
void			init(t_flag *flag);
int				ft_flag_c(t_flag flag, va_list arg, char c);
int				ft_flag_char(t_flag flag, va_list arg);
int				ft_flag_mod(t_flag flag);
int				ft_flag_u(t_flag flag, va_list arg);
int				ft_flag_u_4(t_flag flag, va_list arg);
int				ft_flag_u_3(t_flag flag, va_list arg);
int				ft_flag_u_help2(t_flag flag, unsigned uu, int w);
int				ft_flag_u_2(t_flag flag, va_list arg);
int				ft_flag_u_1(t_flag flag, va_list arg);
int				ft_flag_u_help1(t_flag flag, va_list arg);
int				ft_flag_d(t_flag flag, va_list arg);
int				ft_flag_d_5(t_flag flag, va_list arg);
int				ft_flag_d_4(t_flag flag, va_list arg);
int				ft_flag_d_3(t_flag flag, int i, int w);
int				ft_flag_d_help1(t_flag flag, int i, int w);
int				ft_flag_d_2(t_flag flag, va_list arg);
int				ft_flag_d_help2(t_flag flag, va_list arg);
int				ft_flag_d_1(t_flag flag, va_list arg);
int				ft_flag_d_help3(t_flag flag, va_list arg);
int				ft_flag_xx(t_flag flag, va_list arg);
int				ft_flag_xx_help4(va_list arg);
int				ft_flag_xx_help3(va_list arg);
int				ft_flag_xx_4(t_flag flag, va_list arg);
int				ft_flag_xx_6(t_flag flag, va_list arg);
int				ft_flag_xx_5(t_flag flag, va_list arg);
int				ft_flag_xx_3(t_flag flag, va_list arg);
int				ft_flag_xx_2(t_flag flag, va_list arg);
int				ft_flag_xx_help2(t_flag flag, va_list arg);
int				ft_flag_xx_1(t_flag flag, va_list arg);
int				ft_flag_xx_help(t_flag flag, va_list arg);
int				ft_flag_x(t_flag flag, va_list arg);
int				ft_flag_x_help4(va_list arg);
int				ft_flag_x_help3(va_list arg);
int				ft_flag_x_4(t_flag flag, va_list arg);
int				ft_flag_x_6(t_flag flag, va_list arg);
int				ft_flag_x_5(t_flag flag, va_list arg);
int				ft_flag_x_3(t_flag flag, va_list arg);
int				ft_flag_x_2(t_flag flag, va_list arg);
int				ft_flag_x_help2(t_flag flag, va_list arg);
int				ft_flag_x_1(t_flag flag, va_list arg);
int				ft_flag_x_help(t_flag flag, va_list arg);
int				ft_flag_s(t_flag flag, va_list arg);
int				help_s_2(va_list arg);
int				ft_flag_s_2(t_flag flag, va_list arg);
int				ft_flag_s_6(t_flag flag, char *str);
int				ft_flag_s_5(t_flag flag, char *str);
int				ft_flag_s_3(t_flag flag, va_list arg);
int				help_s(t_flag flag, char *str, int w);
int				ft_flag_s_1(t_flag flag, va_list arg);
int				ft_flag_p(t_flag flag, va_list arg);
int				print_spaces(int w, char c);
int				print_conv(int c, va_list arg);
int				ft_print_s(va_list arg, char c);
int				ft_print_x(va_list arg, char c);
int				ft_print_d(va_list arg, char c);
char			*ft_strdup(const char *src);
int				ft_atoi(const char *str);
int				spaces(char c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
size_t			ft_strlen(const char *str);
int				ft_putstr_len(char *s, int len);
int				ft_putstr(char *s);
int				ft_putchar(char c);
char			*ft_strupcase(char *str);
char			*ft_itoa_pointer(unsigned long long nbr);
char			*ft_itoa_base(unsigned int nbr, int base);
char			*ft_itoa(long nb);
int				len_u(size_t nb);
int				len(long nb);
char			*ft_utoa(size_t nb);

#endif
