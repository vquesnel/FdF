/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:57:22 by vquesnel          #+#    #+#             */
/*   Updated: 2015/11/27 12:40:07 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t n)
{
	size_t		i;

	if (!dst && !src)
		return (NULL);
	i = 0;
	ft_bzero(dst, n);
	while (src[i] && i < n)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
