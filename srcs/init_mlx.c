/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <vquesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 11:57:01 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/25 14:19:48 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx		*init_mlx(char *text)
{
	t_mlx	*new;

	if (!(new = (t_mlx *)malloc(sizeof(t_mlx))))
		return (NULL);
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, X_SIZE, Y_SIZE, "Vquesnel's FDF");
	new->fd = open(text, O_RDONLY);
	new->zoom = 30;
	if (!new->mlx || !new->win)
		return (NULL);
	return (new);
}
