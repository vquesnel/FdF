/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 17:27:23 by vquesnel          #+#    #+#             */
/*   Updated: 2015/12/01 17:27:25 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s)
	{
		str = (char *)malloc(sizeof(char) * (len + 1));
		if (str)
		{
			while (start--)
				s++;
			str = ft_strncpy(str, s, len);
			str[len] = '\0';
		}
		return (str);
	}
	return (NULL);
}
