/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 11:01:34 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 23:22:27 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_s_5(t_flag flag, char *str)
{
	int		w;
	int		total;

	total = 0;
	w = flag.width - ft_strlen(str);
	if (flag.moins == 1)
	{
		total += ft_putstr_len(str, flag.prec);
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	else
	{
		if (w > 0)
			total += print_spaces(w, ' ');
		total += ft_putstr_len(str, flag.prec);
	}
	return (total);
}

int		ft_flag_s_6(t_flag flag, char *str)
{
	int		w;
	int		total;

	total = 0;
	w = flag.width - flag.prec;
	if (flag.moins == 1)
	{
		total += ft_putstr_len(str, flag.prec);
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	else
	{
		if (w > 0)
			total += print_spaces(w, ' ');
		total += ft_putstr_len(str, flag.prec);
	}
	return (total);
}

int		ft_flag_s_2(t_flag flag, va_list arg)
{
	char	*str;
	int		total;

	total = 0;
	if (flag.prec >= flag.width)
	{
		str = va_arg(arg, char *);
		if (str && *str == '\0')
			total += print_spaces(flag.width, ' ');
		else
		{
			if (!str)
				str = ft_strdup("(null)");
			if ((int)ft_strlen(str) < flag.prec)
				total += ft_flag_s_5(flag, str);
			else
				total += ft_flag_s_6(flag, str);
		}
	}
	return (total);
}

int		help_s_2(va_list arg)
{
	int		total;
	char	*str;

	total = 0;
	str = va_arg(arg, char *);
	if (!str)
		str = ft_strdup("(null)");
	total += ft_putstr(str);
	return (total);
}

int		ft_flag_s(t_flag flag, va_list arg)
{
	char	*str;
	int		total;

	total = 0;
	if (flag.width >= 1 && flag.prec == -1)
	{
		total += ft_flag_s_1(flag, arg);
	}
	else if (flag.width == 0 && flag.prec >= 1)
	{
		str = va_arg(arg, char *);
		if (!str)
			str = ft_strdup("(null)");
		total += ft_putstr_len(str, flag.prec);
	}
	else if (flag.width > 0 && flag.prec >= 0)
	{
		total += ft_flag_s_2(flag, arg);
		total += ft_flag_s_3(flag, arg);
	}
	else if (flag.width == 0 && flag.prec == -1)
		total += help_s_2(arg);
	return (total);
}
