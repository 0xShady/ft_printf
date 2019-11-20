/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_x_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:05:24 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 21:13:46 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_x_5(t_flag flag, va_list arg)
{
	char		*str;
	int			total;
	int			w;
	int			i;

	total = 0;
	i = va_arg(arg, int);
	str = ft_itoa_base(i, 16);
	if (flag.width > flag.prec)
	{
		w = flag.width - flag.prec;
		if (flag.prec < (int)ft_strlen(str))
			w = flag.width - ft_strlen(str);
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	w = flag.prec - ft_strlen(str);
	if (i == 0)
		w = flag.prec;
	if (w > 0)
		total += print_spaces(w, '0');
	if (i != 0)
		total += ft_putstr(str);
	return (total);
}

int		ft_flag_x_6(t_flag flag, va_list arg)
{
	char		*str;
	int			total;
	int			w;
	int			i;

	total = 0;
	i = va_arg(arg, int);
	str = ft_itoa_base(i, 16);
	w = flag.prec - ft_strlen(str);
	if (i == 0)
		w = flag.prec;
	if (w > 0)
		total += print_spaces(w, '0');
	if (i != 0)
		total += ft_putstr(str);
	if (flag.width > flag.prec)
	{
		w = flag.width - flag.prec;
		if (flag.prec < (int)ft_strlen(str))
			w = flag.width - ft_strlen(str);
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	return (total);
}

int		ft_flag_x_4(t_flag flag, va_list arg)
{
	int			total;

	total = 0;
	if (flag.moins == 0)
		total += ft_flag_x_5(flag, arg);
	else
		total += ft_flag_x_6(flag, arg);
	return (total);
}

int		ft_flag_x_help3(va_list arg)
{
	int		total;
	char	*str;
	int		i;

	total = 0;
	i = va_arg(arg, int);
	str = ft_itoa_base(i, 16);
	if (i != 0)
		total += ft_putstr(str);
	return (total);
}

int		ft_flag_x_help4(va_list arg)
{
	int		total;
	char	*str;
	int		i;

	total = 0;
	i = va_arg(arg, int);
	str = ft_itoa_base(i, 16);
	total += ft_putstr(str);
	return (total);
}
