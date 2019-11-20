/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 09:24:15 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 20:57:10 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_d_help3(t_flag flag, va_list arg)
{
	int i;
	int w;
	int	total;

	total = 0;
	i = va_arg(arg, int);
	if (i == 0 && flag.prec == 0)
		w = flag.width;
	else
		w = flag.width - len(i);
	if (w > 0)
		total += print_spaces(w, ' ');
	if (flag.prec != 0 || i != 0)
		total += ft_putstr(ft_itoa(i));
	return (total);
}

int		ft_flag_d_1(t_flag flag, va_list arg)
{
	int i;
	int w;
	int	total;

	total = 0;
	if (flag.moins == 0)
		total += ft_flag_d_help3(flag, arg);
	else if (flag.moins == 1)
	{
		i = va_arg(arg, int);
		if (i == 0 && flag.prec == 0)
			w = flag.width;
		else
			w = flag.width - len(i);
		if (flag.prec != 0 || i != 0)
			total += ft_putstr(ft_itoa(i));
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	return (total);
}

int		ft_flag_d_help2(t_flag flag, va_list arg)
{
	int i;
	int w;
	int	total;

	total = 0;
	i = va_arg(arg, int);
	w = flag.width - len(i);
	if (i < 0)
	{
		i = -i;
		if (i != -2147483648)
			total += ft_putchar('-');
	}
	if (w > 0)
		total += print_spaces(w, '0');
	total += ft_putstr(ft_itoa(i));
	return (total);
}

int		ft_flag_d_2(t_flag flag, va_list arg)
{
	int i;
	int w;
	int	total;

	total = 0;
	if (flag.moins == 0)
		total += ft_flag_d_help2(flag, arg);
	else
	{
		i = va_arg(arg, int);
		w = flag.width - len(i);
		total += ft_putstr(ft_itoa(i));
		if (i < 0)
		{
			i = -i;
			if (i != -2147483648)
				total += ft_putchar('-');
		}
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	return (total);
}

int		ft_flag_d_help1(t_flag flag, int i, int w)
{
	int	total;
	int p;

	total = 0;
	if (w > 0)
		total += print_spaces(w, ' ');
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
	return (total);
}
