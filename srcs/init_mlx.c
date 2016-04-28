/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 14:54:46 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/28 19:45:51 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*init_mlx(int fd)
{
	t_mlx	*mlx;

	if (!(mlx = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, X_SIZE, Y_SIZE, \
			"Vquesnel's FDF");
	mlx->fd = fd;
	mlx->proj = 0;
	mlx->menu = 0;
	if (!mlx->mlx || !mlx->win)
		return (NULL);
	return (mlx);
}
