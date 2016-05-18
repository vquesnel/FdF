/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:11:29 by vquesnel          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/05/18 14:02:53 by vquesnel         ###   ########.fr       */
=======
/*   Updated: 2016/05/07 13:15:46 by vquesnel         ###   ########.fr       */
>>>>>>> 2268a5e65d97078c8e15e3e05989a4f4964ac65c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
	if (n == -2147483648)
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
