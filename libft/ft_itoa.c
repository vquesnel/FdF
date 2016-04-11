/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:11:29 by vquesnel          #+#    #+#             */
/*   Updated: 2016/03/19 17:36:19 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <limits.h>

static	int		ft_int_len(int n)
{
	int		q;
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		q = n % 10;
		n = n - q;
		n = n / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	int		q;
	int		len;
	char	*str;

	len = ft_int_len(n);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (n == INT_MIN)
		return (ft_strdup("-2147483648"));
	if (n == 0 || !str)
		return (ft_strdup("0"));
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	str[len] = '\0';
	while (n > 0)
	{
		str[len - 1] = n % 10 + '0';
		q = n % 10;
		n = n - q;
		n = n / 10;
		len--;
	}
	return (str);
}
