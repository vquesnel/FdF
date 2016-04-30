/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:56:45 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/30 14:09:42 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_param		*init_param(t_node *node, int zoom, int xdefault, int ydefault, int high)
{
	t_param	*param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	param->x_max = get_xmax(node);
	param->y_max = get_ymax(node);
	param->zoom = zoom;
	param->xdefault = xdefault;
	param->ydefault = ydefault;
	param->high = high;
	return (param);
}
