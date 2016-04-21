/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfdf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/19 15:18:12 by vquesnel         #+#    #+#             */
/*   Updated: 2016/04/21 13:34:14 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_isfdf(char c)
{
	if (c == ' ')
		return (1);
	else if (c == '-')
		return (1);
	else if (c == '\n')
		return (1);
	else if (c == ',')
		return (1);
	return (0);
}
