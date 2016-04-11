/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:01:42 by vquesnel          #+#    #+#             */
/*   Updated: 2016/03/19 17:36:27 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *tosearch, const char *tofind)
{
	int	i;
	int	j;

	i = -1;
	if (!(tofind[0]))
		return ((char*)tosearch);
	while (tosearch[++i])
	{
		j = 0;
		if (tosearch[i] == tofind[j])
		{
			while (tosearch[i + j] == tofind[j] && tosearch[i + j]
					&& tofind[j])
			{
				j++;
				if (!(tofind[j]))
					return ((char*)tosearch + i);
			}
		}
	}
	return (NULL);
}
