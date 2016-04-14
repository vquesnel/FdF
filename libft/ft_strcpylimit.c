/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_limit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/13 12:47:05 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/13 14:06:34 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strcpylimit(char *str, char n)
{
	int		i;
	char	*dst;

	i = 0;
	while (str[i] && str[i] != n)
		i++;
	if ((dst = (char *)ft_memalloc(i + 1)) == NULL)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != n)
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
