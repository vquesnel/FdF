/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:25:35 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/23 14:27:12 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_funct(int keycode, t_mlx *new)
{
	if (new == NULL)
		return (0);
	if (keycode == CLOSE)
	{
		mlx_clear_window(new->mlx, new->win);
		exit(EXIT_SUCCESS);
	}
	if (keycode == SPACE)
	{
		mlx_string_put(new->mlx, new->win, 5, 5, 0xFFFFFF, "FDF Menu :");
		mlx_string_put(new->mlx, new->win, 5, 20, 0xFFFFFF, "-Echap = esc");
		mlx_string_put(new->mlx, new->win, 5, 35, 0xFFFFFF, "-Zoom = mouse wheel");
		mlx_string_put(new->mlx, new->win, 5, 50, 0xFFFFFF, "-Rotation = arrows");
	}

	return (0);
}

int		mouse_funct(int mousecode, t_mlx *new, t_node *list, t_coordmax coord, t_coord cc)
{
	(void)list;
	(void)cc;
	(void)coord;
	if (new == NULL)
		return (0);
	if (mousecode == U_ZOOM || mousecode == D_ZOOM)
	{
		list = NULL;
		list = insert_node(list, cc, 0, 0);
		new->zoom += (mousecode == U_ZOOM) ? 1 : 0;
		new->zoom -= (mousecode == D_ZOOM) ? 1 : 0;
		mlx_clear_window(new->mlx, new->win);
		fdf(new, list, coord);
	}
	return (0);
}
