/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 22:45:23 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/22 12:59:50 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		int_len(int nb, int base)
{
	int i;

	i = 0;
	if (nb < 0 && base == 10)
	{
		++i;
		nb = -nb;
	}
	if (nb < 0 && base != 10)
		nb = -nb;
	while (nb)
	{
		nb /= base;
		++i;
	}
	return (i);
}

long	max_power(long nb, int base)
{
	long max;

	max = base;
	while (max < nb)
		max *= base;
	if (max > nb)
		max /= base;
	return (max);
}

char	*ft_itoa_base(int value, int base)
{
	long			max;
	static char		hex[16] = "0123456789ABCDEF";
	char			*text;
	static int		i;
	long			nb;

	text = ft_strnewzero(int_len(value, base));
	nb = (long)value;
	if (nb < 0 && base == 10)
	{
		text[i] = '-';
		i++;
		nb = -nb;
	}
	if (nb < 0 && base != 10)
		nb = -nb;
	max = max_power(nb, base);
	while (max > 0)
	{
		text[i] = hex[nb / max];
		nb %= max;
		max /= base;
		i++;
	}
	return (text);
}
