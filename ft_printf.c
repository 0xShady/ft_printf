/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:17:06 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/20 01:24:22 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ship_flag(t_flag flag, va_list arg, char c)
{
	int		total;

	total = 0;
	if (c == 'd' || c == 'i')
		total += ft_flag_d(flag, arg);
	else if (c == 'u')
		total += ft_flag_u(flag, arg);
	else if (c == 's')
		total += ft_flag_s(flag, arg);
	else if (c == 'x')
		total += ft_flag_x(flag, arg);
	else if (c == 'X')
		total += ft_flag_xx(flag, arg);
	else if (c == 'p')
		total += ft_flag_p(flag, arg);
	else if (c == 'c' || c == '%')
		total += ft_flag_c(flag, arg, c);
	return (total);
}

int			get_flag(char *s, va_list arg)
{
	t_flag	flag;
	char	c;
	int		total;
	int		moins;

	total = 0;
	moins = 0;
	init(&flag);
	flag.width = ft_get_width(s, arg, &moins);
	flag.zero = ft_check_zero(s);
	flag.prec = ft_get_prec(s, arg);
	if (moins == 1 || ft_check_moins(s) == 1)
		flag.moins = 1;
	c = ft_get_conv(s);
	total += ship_flag(flag, arg, c);
	return (total);
}

int			ft_check_flag(char *s, va_list arg, int *flag)
{
	int		i;
	int		len;
	int		j;

	len = 0;
	i = 0;
	j = 0;
	if (*s == 'c' || *s == 'd' || *s == 'i' || *s == 'u' || *s == 's'
	|| *s == 'x' || *s == 'X' || *s == 'p' || *s == '%')
		i += print_conv(*s, arg);
	else
	{
		*flag = 1;
		while (s[j] != 'c' && s[j] != 'd' && s[j] != 'i' && s[j] != 'u' &&
		s[j] != 's' && s[j] != 'x' && s[j] != 'X' && s[j] != 'p' && s[j] != '%')
		{
			len++;
			j++;
		}
		len++;
		i += get_flag(ft_substr(s, 0, len), arg);
		s += len;
	}
	return (i);
}

char		*flag_conv(char *frm, int flag)
{
	if (flag == 1)
	{
		while (*frm != 'c' && *frm != 'd' && *frm != 'i' && *frm != 'u' &&
		*frm != 's' && *frm != 'x' && *frm != 'X' && *frm != 'p' && *frm != '%')
			frm++;
		frm++;
	}
	else
		frm++;
	return (frm);
}

int			ft_printf(char *frm, ...)
{
	va_list		arg;
	int			total;
	int			flag;

	total = 0;
	flag = 0;
	va_start(arg, frm);
	while (*frm != '\0')
		if (*frm != '%')
			total += ft_putchar(*frm++);
		else
		{
			if (*++frm == '%')
			{
				total += ft_putchar('%');
				frm++;
			}
			else
			{
				total += ft_check_flag(frm, arg, &flag);
				frm = flag_conv(frm, flag);
			}
		}
	va_end(arg);
	return (total);
}
