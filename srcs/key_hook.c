/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vquesnel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/09 16:25:12 by vquesnel          #+#    #+#             */
/*   Updated: 2016/04/28 22:30:48 by vquesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*static t_proj		*change_color(t_env *env, int keycode)
{
	t_proj *tmp;

	tmp = env->proj;
	if (keycode == COLOR_A)
	{
		while (tmp)
		{
		tmp->color = (tmp->z > -10) ? BLUE : tmp->color;
		tmp->color = (tmp->z <= -10 && tmp->z > -20) ? GREEN : tmp->color;
		tmp->color = (tmp->z <= -20 && tmp->z > -40) ? BROWN : tmp->color;
		tmp->color = (tmp->z <= -40) ? WHITE : tmp->color;
		tmp = tmp->next;
		}
		env->mlx->color = 1;
	}
	if (keycode == COLOR_B)
	{
		env->mlx->color = 0;
		return (env->proj);
	}
	return (env->proj);
}*/
/*static void		color(t_env *env, int keycode)
{
	if (keycode == COLOR_A)
		env->proj = change_color(env, keycode);
	fdf(env);
}
*/
static void		zoom(t_env *env, int keycode, t_node coord)
{
	ft_memdel((void **)&env->param);
	ft_memdel((void **)&env->proj);
	if (keycode == P_ZOOM)
		coord.x += (coord.x >= 100) ? 20 : 2;
	else if (keycode == M_ZOOM && coord.x >= 3)
		coord.x -= (coord.x >= 100) ? 20 : 2;
	env->param = init_param(env->map, coord.x, coord.y, coord.z);
	if (env->mlx->proj == 1)
		env->proj = init_para(env->map, env->param);
	else if (env->mlx->proj == 0)
		env->proj = init_iso(env->map, env->param);
//	if (env->mlx->color == 1)
//		env->proj = change_color(env, keycode);
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
//	if (env->mlx->color == 1)
//		env->proj = change_color(env, keycode);
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
//	if (env->mlx->color == 1)
//		env->proj = change_color(env, keycode);
	fdf(env);
}

static void		origin(t_env *env, int keycode)
{
	ft_memdel((void **)&env->param);
	ft_memdel((void **)&env->proj);
	if (keycode == MIDDLE)
		env->param = init_param(env->map, 2, X_SIZE / 2, Y_SIZE / 2);
	if (env->mlx->proj == 1)
		env->proj = init_para(env->map, env->param);
	else if (env->mlx->proj == 0)
		env->proj = init_iso(env->map, env->param);
//	if (env->mlx->color == 1)
//		env->proj = change_color(env, keycode);
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
	if (keycode == MIDDLE)
		origin(env, keycode);
//	if (keycode == COLOR_A)
//		color(env, keycode);
	return (0);
}
