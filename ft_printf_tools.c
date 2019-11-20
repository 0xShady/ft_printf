/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:55:05 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 22:53:00 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

size_t		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (*str != '\0')
	{
		str++;
		i++;
	}
	return (i);
}

char		*ft_substr(char const *s, unsigned int start, size_t len)
{
	int				k;
	int				i;
	int				j;
	char			*tab;

	if (!s)
		return (NULL);
	if (s[0] == '\0' || start > ft_strlen(s))
	{
		if (!(tab = malloc(1 * sizeof(char))))
			return (0);
		tab[0] = '\0';
		return (tab);
	}
	i = 0;
	j = len + start;
	k = start;
	if (!(tab = (char *)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (s[start] != '\0' && k++ < j)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}

int			spaces(char c)
{
	if (c == '\f' || c == '\t' || c == '\n' || c == '\v' || c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	return (0);
}

int			ft_atoi(const char *str)
{
	unsigned long	res;
	int				sign;
	int				i;

	res = 0;
	sign = 0;
	i = 0;
	while (spaces(str[i]) == 1)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
		res = res * 10 + ((int)str[i++] - '0');
	if (res > 2147483648 && sign == -1)
		return (0);
	if (res > 2147483647 && sign != -1)
		return (-1);
	if (sign == -1)
		return (res * -1);
	return (res);
}
