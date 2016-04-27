/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchinlist.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 15:34:51 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/27 12:04:02 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_proj		*searchinlist(t_proj *proj, t_param *param)
{
	int		x;
	t_proj	*tmp;

	tmp = proj;
	x = param->x_max + 1;
	while (x)
	{
		tmp = tmp->next;
		x--;
	}
	return (tmp);
}
