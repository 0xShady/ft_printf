/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_u_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 20:42:17 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 21:03:58 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_flag_u_help1(t_flag flag, va_list arg)
{
	int			total;
	unsigned	uu;
	int			w;

	total = 0;
	uu = va_arg(arg, unsigned);
	if (uu == 0 && flag.prec == 0)
		w = flag.width;
	else
		w = flag.width - len_u(uu);
	if (w > 0)
		total += print_spaces(w, ' ');
	if (flag.prec != 0 || uu != 0)
		total += ft_putstr(ft_utoa(uu));
	return (total);
}

int		ft_flag_u_1(t_flag flag, va_list arg)
{
	int			total;
	unsigned	uu;
	int			w;

	total = 0;
	if (flag.moins == 0)
		total += ft_flag_u_help1(flag, arg);
	else if (flag.moins == 1)
	{
		uu = va_arg(arg, unsigned);
		if (uu == 0 && flag.prec == 0)
			w = flag.width;
		else
			w = flag.width - len_u(uu);
		if (flag.prec != 0 || uu != 0)
			total += ft_putstr(ft_utoa(uu));
		if (w > 0)
			total += print_spaces(w, ' ');
	}
	return (total);
}

char	*ft_utoa(size_t nb)
{
	char	*str;
	size_t	n;
	size_t	i;

	n = nb;
	i = len_u(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	while (n > 0)
	{
		str[i] = 48 + (n % 10);
		n = n / 10;
		i--;
	}
	return (str);
}

int		len_u(size_t nb)
{
	int		len;

	len = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}
