/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_xx_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:42:43 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 23:38:40 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		len(long nb)
{
	int		len;

	if (nb == 0)
		return (1);
	len = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		len++;
	}
	while (nb > 0)
	{
		nb = nb / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(long nb)
{
	char	*str;
	long	n;
	int		i;

	n = nb;
	i = len(n);
	if (!(str = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	str[i--] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	if (n < 0)
	{
		str[0] = '-';
		n = n * -1;
	}
	while (n > 0)
	{
		str[i--] = 48 + (n % 10);
		n = n / 10;
	}
	return (str);
}

char	*ft_itoa_pointer(unsigned long long nbr)
{
	char				*str;
	unsigned long long	x;
	size_t				i;
	size_t				j;

	x = 1;
	i = 2;
	j = 0;
	while (nbr >= x * 16 || j++)
	{
		if (x > 1152921504606846975)
			break ;
		x *= 16;
	}
	str = malloc(j + 3);
	str[0] = '0';
	str[1] = 'x';
	while (x)
	{
		str[i++] = (nbr / x) + (nbr / x > 9 ? 'a' - 10 : '0');
		nbr = nbr % x;
		x = x / 16;
	}
	str[i] = '\0';
	return (str);
}

int		ft_flag_xx(t_flag flag, va_list arg)
{
	unsigned		i;
	int				total;

	total = 0;
	if (flag.width == 0 && flag.prec > 1 && flag.zero == 1 && flag.moins == 0)
	{
		i = va_arg(arg, int);
		total += ft_putstr(ft_strupcase(ft_itoa_base(i, 16)));
		return (0);
	}
	if (flag.width > 0 && flag.prec == -1)
		total += ft_flag_xx_1(flag, arg);
	else if (flag.width > 0 && flag.prec == 0)
		total += ft_flag_xx_2(flag, arg);
	else if (flag.width == 0 && flag.prec > 0)
		total += ft_flag_xx_3(flag, arg);
	else if (flag.width == 0 && flag.prec == -1)
		total += ft_flag_xx_help4(arg);
	else if (flag.width == 0 && flag.prec == 0)
		total += ft_flag_xx_help3(arg);
	else if (flag.width > 0 && flag.prec > 0)
		total += ft_flag_xx_4(flag, arg);
	return (total);
}
