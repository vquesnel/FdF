/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:25:12 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/28 17:38:52 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		zoom(t_env *env, int keycode, t_node coord)
{
	ft_memdel((void **)&env->param);
	ft_memdel((void **)&env->proj);
	if (keycode == P_ZOOM)
	{
		if (coord.x >= 100)
			coord.x += 20;
		else
			coord.x += 2;
	}
	else if (keycode == M_ZOOM && coord.x >= 3)
	{
		if (coord.x >= 120)
			coord.x -= 20;
		else
			coord.x -= 2;
	}
	env->param = init_param(env->map, coord.x, coord.y, coord.z);
	if (env->mlx->proj == 1)
		env->proj = init_para(env->map, env->param);
	else if (env->mlx->proj == 0)
		env->proj = init_iso(env->map, env->param);
	fdf(env);
}

static void		moove(t_env *env, int keycode, t_node coord)
{
	ft_memdel((void **)&env->param);
	ft_memdel((void **)&env->proj);
	if (keycode == L_MOOVE)
		coord.y -= 100;
	else if (keycode == R_MOOVE)
		coord.y += 100;
	else if (keycode == D_MOOVE)
		coord.z -= 100;
	else if (keycode == U_MOOVE)
		coord.z += 100;
	env->param = init_param(env->map, coord.x, coord.y, coord.z);
	if (env->mlx->proj == 1)
		env->proj = init_para(env->map, env->param);
	else if (env->mlx->proj == 0)
		env->proj = init_iso(env->map, env->param);
	fdf(env);
}

static void		projection(t_env *env, int keycode, t_node coord)
{
	ft_memdel((void **)&env->param);
	ft_memdel((void **)&env->proj);
	if (keycode == ISO)
	{
		env->param = init_param(env->map, coord.x, coord.y, coord.z);
		env->proj = init_iso(env->map, env->param);
		env->mlx->proj = 0;
	}
	else if (keycode == PARA)
	{
		env->param = init_param(env->map, coord.x, coord.y, coord.z);
		env->proj = init_para(env->map, env->param);
		env->mlx->proj = 1;
	}
	fdf(env);
}

int				key_funct(int keycode, t_env *env)
{
	t_node	hook;

	hook.x = env->param->zoom;
	hook.y = env->param->xdefault;
	hook.z = env->param->ydefault;
	hook.color = env->proj->z;
	if (env->mlx == NULL)
		return (0);
	if (keycode == CLOSE)
		exit(EXIT_SUCCESS);
	if (keycode == SPACE)
		menu(env);
	if (keycode == P_ZOOM || keycode == M_ZOOM)
		zoom(env, keycode, hook);
	if (keycode == L_MOOVE || keycode == R_MOOVE || keycode == U_MOOVE || \
			keycode == D_MOOVE)
		moove(env, keycode, hook);
	if (keycode == ISO || keycode == PARA)
		projection(env, keycode, hook);
	return (0);
}
