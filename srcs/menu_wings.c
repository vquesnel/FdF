/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_wings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:55:13 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/28 16:55:14 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	left_wing(t_env *env)
{
	int		x;
	int		y;

	x = 148;
	y = 820;
	while (x++ < 383)
		mlx_pixel_put(env->mlx->mlx, env->mlx->win, x, y, 0xFFFFFF);
	while (y++ < 955)
		mlx_pixel_put(env->mlx->mlx, env->mlx->win, x, y, 0xFFFFFF);
	x = 148;
	y = 820;
	while (y++ < 955)
		mlx_pixel_put(env->mlx->mlx, env->mlx->win, x, y, 0xFFFFFF);
	while (x++ < 383)
		mlx_pixel_put(env->mlx->mlx, env->mlx->win, x, y, 0xFFFFFF);
}

void	right_wing(t_env *env)
{
	int		x;
	int		y;

	x = 642;
	y = 820;
	while (x++ < 890)
		mlx_pixel_put(env->mlx->mlx, env->mlx->win, x, y, 0xFFFFFF);
	while (y++ < 955)
		mlx_pixel_put(env->mlx->mlx, env->mlx->win, x, y, 0xFFFFFF);
	x = 642;
	y = 820;
	while (y++ < 955)
		mlx_pixel_put(env->mlx->mlx, env->mlx->win, x, y, 0xFFFFFF);
	while (x++ < 890)
		mlx_pixel_put(env->mlx->mlx, env->mlx->win, x, y, 0xFFFFFF);
}

void	body(t_env *env)
{
	int		x;
	int		y;

	x = 384;
	y = 766;
	while (x++ <= 640)
		mlx_pixel_put(env->mlx->mlx, env->mlx->win, x, y, 0xFFFFFF);
	while (y++ <= 1005)
		mlx_pixel_put(env->mlx->mlx, env->mlx->win, x, y, 0xFFFFFF);
	x = 384;
	y = 766;
	while (y++ <= 1005)
		mlx_pixel_put(env->mlx->mlx, env->mlx->win, x, y, 0xFFFFFF);
	while (x++ <= 640)
		mlx_pixel_put(env->mlx->mlx, env->mlx->win, x, y, 0xFFFFFF);
}
