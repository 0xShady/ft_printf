/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_d_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:34:53 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 20:57:07 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_d_3(t_flag flag, int i, int w)
{
	int	total;
	int p;

	total = 0;
	if (flag.moins == 0)
		total += ft_flag_d_help1(flag, i, w);
	else if (flag.moins == 1)
	{
		if (i < 0)
		{
			i = -i;
			if (i != -2147483648)
				total += ft_putchar('-');
		}
		p = flag.prec - len(i);
		if (p > 0)
			total += print_spaces(p, '0');
		total += ft_putstr(ft_itoa(i));
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	return (total);
}

int		ft_flag_d_4(t_flag flag, va_list arg)
{
	int i;
	int w;
	int	total;

	total = 0;
	i = va_arg(arg, int);
	if (i < 0)
	{
		i = -i;
		if (i != -2147483648)
			total += ft_putchar('-');
	}
	if (i == 0)
		w = flag.prec;
	else
		w = flag.prec - len(i);
	if (w > 0)
		total += print_spaces(w, '0');
	if (i != 0)
		total += ft_putstr(ft_itoa(i));
	return (total);
}

int		ft_flag_d_5(t_flag flag, va_list arg)
{
	int i;
	int w;
	int	total;

	total = 0;
	i = va_arg(arg, int);
	if (flag.prec == len(i))
		flag.prec = 0;
	if (i < 0 && i != -2147483648)
		w = flag.width - ((flag.prec + 1) >
		len(-i) ? (flag.prec + 1) : len(-i) + 1);
	else
		w = flag.width - (flag.prec > len(i) ? flag.prec : len(i));
	total += ft_flag_d_3(flag, i, w);
	return (total);
}

int		ft_flag_d(t_flag flag, va_list arg)
{
	int i;
	int	total;

	total = 0;
	if (flag.width > 0 && flag.prec <= 0)
	{
		if (flag.zero == 0)
			total += ft_flag_d_1(flag, arg);
		else if (flag.zero == 1)
			total += ft_flag_d_2(flag, arg);
	}
	else if (flag.width > 0 && flag.prec > 0 && flag.width > flag.prec)
		total += ft_flag_d_5(flag, arg);
	else if (flag.width <= flag.prec)
		total += ft_flag_d_4(flag, arg);
	else if (flag.prec == -1 && flag.width == 0)
	{
		i = va_arg(arg, int);
		total += ft_putstr(ft_itoa(i));
	}
	return (total);
}
