/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 12:34:14 by vquesnel          #+#    #+#             */
/*   Updated: 2015/11/27 15:43:09 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	d;
	size_t			i;

	i = 0;
	if (!s)
		return (NULL);
	str = (unsigned char *)s;
	d = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == d)
			return (str + i);
		i++;
	}
	return (NULL);
}
