/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:55:05 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/28 17:14:36 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	signature(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 404, 786, 0xAEECFE, "XXXXXX XXXXX   XXXXXX");
	mlx_string_put(mlx, win, 404, 796, 0xAEECFE, "X      X    X  X");
	mlx_string_put(mlx, win, 404, 806, 0xAEECFE, "X      X     X X");
	mlx_string_put(mlx, win, 404, 816, 0xAEECFE, "XXXXX  X     X XXXXX");
	mlx_string_put(mlx, win, 404, 826, 0xAEECFE, "X      X    X  X");
	mlx_string_put(mlx, win, 404, 836, 0xAEECFE, "X      XXXXX   X");
	mlx_string_put(mlx, win, 404, 856, 0xAEECFE, "X   X XXXX X   X X  X");
	mlx_string_put(mlx, win, 404, 866, 0xAEECFE, "XX XX X    XX  X X  X");
	mlx_string_put(mlx, win, 404, 876, 0xAEECFE, "X X X XXXX X X X X  X");
	mlx_string_put(mlx, win, 404, 886, 0xAEECFE, "X   X X    X  XX X  X");
	mlx_string_put(mlx, win, 404, 896, 0xAEECFE, "X   X XXXX X   X XXXX");
	mlx_string_put(mlx, win, 404, 920, 0xFFFFFF, "       vquesnel");
	mlx_string_put(mlx, win, 404, 936, 0xFFFFFF, "       kwiessle");
	mlx_string_put(mlx, win, 404, 965, 0xAEECFE, "zdteam 42        2016");
	mlx_string_put(mlx, win, 404, 965, 0xFFFFFF, "      @  school");
}

static void	options(void *mlx, void *win)
{
	signature(mlx, win);
	mlx_string_put(mlx, win, 700, 860, 0xFCFEAE, "moove    ");
	mlx_string_put(mlx, win, 700, 860, 0xFFFFFF, "         :  arrow");
	mlx_string_put(mlx, win, 700, 880, 0xFFFFFF, "         :    +");
	mlx_string_put(mlx, win, 700, 880, 0xFCFEAE, "zoom +    ");
	mlx_string_put(mlx, win, 700, 900, 0xFFFFFF, "         :    -");
	mlx_string_put(mlx, win, 700, 900, 0xFCFEAE, "zoom -   ");
	mlx_string_put(mlx, win, 168, 860, 0xFFFFFF, "         :    i");
	mlx_string_put(mlx, win, 168, 860, 0xFCFEAE, "iso      ");
	mlx_string_put(mlx, win, 168, 880, 0xFFFFFF, "         :    p");
	mlx_string_put(mlx, win, 168, 880, 0xFCFEAE, "para     ");
	mlx_string_put(mlx, win, 168, 900, 0xFFFFFF, "         :   esc");
	mlx_string_put(mlx, win, 168, 900, 0xFCFEAE, "exit     ");
}

int			menu(t_env *env)
{
	void	*mlx;
	void	*win;

	mlx = env->mlx->mlx;
	win = env->mlx->win;
	options(mlx, win);
	left_wing(env);
	right_wing(env);
	body(env);
	return (0);
}
