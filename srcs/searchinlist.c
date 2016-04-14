/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchinlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/14 15:17:31 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/14 15:21:50 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_iso		*searchinlist(t_iso *list, t_coordmax coord)
{
	t_iso *tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->index == list->index + coord.x_max + 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
