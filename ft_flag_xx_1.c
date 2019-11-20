/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_xx_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:36:12 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 23:22:26 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_xx_help(t_flag flag, va_list arg)
{
	int		total;
	int		w;
	char	*str;
	int		i;

	total = 0;
	if (flag.moins == 0)
	{
		i = va_arg(arg, int);
		str = ft_strupcase(ft_itoa_base(i, 16));
		w = flag.width - ft_strlen(str);
		if (w > 0)
			total += print_spaces(w, ' ');
		total += ft_putstr(str);
	}
	else if (flag.moins == 1)
	{
		i = va_arg(arg, int);
		str = ft_strupcase(ft_itoa_base(i, 16));
		w = flag.width - ft_strlen(str);
		total += ft_putstr(str);
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	return (total);
}

int		ft_flag_xx_1(t_flag flag, va_list arg)
{
	char		*str;
	int			total;
	int			w;
	int			i;

	total = 0;
	if (flag.zero == 0)
		total += ft_flag_xx_help(flag, arg);
	else if (flag.zero == 1)
	{
		i = va_arg(arg, int);
		str = ft_strupcase(ft_itoa_base(i, 16));
		w = flag.width - ft_strlen(str);
		if (w > 0)
			total += print_spaces(w, '0');
		total += ft_putstr(str);
	}
	return (total);
}

int		ft_flag_xx_help2(t_flag flag, va_list arg)
{
	int		total;
	int		w;
	char	*str;
	int		i;

	total = 0;
	i = va_arg(arg, int);
	str = ft_strupcase(ft_itoa_base(i, 16));
	if (i == 0)
		w = flag.width;
	else
		w = flag.width - ft_strlen(str);
	if (w > 0)
		total += print_spaces(w, ' ');
	if (i != 0)
		total += ft_putstr(str);
	return (total);
}

int		ft_flag_xx_2(t_flag flag, va_list arg)
{
	char		*str;
	int			total;
	int			w;
	int			i;

	total = 0;
	if (flag.moins == 0)
		total += ft_flag_xx_help2(flag, arg);
	else
	{
		i = va_arg(arg, int);
		str = ft_strupcase(ft_itoa_base(i, 16));
		if (i == 0)
			w = flag.width;
		else
			w = flag.width - ft_strlen(str);
		if (i != 0)
			total += ft_putstr(str);
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	return (total);
}

int		ft_flag_xx_3(t_flag flag, va_list arg)
{
	char		*str;
	int			total;
	int			w;
	int			i;

	total = 0;
	if (flag.moins == 0)
	{
		i = va_arg(arg, int);
		if (i == 0)
		{
			w = flag.prec;
			if (w > 0)
				total += print_spaces(w, '0');
		}
		else
		{
			str = ft_strupcase(ft_itoa_base(i, 16));
			w = flag.prec - ft_strlen(str);
			if (w > 0)
				total += print_spaces(w, '0');
			total += ft_putstr(str);
		}
	}
	return (total);
}
