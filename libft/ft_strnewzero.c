/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:51:45 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/22 12:58:36 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewzero(size_t size)
{
	char	*str;
	size_t	i;

	i = 0;
	str = (char *)(ft_memalloc(sizeof(char) * size + 1));
	while (i < size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}
