/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:23:56 by vquesnel          #+#    #+#             */
/*   Updated: 2016/03/22 13:38:09 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = -1;
	if (s1 && s2)
	{
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (!new)
			return (NULL);
		while (s1[++i])
			new[i] = s1[i];
		j = -1;
		while (s2[++j])
			new[i + j] = s2[j];
		return (new);
	}
	return (NULL);
}
