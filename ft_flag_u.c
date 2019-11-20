/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 08:59:45 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 21:03:40 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_u_2(t_flag flag, va_list arg)
{
	int			total;
	unsigned	uu;
	int			w;

	total = 0;
	if (flag.moins == 0)
	{
		uu = va_arg(arg, unsigned);
		w = flag.width - len_u(uu);
		if (w > 0)
			total += print_spaces(w, '0');
		total += ft_putstr(ft_utoa(uu));
	}
	else
	{
		uu = va_arg(arg, unsigned);
		w = flag.width - len_u(uu);
		total += ft_putstr(ft_utoa(uu));
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	return (total);
}

int		ft_flag_u_help2(t_flag flag, unsigned uu, int w)
{
	int			total;
	int			p;

	total = 0;
	if (w > 0)
		total += print_spaces(w, ' ');
	p = flag.prec - len_u(uu);
	if (p > 0)
		total += print_spaces(p, '0');
	total += ft_putstr(ft_utoa(uu));
	return (total);
}

int		ft_flag_u_3(t_flag flag, va_list arg)
{
	int			total;
	unsigned	uu;
	int			w;
	int			p;

	total = 0;
	uu = va_arg(arg, unsigned);
	w = flag.width - (flag.prec > len_u(uu) ? flag.prec : len_u(uu));
	if (flag.prec == len_u(uu))
		flag.prec = 0;
	if (flag.moins == 0)
		total += ft_flag_u_help2(flag, uu, w);
	else if (flag.moins == 1)
	{
		p = flag.prec - len_u(uu);
		if (p > 0)
			total += print_spaces(p, '0');
		total += ft_putstr(ft_utoa(uu));
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	return (total);
}

int		ft_flag_u_4(t_flag flag, va_list arg)
{
	int			total;
	unsigned	uu;
	int			w;

	total = 0;
	uu = va_arg(arg, unsigned);
	if (uu == 0)
		w = flag.prec;
	else
		w = flag.prec - len_u(uu);
	if (w > 0)
		total += print_spaces(w, '0');
	if (uu != 0)
		total += ft_putstr(ft_utoa(uu));
	return (total);
}

int		ft_flag_u(t_flag flag, va_list arg)
{
	unsigned	uu;
	int			total;

	total = 0;
	if (flag.width > 0 && flag.prec <= 0)
	{
		if (flag.zero == 0)
			total += ft_flag_u_1(flag, arg);
		else if (flag.zero == 1)
			total += ft_flag_u_2(flag, arg);
	}
	else if (flag.width > 0 && flag.prec > 0 && flag.width > flag.prec)
		total += ft_flag_u_3(flag, arg);
	else if (flag.width <= flag.prec)
		total += ft_flag_u_4(flag, arg);
	else if (flag.prec == -1 && flag.width == 0)
	{
		uu = va_arg(arg, unsigned);
		total += ft_putstr(ft_utoa(uu));
	}
	return (total);
}
