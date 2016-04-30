/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:56:45 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/30 19:01:52 by kwiessle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_param		*init_param(int zoom, int xdefault, int ydefault, int high)
{
	t_param	*param;

	if (!(param = (t_param *)malloc(sizeof(t_param))))
		return (NULL);
	param->x_max = 0;
	param->y_max = 0;
	param->zoom = zoom;
	param->xdefault = xdefault;
	param->ydefault = ydefault;
	param->high = high;
	return (param);
}

t_param		*new_param(t_param *param, t_node hook)
{
	t_param		*new;

	new = init_param(hook.x, hook.y, hook.z, hook.color);
	new->x_max = param->x_max;
	new->y_max = param->y_max;
	return (new);
}
