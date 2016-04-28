/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 10:38:18 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/28 13:13:51 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		write_fdf(t_env *env, void *win2)
{
	mlx_string_put(env->mlx->mlx, win2, 170, 52, 0xAEECFE, "-> FDF'S MENU <-");
}

static void		write_menu(t_env *env, void *win2)
{
	write_fdf(env, win2);
	mlx_string_put(env->mlx->mlx, win2, 160, 82, 0xFCFEAE, "moove    ");
	mlx_string_put(env->mlx->mlx, win2, 160, 82, 0xFFFFFF, "         :  arrow");
	mlx_string_put(env->mlx->mlx, win2, 160, 102, 0xFFFFFF, "         :    +");
	mlx_string_put(env->mlx->mlx, win2, 160, 102, 0xFCFEAE, "zoom +    ");
	mlx_string_put(env->mlx->mlx, win2, 160, 122, 0xFFFFFF, "         :    -");
	mlx_string_put(env->mlx->mlx, win2, 160, 122, 0xFCFEAE, "zoom -   ");
	mlx_string_put(env->mlx->mlx, win2, 160, 142, 0xFFFFFF, "         :    p");
	mlx_string_put(env->mlx->mlx, win2, 160, 142, 0xFCFEAE, "para     ");
	mlx_string_put(env->mlx->mlx, win2, 160, 162, 0xFFFFFF, "         :    i");
	mlx_string_put(env->mlx->mlx, win2, 160, 162, 0xFCFEAE, "iso      ");
	mlx_string_put(env->mlx->mlx, win2, 160, 182, 0xFFFFFF, "         :  Escp");
	mlx_string_put(env->mlx->mlx, win2, 160, 182, 0xFCFEAE, "exit     ");
}

int				menu(t_env *env)
{
	int			color;
	int			x;
	int			y;
	void		*win2;

	y = -1;
	color = 100493;
	win2 = mlx_new_window(env->mlx->mlx, 512, 256, "Menu");
	while (y++ < 253)
	{
		x = -1;
		while (x++ < 512)
		{
			mlx_pixel_put(env->mlx->mlx, win2, x, y, color);
			color = color + 32896;
		}
	}
	write_menu(env, win2);
	mlx_loop(env->mlx->mlx);
	return (0);
}
