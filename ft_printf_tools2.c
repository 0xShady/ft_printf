/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_tools2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-fadi <ael-fadi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:57:10 by ael-fadi          #+#    #+#             */
/*   Updated: 2019/11/19 22:09:00 by ael-fadi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *src)
{
	int		i;
	int		j;
	char	*p;

	i = 0;
	j = 0;
	while (src[i] != '\0')
		i++;
	i += 1;
	p = (char *)malloc(i * sizeof(char));
	if (p == 0)
		return (0);
	while (src[j] != '\0')
	{
		p[j] = src[j];
		j++;
	}
	p[j] = '\0';
	return (p);
}
