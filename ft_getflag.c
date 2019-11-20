/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getflag.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 02:25:54 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 23:43:37 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_prec(char *s, va_list arg)
{
	int i;

	i = -1;
	while (*s != 0)
	{
		if (*s++ == '.')
		{
			if (*s <= '9' && *s >= '0')
			{
				i = ft_atoi(s);
				break ;
			}
			else if (*s == '*')
			{
				i = va_arg(arg, int);
				if (i < 0)
					i = -1;
				break ;
			}
			else
				i = 0;
		}
	}
	return (i);
}

int		ft_get_width(char *s, va_list arg, int *moins)
{
	int w;
	int i;

	w = 0;
	while (*s != '\0' && *s != '.')
	{
		if (*s <= '9' && *s >= '1')
		{
			w = ft_atoi(s);
			break ;
		}
		else if (*s == '*')
		{
			i = va_arg(arg, int);
			if (i < 0)
			{
				i = -i;
				*moins = 1;
			}
			w = i;
			break ;
		}
		s++;
	}
	return (w);
}

int		ft_check_moins(char *s)
{
	while (*s != '\0')
	{
		if (*s == '-')
		{
			return (1);
		}
		s++;
	}
	return (0);
}

int		ft_check_zero(char *s)
{
	if (*s == '0')
	{
		return (1);
	}
	return (0);
}

char	ft_get_conv(char *s)
{
	while (*s != '\0')
	{
		if (*s == 'c' || *s == 'd' || *s == 'i' || *s == 'u' || *s == 's'
		|| *s == 'x' || *s == 'X' || *s == 'p' || *s == '%')
		{
			return (*s);
		}
		s++;
	}
	return (0);
}
