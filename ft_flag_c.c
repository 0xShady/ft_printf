/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_c.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 08:41:16 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 22:53:06 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_mod(t_flag flag)
{
	int total;

	total = 0;
	if (flag.width > 0)
	{
		if (flag.moins == 1)
		{
			total += ft_putchar('%');
			if (flag.zero == 1)
				total += print_spaces(flag.width - 1, '0');
			if (flag.zero == 0)
				total += print_spaces(flag.width - 1, ' ');
		}
		if (flag.moins == 0)
		{
			if (flag.zero == 1)
				total += print_spaces(flag.width - 1, '0');
			if (flag.zero == 0)
				total += print_spaces(flag.width - 1, ' ');
			total += ft_putchar('%');
		}
	}
	else
		total += ft_putchar('%');
	return (total);
}

int		ft_flag_char(t_flag flag, va_list arg)
{
	int total;
	int w;
	int	a;

	total = 0;
	if (flag.width > 0)
	{
		w = flag.width - 1;
		if (flag.moins == 1)
		{
			a = va_arg(arg, int);
			total += ft_putchar(a);
			if (w > 0)
				total += print_spaces(w, ' ');
		}
		if (flag.moins == 0)
		{
			a = va_arg(arg, int);
			if (w > 0)
				total += print_spaces(w, ' ');
			total += ft_putchar(a);
		}
	}
	return (total);
}

int		ft_flag_c(t_flag flag, va_list arg, char c)
{
	int		total;

	total = 0;
	if (c == 'c')
		total += ft_flag_char(flag, arg);
	else if (c == '%')
		total += ft_flag_mod(flag);
	return (total);
}

int		ft_flag_p(t_flag flag, va_list arg)
{
	int					w;
	int					total;
	unsigned long long	x;

	total = 0;
	if (flag.width >= 1)
	{
		if (flag.moins == 0)
		{
			x = va_arg(arg, unsigned long long);
			w = flag.width - ft_strlen(ft_itoa_pointer(x));
			if (w > 0)
				total += print_spaces(w, ' ');
			total += ft_putstr(ft_itoa_pointer(x));
		}
		else if (flag.moins == 1)
		{
			x = va_arg(arg, unsigned long long);
			total += ft_putstr(ft_itoa_pointer(x));
			w = flag.width - ft_strlen(ft_itoa_pointer(x));
			if (w > 0)
				total += print_spaces(w, ' ');
		}
	}
	return (total);
}

void	init(t_flag *flag)
{
	flag->moins = 0;
	flag->prec = -1;
	flag->zero = 0;
	flag->width = 0;
}
