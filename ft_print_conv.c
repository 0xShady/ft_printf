/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_conv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 07:40:33 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 23:11:56 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_d(va_list arg, char c)
{
	int				total;
	long			i;
	unsigned int	y;

	total = 0;
	if (c == 'd' || c == 'i')
	{
		i = va_arg(arg, int);
		if (i < 0)
		{
			i = i * -1;
			total += ft_putchar('-');
		}
		total += ft_putstr(ft_itoa(i));
	}
	else if (c == 'u')
	{
		y = va_arg(arg, unsigned int);
		total += ft_putstr(ft_utoa(y));
	}
	return (total);
}

int		ft_print_x(va_list arg, char c)
{
	int					total;
	long				i;
	unsigned long long	x;

	total = 0;
	if (c == 'X')
	{
		i = va_arg(arg, int);
		total += ft_putstr(ft_strupcase(ft_itoa_base(i, 16)));
	}
	else if (c == 'x')
	{
		i = va_arg(arg, int);
		total += ft_putstr(ft_itoa_base(i, 16));
	}
	else if (c == 'p')
	{
		x = va_arg(arg, unsigned long long);
		total += ft_putstr(ft_itoa_pointer(x));
	}
	return (total);
}

int		ft_print_s(va_list arg, char c)
{
	char	*s;
	int		i;
	int		total;

	total = 0;
	if (c == 'c')
	{
		i = va_arg(arg, int);
		total += ft_putchar(i);
	}
	else if (c == 's')
	{
		s = va_arg(arg, char *);
		if (!s)
			total += ft_putstr("(null)");
		else
			total += ft_putstr(s);
	}
	return (total);
}

int		print_conv(int c, va_list arg)
{
	int					total;

	total = 0;
	if (c == 'd' || c == 'i' || c == 'u')
		total += ft_print_d(arg, c);
	else if (c == 'c' || c == 's')
		total += ft_print_s(arg, c);
	else if (c == 'X' || c == 'x' || c == 'p')
		total += ft_print_x(arg, c);
	return (total);
}

int		print_spaces(int w, char c)
{
	int		total;

	total = 0;
	while (w > 0)
	{
		total += ft_putchar(c);
		w--;
	}
	return (total);
}
