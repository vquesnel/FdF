/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:25:35 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/22 14:26:23 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		key_funct(int keycode, t_mlx *new, t_node *list)
{
	printf("key event == %d\n", keycode);
	if (new == NULL)
		return (0);
	if (keycode == CLOSE)
	{
		mlx_clear_window(new->mlx, new->win);
		exit(EXIT_SUCCESS);
	}
		if (keycode == U_ZOOM)
		{
			mlx_clear_window(new->mlx, new->win);
			fdf(new, list);
		}
		return (0);
}
