/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 11:57:01 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/21 17:39:54 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*init_mlx(void)
{
	t_mlx	*new;

	if (!(new = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, X_SIZE, Y_SIZE, "Vquesnel's FDF");
	new->zoom = ZOOM;
	if (!new->mlx || !new->win)
		return (NULL);
	return (new);
}
