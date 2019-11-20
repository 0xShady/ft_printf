/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_s_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:38:31 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 23:38:42 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int		ft_putstr_len(char *s, int len)
{
	int i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0' && len > 0)
		{
			write(1, &s[i], 1);
			i++;
			len--;
		}
	}
	return (i);
}

int		ft_flag_s_1(t_flag flag, va_list arg)
{
	char	*str;
	int		w;
	int		total;

	total = 0;
	if (flag.moins == 0)
	{
		if (!(str = va_arg(arg, char *)))
			str = ft_strdup("(null)");
		w = flag.width - ft_strlen(str);
		if (w > 0)
			total += print_spaces(w, ' ');
		total += ft_putstr(str);
	}
	else if (flag.moins == 1)
	{
		str = va_arg(arg, char *);
		if (!str)
			str = ft_strdup("(null)");
		w = flag.width - ft_strlen(str);
		total += ft_putstr(str);
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	return (total);
}

int		help_s(t_flag flag, char *str, int w)
{
	int total;

	total = 0;
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

int		ft_flag_s_3(t_flag flag, va_list arg)
{
	char	*str;
	int		w;
	int		total;
	int		l;

	total = 0;
	if (flag.prec < flag.width)
	{
		str = va_arg(arg, char *);
		if (str && *str == '\0')
			total += print_spaces(flag.width, ' ');
		else
		{
			if (!str)
				str = ft_strdup("(null)");
			w = flag.width - (flag.prec <
				(l = ft_strlen(str)) ? flag.prec : l);
			total += help_s(flag, str, w);
		}
	}
	return (total);
}
