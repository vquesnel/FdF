/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:55:05 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/28 18:29:52 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	signature(void *mlx, void *win)
{
	mlx_string_put(mlx, win, 404, 612, 0xAEECFE, "XXXXXX XXXXX   XXXXXX");
	mlx_string_put(mlx, win, 404, 622, 0xAEECFE, "X      X    X  X");
	mlx_string_put(mlx, win, 404, 632, 0xAEECFE, "X      X     X X");
	mlx_string_put(mlx, win, 404, 642, 0xAEECFE, "XXXXX  X     X XXXXX");
	mlx_string_put(mlx, win, 404, 652, 0xAEECFE, "X      X    X  X");
	mlx_string_put(mlx, win, 404, 662, 0xAEECFE, "X      XXXXX   X");
	mlx_string_put(mlx, win, 404, 682, 0xAEECFE, "X   X XXXX X   X X  X");
	mlx_string_put(mlx, win, 404, 692, 0xAEECFE, "XX XX X    XX  X X  X");
	mlx_string_put(mlx, win, 404, 702, 0xAEECFE, "X X X XXXX X X X X  X");
	mlx_string_put(mlx, win, 404, 712, 0xAEECFE, "X   X X    X  XX X  X");
	mlx_string_put(mlx, win, 404, 722, 0xAEECFE, "X   X XXXX X   X XXXX");
	mlx_string_put(mlx, win, 404, 746, 0xFFFFFF, "       vquesnel");
	mlx_string_put(mlx, win, 404, 762, 0xFFFFFF, "       kwiessle");
	mlx_string_put(mlx, win, 404, 791, 0xAEECFE, "zdteam 42        2016");
	mlx_string_put(mlx, win, 404, 791, 0xFFFFFF, "      @  school");
}

static void	options(void *mlx, void *win)
{
	signature(mlx, win);
	mlx_string_put(mlx, win, 700, 686, 0xFCFEAE, "moove    ");
	mlx_string_put(mlx, win, 700, 686, 0xFFFFFF, "         :  arrow");
	mlx_string_put(mlx, win, 700, 706, 0xFFFFFF, "         :    +");
	mlx_string_put(mlx, win, 700, 706, 0xFCFEAE, "zoom +    ");
	mlx_string_put(mlx, win, 700, 726, 0xFFFFFF, "         :    -");
	mlx_string_put(mlx, win, 700, 726, 0xFCFEAE, "zoom -   ");
	mlx_string_put(mlx, win, 168, 686, 0xFFFFFF, "         :    i");
	mlx_string_put(mlx, win, 168, 686, 0xFCFEAE, "iso      ");
	mlx_string_put(mlx, win, 168, 706, 0xFFFFFF, "         :    p");
	mlx_string_put(mlx, win, 168, 706, 0xFCFEAE, "para     ");
	mlx_string_put(mlx, win, 168, 726, 0xFFFFFF, "         :   esc");
	mlx_string_put(mlx, win, 168, 726, 0xFCFEAE, "exit     ");
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
