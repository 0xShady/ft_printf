/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_x_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:08:31 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 21:28:12 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_base(unsigned int nbr, int base)
{
	char	*str;
	size_t	x;
	size_t	i;
	size_t	j;

	x = 1;
	i = 0;
	j = 0;
	while (nbr >= x * base)
	{
		x *= base;
		j++;
	}
	str = malloc(sizeof(str) * (i + j + 1));
	while (x)
	{
		str[i] = (nbr / x) + (nbr / x > 9 ? 'a' - 10 : '0');
		nbr = nbr % x;
		x = x / base;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strupcase(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 97 && str[i] <= 122)
			str[i] = str[i] - 32;
		i++;
	}
	return (str);
}

int		ft_flag_x(t_flag flag, va_list arg)
{
	unsigned		i;
	int				total;

	total = 0;
	if (flag.width == 0 && flag.prec > 1 && flag.zero == 1 && flag.moins == 0)
	{
		i = va_arg(arg, int);
		total += ft_putstr(ft_itoa_base(i, 16));
		return (0);
	}
	if (flag.width > 0 && flag.prec == -1)
		total += ft_flag_x_1(flag, arg);
	else if (flag.width > 0 && flag.prec == 0)
		total += ft_flag_x_2(flag, arg);
	else if (flag.width == 0 && flag.prec > 0)
		total += ft_flag_x_3(flag, arg);
	else if (flag.width == 0 && flag.prec == -1)
		total += ft_flag_x_help4(arg);
	else if (flag.width == 0 && flag.prec == 0)
		total += ft_flag_x_help3(arg);
	else if (flag.width > 0 && flag.prec > 0)
		total += ft_flag_x_4(flag, arg);
	return (total);
}
