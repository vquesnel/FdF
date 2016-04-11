/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:43:07 by vquesnel          #+#    #+#             */
/*   Updated: 2015/11/27 13:40:17 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int i;
	int j;
	int sign;

	i = 0;
	j = 0;
	sign = 1;
	while (ft_isspace(str[i]) == 1 && str[i])
		i++;
	if ((str[i] == '-' || str[i] == '+') && ft_isdigit(str[i + 1]) == 1)
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1 && str[i] != '\0')
	{
		j = (j * 10) + (str[i] - 48);
		i++;
	}
	return (j * sign);
}
